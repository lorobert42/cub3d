/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:15:11 by shiroz            #+#    #+#             */
/*   Updated: 2023/06/07 09:17:11 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_line(t_info *info)
{
	unsigned int	*tmp;
	int				i;
	int				start;
	int				end;
	float			step;
	int				tex_x;
	int				tex_y;
	float			tex_pos;
	t_texture		texture;

	start = -info->line_to_print.wall_size / 2 + HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = info->line_to_print.wall_size / 2 + HEIGHT / 2;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	if (info->line_to_print.texture == NO)
		texture = info->n_info;
	else if (info->line_to_print.texture == SO)
		texture = info->s_info;
	else if (info->line_to_print.texture == EA)
		texture = info->e_info;
	else
		texture = info->w_info;
	i = 0;
	while (i < start)
	{
		tmp = (unsigned int *)(&info->image.image[(WIDTH * i + \
		info->line_to_print.n_col) * 4 /* info->image.bits_per_pixel*/]);
		*tmp = info->ceiling;
		i++;
	}
	tex_x = info->line_to_print.wall_x * texture.width;
	step = 1.0 * texture.height / info->line_to_print.wall_size;
	tex_pos = (start - (float)HEIGHT / 2 + (float)info->line_to_print.wall_size / 2) * step;
	while (i < end)
	{
		tex_y = (int)tex_pos & (texture.height - 1);
		tex_pos += step;
		tmp = (unsigned int *)(&info->image.image[(WIDTH * i + info->line_to_print.n_col) * 4]);
		*tmp = texture.info_i.image[(texture.width * tex_y + tex_x) * 4];
		tmp = (unsigned int *)(&info->image.image[(WIDTH * i + info->line_to_print.n_col) * 4 + 1]);
		*tmp = texture.info_i.image[(texture.width * tex_y + tex_x) * 4 + 1];
		tmp = (unsigned int *)(&info->image.image[(WIDTH * i + info->line_to_print.n_col) * 4] + 2);
		*tmp = texture.info_i.image[(texture.width * tex_y + tex_x) * 4 + 2];
		tmp = (unsigned int *)(&info->image.image[(WIDTH * i + info->line_to_print.n_col) * 4] + 3);
		*tmp = texture.info_i.image[(texture.width * tex_y + tex_x) * 4 + 3];
		i++;
	}
	while (i < HEIGHT)
	{
		tmp = (unsigned int *)(&info->image.image[(WIDTH * i + \
		info->line_to_print.n_col) * 4 /* info->image.bits_per_pixel*/]);
		*tmp = info->floor;
		i++;
	}
}
