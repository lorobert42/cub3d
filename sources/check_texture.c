/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:29:06 by shiroz            #+#    #+#             */
/*   Updated: 2023/07/10 13:12:13 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_texture_2(t_info *info)
{
	info->e_info.info_i.image = mlx_get_data_addr(info->e_info.image, \
		&info->e_info.info_i.bps, &info->e_info.info_i.size_line, \
		&info->e_info.info_i.endian);
	if (!info->e_info.info_i.image || !info->n_info.info_i.image || \
		!info->s_info.info_i.image || !info->w_info.info_i.image)
		exit(1);
	info->floor = mlx_get_color_value(info->mlx_ptr, info->f_color.final);
	info->ceiling = mlx_get_color_value(info->mlx_ptr, info->c_color.final);
	info->image.data = mlx_new_image(info->mlx_ptr, WIDTH, HEIGHT);
	info->image.image = mlx_get_data_addr(info->image.data, \
		&info->image.bps, &info->image.size_line, &info->image.endian);
	info->middle = HEIGHT / 2 - 1;
	if (!info->image.data || !info->image.image)
		exit (1);
}

void	check_texture(t_info *info)
{
	info->n_info.image = mlx_xpm_file_to_image(info->mlx_ptr, info->n_texture, \
		&info->n_info.width, &info->n_info.height);
	info->s_info.image = mlx_xpm_file_to_image(info->mlx_ptr, info->s_texture, \
		&info->s_info.width, &info->s_info.height);
	info->w_info.image = mlx_xpm_file_to_image(info->mlx_ptr, info->w_texture, \
		&info->w_info.width, &info->w_info.height);
	info->e_info.image = mlx_xpm_file_to_image(info->mlx_ptr, info->e_texture, \
		&info->e_info.width, &info->e_info.height);
	if (!info->e_info.image || !info->w_info.image || !info->s_info.image || \
	!info->n_info.image)
		fatal_error("Invalid texture\n", NULL);
	info->n_info.info_i.image = mlx_get_data_addr \
		(info->n_info.image, &info->n_info.info_i.bps, &info->n_info.info_i \
		.size_line, &info->n_info.info_i.endian);
	info->s_info.info_i.image = mlx_get_data_addr(info->s_info.image, \
		&info->s_info.info_i.bps, &info->s_info.info_i.size_line, \
		&info->s_info.info_i.endian);
	info->w_info.info_i.image = mlx_get_data_addr(info->w_info.image, \
		&info->w_info.info_i.bps, &info->w_info.info_i.size_line, \
		&info->w_info.info_i.endian);
	info->e_info.info_i.image = mlx_get_data_addr(info->e_info.image, \
		&info->e_info.info_i.bps, &info->e_info.info_i.size_line, \
		&info->e_info.info_i.endian);
	check_texture_2(info);
}
