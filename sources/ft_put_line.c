/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:15:11 by shiroz            #+#    #+#             */
/*   Updated: 2023/05/31 13:48:23 by shiroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_line(t_info *info)
{
	unsigned int *tmp;


	for (int i = 0; i < HEIGHT; i++)
	{
		tmp = (unsigned int *)(&info->image.image[i * sizeof(int) * WIDTH + 500 * 4]);
		*tmp = 0x00FF0000;
	}
	(void)info;
}
