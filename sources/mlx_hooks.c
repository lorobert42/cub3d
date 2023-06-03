/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:48:42 by lorobert          #+#    #+#             */
/*   Updated: 2023/06/03 10:24:40 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move(t_info *info)
{
	float	old_dir;
	float	old_plane;

	if (info->mvt & FORWARD)
	{
		if (info->map[info->nb_lines - (int)info->pos.y][(int)(info->pos.x + info->dir.x * MOVE_SPEED)] != '1')
			info->pos.x += info->dir.x * MOVE_SPEED;
		if (info->map[info->nb_lines - (int)(info->pos.y + info->dir.y * MOVE_SPEED)][(int)(info->pos.x)] != '1')
			info->pos.y += info->dir.y * MOVE_SPEED;
	}
	if (info->mvt & BACKWARD)
	{
		if (info->map[info->nb_lines - (int)info->pos.y][(int)(info->pos.x - info->dir.x * MOVE_SPEED)] != '1')
			info->pos.x -= info->dir.x * MOVE_SPEED;
		if (info->map[info->nb_lines - (int)(info->pos.y - info->dir.y * MOVE_SPEED)][(int)(info->pos.x)] != '1')
			info->pos.y -= info->dir.y * MOVE_SPEED;
	}
	if (info->mvt & LEFT)
	{
		if (info->map[info->nb_lines - (int)info->pos.y][(int)(info->pos.x - info->plane.x * MOVE_SPEED)] != '1')
			info->pos.x -= info->plane.x * MOVE_SPEED;
		if (info->map[info->nb_lines - (int)(info->pos.y - info->plane.y * MOVE_SPEED)][(int)(info->pos.x)] != '1')
			info->pos.y -= info->plane.y * MOVE_SPEED;
	}
	if (info->mvt & RIGHT)
	{
		if (info->map[info->nb_lines - (int)info->pos.y][(int)(info->pos.x + info->plane.x * MOVE_SPEED)] != '1')
			info->pos.x += info->plane.x * MOVE_SPEED;
		if (info->map[info->nb_lines - (int)(info->pos.y + info->plane.y * MOVE_SPEED)][(int)(info->pos.x)] != '1')
			info->pos.y += info->plane.y * MOVE_SPEED;
	}
	if (info->mvt & RRIGHT)
	{
		old_dir = info->dir.x;
		info->dir.x = info->dir.x * cos(-ROT_SPEED) - info->dir.y * sin(-ROT_SPEED);
		info->dir.y = old_dir * sin(-ROT_SPEED) + info->dir.y * cos(-ROT_SPEED);
		old_plane = info->plane.x;
		info->plane.x = info->plane.x * cos(-ROT_SPEED) - info->plane.y * sin(-ROT_SPEED);
		info->plane.y = old_plane * sin(-ROT_SPEED) + info->plane.y * cos(-ROT_SPEED);
	}
	if (info->mvt & RLEFT)
	{
		old_dir = info->dir.x;
		info->dir.x = info->dir.x * cos(ROT_SPEED) - info->dir.y * sin(ROT_SPEED);
		info->dir.y = old_dir * sin(ROT_SPEED) + info->dir.y * cos(ROT_SPEED);
		old_plane = info->plane.x;
		info->plane.x = info->plane.x * cos(ROT_SPEED) - info->plane.y * sin(ROT_SPEED);
		info->plane.y = old_plane * sin(ROT_SPEED) + info->plane.y * cos(ROT_SPEED);
	}
	raycast(info);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->image.data, 0, 0);
	return (0);
}

static int	key_pressed(int keycode, t_info *info)
{
	if (keycode == K_ESC)
		quit(info);
	if (keycode == K_W)
		info->mvt |= FORWARD;
	if (keycode == K_S)
		info->mvt |= BACKWARD;
	if (keycode == K_A)
		info->mvt |= LEFT;
	if (keycode == K_D)
		info->mvt |= RIGHT;
	if (keycode == K_RIGHT)
		info->mvt |= RRIGHT;
	if (keycode == K_LEFT)
		info->mvt |= RLEFT;
	return (0);
}

static int	key_released(int keycode, t_info *info)
{
	if (keycode == K_W)
		info->mvt &= ~FORWARD;
	if (keycode == K_S)
		info->mvt &= ~BACKWARD;
	if (keycode == K_A)
		info->mvt &= ~LEFT;
	if (keycode == K_D)
		info->mvt &= ~RIGHT;
	if (keycode == K_RIGHT)
		info->mvt &= ~RRIGHT;
	if (keycode == K_LEFT)
		info->mvt &= ~RLEFT;
	return (0);
}

void	hooks(t_info *info)
{
	mlx_hook(info->win_ptr, 2, 1L << 0, key_pressed, info);
	mlx_hook(info->win_ptr, 3, 1L << 1, key_released, info);
	mlx_hook(info->win_ptr, 17, 0, quit, info);
}
