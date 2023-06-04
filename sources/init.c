/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:49:47 by lorobert          #+#    #+#             */
/*   Updated: 2023/06/04 21:10:43 by lorobert         ###   ########.fr       */
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

void	init_player(t_info *info)
{
	info->pos.x = info->start_column + 0.5;
	info->pos.y = info->nb_lines - info->start_line + 0.5;
	if (info->start_direction == 'N')
	{
		info->dir.x = 0;
		info->dir.y = 1;
	}
	else if (info->start_direction == 'S')
	{
		info->dir.x = 0;
		info->dir.y = -1;
	}
	else if (info->start_direction == 'W')
	{
		info->dir.x = -1;
		info->dir.y = 0;
	}
	else if (info->start_direction == 'E')
	{
		info->dir.x = 1;
		info->dir.y = 0;
	}
	info->plane.x = info->dir.y * 0.66;
	info->plane.y = info->dir.x * 0.66;
	info->mvt = 0;
}
