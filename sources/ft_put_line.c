/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:15:11 by shiroz            #+#    #+#             */
/*   Updated: 2023/06/01 20:27:48 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_line(t_info *info)
{
	unsigned int	*tmp;
	int	i;
	int	start;
	int	end;

	start = -info->line_to_print.wall_size / 2 + HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = info->line_to_print.wall_size / 2 + HEIGHT / 2;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	i = 0;
	while (i < start)
	{
		tmp = (unsigned int *)(&info->image.image[(WIDTH * i + \
		info->line_to_print.n_col) * 4 /* info->image.bits_per_pixel*/]);
		*tmp = info->floor;
		i++;
	}
	while (i < end)
	{
		tmp = (unsigned int *)(&info->image.image[(WIDTH * i + \
		info->line_to_print.n_col) * 4 /* info->image.bits_per_pixel*/]);
		if (info->line_to_print.texture == NO)
			*tmp = mlx_get_color_value(info->mlx_ptr, (0 << 24 | 255 << 16 | 0 << 8 | 0));
		else if (info->line_to_print.texture == SO)
			*tmp = mlx_get_color_value(info->mlx_ptr, (0 << 24 | 0 << 16 | 255 << 8 | 0));
		else if (info->line_to_print.texture == EA)
			*tmp = mlx_get_color_value(info->mlx_ptr, (0 << 24 | 0 << 16 | 0 << 8 | 255));
		else
			*tmp = 0;
		i++;
	}
	while (i < HEIGHT)
	{
		tmp = (unsigned int *)(&info->image.image[(WIDTH * i + \
		info->line_to_print.n_col) * 4 /* info->image.bits_per_pixel*/]);
		*tmp = info->ceiling;
		i++;
	}
}
