/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:49:47 by lorobert          #+#    #+#             */
/*   Updated: 2023/05/26 13:45:02 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_color(t_color *color)
{
	color->red = -1;
	color->green = -1;
	color->blue = -1;
}

void	init_info(t_info *info)
{
	info->map = NULL;
	info->nb_lines = 0;
	info->n_texture = NULL;
	info->s_texture = NULL;
	info->w_texture = NULL;
	info->e_texture = NULL;
	init_color(&info->f_color);
	init_color(&info->c_color);
}

void	init_mlx(t_info *info)
{
	info->mlx_ptr = mlx_init();
	info->win_ptr = mlx_new_window(info->mlx_ptr, WIDTH, HEIGHT, "cub3D");
}
