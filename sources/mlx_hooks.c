/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:48:42 by lorobert          #+#    #+#             */
/*   Updated: 2023/05/31 15:38:48 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	key_hooks(int keycode, t_info *info)
{
	printf("%d\n", keycode);
	if (keycode == K_ESC)
		quit(info);
	else if (keycode == K_RIGHT)
		NULL ;
	else if (keycode == K_LEFT)
		NULL ;
	else if (keycode == K_W)
		info->pos.y += info->dir.y * 0.5;
	else if (keycode == K_A)
		info->pos.x -= info->dir.x * 0.5;
	else if (keycode == K_S)
		info->pos.y -= info->dir.y * 0.5;
	else if (keycode == K_D)
		info->pos.x += info->dir.x * 0.5;
	raycast(info);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->image.data, 0, 0);
	return (0);
}

void	hooks(t_info *info)
{
	mlx_key_hook(info->win_ptr, key_hooks, info);
	mlx_hook(info->win_ptr, 17, 0, quit, info);
}
