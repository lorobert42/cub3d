/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:29:06 by shiroz            #+#    #+#             */
/*   Updated: 2023/06/06 20:44:10 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_texture(t_info *info)
{
//	info->n_info.height = -50;

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
	{
		//free something
		fatal_error("", "Texture");
	}


	info->n_info.info_i.image = mlx_get_data_addr(info->n_info.image,\
		&info->n_info.info_i.bits_per_pixel, &info->n_info.info_i.size_line, &info->n_info.info_i.endian);

	info->s_info.info_i.image = mlx_get_data_addr(info->s_info.image,\
		&info->s_info.info_i.bits_per_pixel, &info->s_info.info_i.size_line, &info->s_info.info_i.endian);

	info->w_info.info_i.image = mlx_get_data_addr(info->w_info.image,\
		&info->w_info.info_i.bits_per_pixel, &info->w_info.info_i.size_line, &info->w_info.info_i.endian);

	info->e_info.info_i.image = mlx_get_data_addr(info->e_info.image,\
		&info->e_info.info_i.bits_per_pixel, &info->e_info.info_i.size_line, &info->e_info.info_i.endian);
//	printf("Coucou%d %d\n", info->n_info.info_i.size_line, info->n_info.width);

//	printf("|%s|\n", &info->n_info.info_i.image[999900]);
//	info->n_info.image[15] = 0;
//	write(1, info->n_info.image, 14);
//	printf("|%p|%p\n", info->n_info.image, &info->n_info.image[100000]);
//	printf("Coucou%d %d\n", info->n_info.height, info->n_info.width);
	info->floor = mlx_get_color_value(info->mlx_ptr, info->f_color.final);
	info->ceiling = mlx_get_color_value(info->mlx_ptr, info->c_color.final);
	info->image.data = mlx_new_image(info->mlx_ptr, WIDTH, HEIGHT);
	info->image.image = mlx_get_data_addr(info->image.data,\
		&info->image.bits_per_pixel, &info->image.size_line, &info->image.endian);
	info->middle = HEIGHT / 2 - 1;
	/* info->image = mlx_new_image(info->mlx_ptr, WIDTH + (WIDTH % 2) * 2 + 1, \
	HEIGHT + (HEIGHT % 2) * 2 + 1); */
}
