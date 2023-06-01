/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:48:42 by lorobert          #+#    #+#             */
/*   Updated: 2023/06/01 09:42:56 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	key_hooks(int keycode, t_info *info)
{
	float	old_dir;
	float	old_plane;

	if (keycode == K_ESC)
		quit(info);
	else if (keycode == K_W)
	{
		if (info->map[info->nb_lines - (int)info->pos.y][(int)(info->pos.x + info->dir.x * MOVE_SPEED)] != '1')
			info->pos.x += info->dir.x * MOVE_SPEED;
		if (info->map[info->nb_lines - (int)(info->pos.y + info->dir.y * MOVE_SPEED)][(int)(info->pos.x)] != '1')
			info->pos.y += info->dir.y * MOVE_SPEED;
	}
	else if (keycode == K_S)
	{
		if (info->map[info->nb_lines - (int)info->pos.y][(int)(info->pos.x - info->dir.x * MOVE_SPEED)] != '1')
			info->pos.x -= info->dir.x * MOVE_SPEED;
		if (info->map[info->nb_lines - (int)(info->pos.y - info->dir.y * MOVE_SPEED)][(int)(info->pos.x)] != '1')
			info->pos.y -= info->dir.y * MOVE_SPEED;
	}
	else if (keycode == K_A)
		info->pos.x -= info->dir.x * MOVE_SPEED;
	else if (keycode == K_D)
		info->pos.x += info->dir.x * MOVE_SPEED;
	else if (keycode == K_RIGHT)
	{
		old_dir = info->dir.x;
		info->dir.x = info->dir.x * cos(-ROT_SPEED) - info->dir.y * sin(-ROT_SPEED);
		info->dir.y = old_dir * sin(-ROT_SPEED) + info->dir.y * cos(-ROT_SPEED);
		old_plane = info->plane.x;
		info->plane.x = info->plane.x * cos(-ROT_SPEED) - info->plane.y * sin(-ROT_SPEED);
		info->plane.y = old_plane * sin(-ROT_SPEED) + info->plane.y * cos(-ROT_SPEED);
	}
	else if (keycode == K_LEFT)
	{
		old_dir = info->dir.x;
		info->dir.x = info->dir.x * cos(ROT_SPEED) - info->dir.y * sin(ROT_SPEED);
		info->dir.y = old_dir * sin(ROT_SPEED) + info->dir.y * cos(ROT_SPEED);
		old_plane = info->plane.x;
		info->plane.x = info->plane.x * cos(ROT_SPEED) - info->plane.y * sin(ROT_SPEED);
		info->plane.y = old_plane * sin(ROT_SPEED) + info->plane.y * cos(ROT_SPEED);
	}
	printf("New pos: %f, %f\n", info->pos.x, info->pos.y);
	printf("New dir: %f, %f\n", info->dir.x, info->dir.y);
	raycast(info);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->image.data, 0, 0);
	return (0);
}

void	hooks(t_info *info)
{
	mlx_key_hook(info->win_ptr, key_hooks, info);
	mlx_hook(info->win_ptr, 17, 0, quit, info);
}
