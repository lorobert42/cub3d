/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:48:42 by lorobert          #+#    #+#             */
/*   Updated: 2023/05/29 13:37:39 by shiroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	key_hooks(int keycode, t_info *info)
{
	printf("%d\n", keycode);


	if (keycode == K_ESC)
		quit(info);
/*	else if (keycode == K_RIGHT)
		//
	else if (keycode == K_LEFT)
		//
	else if (keycode == K_W)
		//
	else if (keycode == K_A)
		//
	else if (keycode == K_S)
		//
	else if (keycode == K_D)
		//
*/	return (0);
}

void	hooks(t_info *info)
{
	mlx_key_hook(info->win_ptr, key_hooks, info);
	mlx_hook(info->win_ptr, 17, 0, quit, info);
}
