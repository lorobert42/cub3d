/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:22:58 by lorobert          #+#    #+#             */
/*   Updated: 2023/06/04 20:59:32 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_raycat(t_info *info, int x)
{
	float	camera_x;

	camera_x = 2 * x / (float)WIDTH - 1;
	info->ray_dir.x = info->dir.x + info->plane.x * camera_x;
	info->ray_dir.y = info->dir.y + info->plane.y * camera_x;
	info->map_x = (int)info->pos.x;
	info->map_y = (int)info->pos.y;
	if (info->ray_dir.x == 0)
		info->delta_dist.x = FLT_MAX;
	else
		info->delta_dist.x = fabs(1 / info->ray_dir.x);
	if (info->ray_dir.y == 0)
		info->delta_dist.y = FLT_MAX;
	else
		info->delta_dist.y = fabs(1 / info->ray_dir.y);
}

static void	compute_steps(t_info *info)
{
	if (info->ray_dir.x < 0)
	{
		info->step_x = -1;
		info->side_dist.x = (info->pos.x - info->map_x) * info->delta_dist.x;
	}
	else
	{
		info->step_x = 1;
		info->side_dist.x = (info->map_x + 1.0 - info->pos.x) * \
		info->delta_dist.x;
	}
	if (info->ray_dir.y < 0)
	{
		info->step_y = -1;
		info->side_dist.y = (info->pos.y - info->map_y) * info->delta_dist.y;
	}
	else
	{
		info->step_y = 1;
		info->side_dist.y = (info->map_y + 1.0 - info->pos.y) * \
		info->delta_dist.y;
	}
}

static int	compute_hit(t_info *info)
{
	int		hit;
	int		side;

	hit = 0;
	while (hit == 0)
	{
		if (info->side_dist.x < info->side_dist.y)
		{
			info->side_dist.x += info->delta_dist.x;
			info->map_x += info->step_x;
			side = 0;
		}
		else
		{
			info->side_dist.y += info->delta_dist.y;
			info->map_y += info->step_y;
			side = 1;
		}
		if (info->map[info->nb_lines - info->map_y][info->map_x] == '1')
			hit = 1;
	}
	return (side);
}

static void	select_texture(t_info *info, int side)
{
	if (info->ray_dir.x >= 0)
	{
		if (!side)
			info->line_to_print.texture = WE;
		else if (info->ray_dir.y >= 0)
			info->line_to_print.texture = SO;
		else
			info->line_to_print.texture = NO;
	}
	else
	{
		if (!side)
			info->line_to_print.texture = EA;
		else if (info->ray_dir.y >= 0)
			info->line_to_print.texture = SO;
		else
			info->line_to_print.texture = NO;
	}
}

static void	compute_wall(t_info *info, int side)
{
	float	perp_wall_dist;
	int		line_height;
	float	wall_x;

	if (side == 0)
		perp_wall_dist = (info->side_dist.x - info->delta_dist.x);
	else
		perp_wall_dist = (info->side_dist.y - info->delta_dist.y);
	line_height = (int)(HEIGHT / perp_wall_dist);
	if (side == 0)
		wall_x = info->pos.y + perp_wall_dist * info->ray_dir.y;
	else
		wall_x = info->pos.x + perp_wall_dist * info->ray_dir.x;
	wall_x -= floor(wall_x);
	info->line_to_print.wall_size = line_height;
	info->line_to_print.wall_x = wall_x;
}

void	raycast(t_info *info)
{
	float	x;
	int		side;

	x = 0;
	while (x < WIDTH)
	{
		init_raycat(info, x);
		compute_steps(info);
		side = compute_hit(info);
		compute_wall(info, side);
		select_texture(info, side);
		info->line_to_print.n_col = x;
		ft_put_line(info);
		x++;
	}
}
