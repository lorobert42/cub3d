/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:52:46 by lorobert          #+#    #+#             */
/*   Updated: 2023/05/26 13:46:33 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	del(void *content)
{
	(void)content;
	return ;
}

void	clear_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
}

void	clear_mlx(t_info *info)
{
	mlx_destroy_window(info->mlx_ptr, info->win_ptr);
}

void	clear_info(t_info *info)
{
	free(info->n_texture);
	free(info->s_texture);
	free(info->e_texture);
	free(info->w_texture);
	clear_split(info->map);
	clear_mlx(info);
}
