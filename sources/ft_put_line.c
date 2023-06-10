/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:15:11 by shiroz            #+#    #+#             */
/*   Updated: 2023/06/10 14:35:19 by shiroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_line_start(t_info *info, t_put_line *t)
{
	t->start = -info->line_to_print.wall_size / 2 + HEIGHT / 2;
	if (t->start < 0)
		t->start = 0;
	t->end = info->line_to_print.wall_size / 2 + HEIGHT / 2;
	if (t->end >= HEIGHT)
		t->end = HEIGHT - 1;
	if (info->line_to_print.texture == NO)
		t->texture = info->n_info;
	else if (info->line_to_print.texture == SO)
		t->texture = info->s_info;
	else if (info->line_to_print.texture == EA)
		t->texture = info->e_info;
	else
		t->texture = info->w_info;
}

void	ft_put_texture(t_info *info, t_put_line *t, int *tmp_i, int i)
{
	while (i < t->end)
	{
		t->tex_y = (int)t->tex_pos & (t->texture.height - 1);
		t->tex_pos += t->step;
		t->tmp = (unsigned int *)(&info->image.image[(WIDTH * i \
			+ info->line_to_print.n_col) * 4]);
		*t->tmp = t->texture.info_i.image[(t->texture.width * \
			t->tex_y + t->tex_x) * 4];
		t->tmp = (unsigned int *)(&info->image.image[(WIDTH * \
			i + info->line_to_print.n_col) * 4 + 1]);
		*t->tmp = t->texture.info_i.image[(t->texture.width \
			* t->tex_y + t->tex_x) * 4 + 1];
		t->tmp = (unsigned int *)(&info->image.image[(WIDTH * \
			i + info->line_to_print.n_col) * 4] + 2);
		*t->tmp = t->texture.info_i.image[(t->texture.width * \
			t->tex_y + t->tex_x) * 4 + 2];
		t->tmp = (unsigned int *)(&info->image.image[(WIDTH * \
			i + info->line_to_print.n_col) * 4] + 3);
		*t->tmp = t->texture.info_i.image[(t->texture.width * \
			t->tex_y + t->tex_x) * 4 + 3];
		i++;
	}
	*tmp_i = i;
}

void	ft_put_line(t_info *info)
{
	int				i;
	t_put_line		t;

	ft_put_line_start(info, &t);
	i = 0;
	while (i < t.start)
	{
		t.tmp = (unsigned int *)(&info->image.image[(WIDTH * i + \
		info->line_to_print.n_col) * 4]);
		*t.tmp = info->ceiling;
		i++;
	}
	t.tex_x = info->line_to_print.wall_x * t.texture.width;
	t.step = 1.0 * t.texture.height / info->line_to_print.wall_size;
	t.tex_pos = (t.start - (float)HEIGHT / 2 + \
		(float)info->line_to_print.wall_size / 2) * t.step;
	ft_put_texture(info, &t, &i, i);
	while (i < HEIGHT)
	{
		t.tmp = (unsigned int *)(&info->image.image[(WIDTH * i + \
		info->line_to_print.n_col) * 4]);
		*t.tmp = info->floor;
		i++;
	}
}
