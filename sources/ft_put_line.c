/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:15:11 by shiroz            #+#    #+#             */
/*   Updated: 2023/05/31 15:03:40 by shiroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_line(t_info *info)
{
	unsigned int	*tmp;
	unsigned int	i;

   	i = 0;
	info->line_to_print.wall_size = (HEIGHT - info->line_to_print.wall_size) / 2;
	printf("ICI%d\n", info->line_to_print.wall_size);
	while (i < (unsigned int)info->line_to_print.wall_size)
	{
//		tmp = (unsigned int *)(&info->image.image[(i * WIDTH + 500) * 4]);
	//	printf("%d\n", info->line_to_print.n_col);
		tmp = (unsigned int *)(&info->image.image[(WIDTH * i + \
		info->line_to_print.n_col) * 4 /* info->image.bits_per_pixel*/]);
		*tmp = info->floor;

		tmp = (unsigned int *)(&info->image.image[(WIDTH * i + \
		info->line_to_print.n_col) * 4 /* info->image.bits_per_pixel*/]);
		*tmp = info->floor;
		i++;
	}
}
