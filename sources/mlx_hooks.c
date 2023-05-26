/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:48:42 by lorobert          #+#    #+#             */
/*   Updated: 2023/05/26 14:33:59 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	key_hooks(int keycode, t_info *info)
{
	printf("%d\n", keycode);
	if (keycode == K_ESC)
		quit(info);
	return (0);
}

void	hooks(t_info *info)
{
	mlx_key_hook(info->win_ptr, key_hooks, info);
	mlx_hook(info->win_ptr, 17, 0, quit, info);
}
