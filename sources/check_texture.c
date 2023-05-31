/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:29:06 by shiroz            #+#    #+#             */
/*   Updated: 2023/05/31 09:57:49 by shiroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	{
		//free something
		fatal_error("", "Texture");
	}
}