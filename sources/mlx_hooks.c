/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:48:42 by lorobert          #+#    #+#             */
/*   Updated: 2023/07/10 13:10:57 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move(t_info *info)
{
	if (info->mvt & FORWARD)
		forward(info);
	if (info->mvt & BACKWARD)
		backward(info);
	if (info->mvt & LEFT)
		left(info);
	if (info->mvt & RIGHT)
		right(info);
	if (info->mvt & RRIGHT)
		rright(info);
	if (info->mvt & RLEFT)
		rleft(info);
	raycast(info);
	if (mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, \
		info->image.data, 0, 0) < 0)
		fatal_error("Unable to print image\n", NULL);
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
	if (mlx_hook(info->win_ptr, 2, 1L << 0, key_pressed, info) < 0)
		fatal_error("Unable to create hook\n", NULL);
	if (mlx_hook(info->win_ptr, 3, 1L << 1, key_released, info) < 0)
		fatal_error("Unable to create hook\n", NULL);
	if (mlx_hook(info->win_ptr, 17, 0, quit, info) < 0)
		fatal_error("Unable to create hook\n", NULL);
}
