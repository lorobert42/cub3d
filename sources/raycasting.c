/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:22:58 by lorobert          #+#    #+#             */
/*   Updated: 2023/05/31 09:42:14 by lorobert         ###   ########.fr       */
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
	int		draw_start;
	int		draw_end;

	x = 0;
	while (x < WIDTH)
	{
		camera_x = 2 * x / (float)WIDTH - 1;
		ray_dir.x = info->dir.x + info->plane.x * camera_x;
		ray_dir.y = info->dir.y + info->plane.y * camera_x;
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
			if (info->map[map_y][map_x] == '1')
				hit = 1;
		}
		if (side == 0)
			perp_wall_dist = (side_dist.x - delta_dist.x);
		else
			perp_wall_dist = (side_dist.y - delta_dist.y);
		line_height = (int)(HEIGHT / perp_wall_dist);
		draw_start = -line_height / 2 + HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + HEIGHT / 2;
		if (draw_end < 0)
			draw_end = 0;
		printf("x: %ld, draw_start: %d, draw_end: %d\n", lrintf(x), draw_start, draw_end);
		x++;
	}
}
