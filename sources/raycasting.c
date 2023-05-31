/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:22:58 by lorobert          #+#    #+#             */
/*   Updated: 2023/05/31 14:42:53 by shiroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast(t_info *info)
{
	float	x;
	float	camera_x;
	t_point	ray_dir;
	int		map_x;
	int		map_y;
	t_point	side_dist;
	t_point	delta_dist;
	float	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	float	wall_x;

	x = 0;
	while (x < WIDTH)
	{
		camera_x = 2 * x / (float)WIDTH - 1;
		//printf("camera_x: %f\n", camera_x);
		ray_dir.x = info->dir.x + info->plane.x * camera_x;
		ray_dir.y = info->dir.y + info->plane.y * camera_x;
		//printf("ray_dir: %f, %f\n", ray_dir.x, ray_dir.y);
		map_x = (int)info->pos.x;
		map_y = (int)info->pos.y;
		if (ray_dir.x == 0)
			delta_dist.x = FLT_MAX;
		else
			delta_dist.x = fabs(1 / ray_dir.x);
		if (ray_dir.y == 0)
			delta_dist.y = FLT_MAX;
		else
			delta_dist.y = fabs(1 / ray_dir.y);
		if (ray_dir.x < 0)
		{
			step_x = -1;
			side_dist.x = (info->pos.x - map_x) * delta_dist.x;
		}
		else
		{
			step_x = 1;
			side_dist.x = (map_x + 1.0 - info->pos.x) * delta_dist.x;
		}
		if (ray_dir.y < 0)
		{
			step_y = -1;
			side_dist.y = (info->pos.y - map_y) * delta_dist.y;
		}
		else
		{
			step_y = 1;
			side_dist.y = (map_y + 1.0 - info->pos.y) * delta_dist.y;
		}
		hit = 0;
		while (hit == 0)
		{
			if (side_dist.x < side_dist.y)
			{
				side_dist.x += delta_dist.x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist.y += delta_dist.y;
				map_y += step_y;
				side = 1;
			}
			if (info->map[info->nb_lines - map_y][map_x] == '1')
				hit = 1;
		}
		//printf("Wall hit: %d, %d, distance: %f, %f\n", info->nb_lines - map_y, map_x, side_dist.x, side_dist.y);
		if (side == 0)
			perp_wall_dist = (side_dist.x - delta_dist.x);
		else
			perp_wall_dist = (side_dist.y - delta_dist.y);
		line_height = (int)(HEIGHT / perp_wall_dist);
		if (side == 0)
			wall_x = info->pos.y + perp_wall_dist * ray_dir.y;
		else
			wall_x = info->pos.x + perp_wall_dist * ray_dir.x;
		wall_x -= floor(wall_x);
		info->line_to_print.n_col = x;
		info->line_to_print.wall_size = line_height;
		info->line_to_print.wall_x = wall_x;
		ft_put_line(info);
		//printf("x: %ld, line_height: %d, wall_x: %f\n", lrintf(x), line_height, wall_x);
		x++;
	}
}
