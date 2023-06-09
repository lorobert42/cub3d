/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:01:11 by shiroz            #+#    #+#             */
/*   Updated: 2023/06/09 18:41:29 by shiroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_creation(t_info *info, t_texture *texture, t_texture \
		*tmp, t_create *cre)
{
	float	i;
	float	j;
	int		dest;
	int		src;

//	*texture = *tmp;
//	return ;
	(void)info;
	j = 0;
	(void)dest;
	(void)src;
	while (j < tmp->height)
	{
		i = 0;
		while (i < tmp->width)
		{
/*			*(unsigned int *)(&tmp->info_i.image[((int)(i * cre->width) +\
				((int)(j * cre->height)) * tmp->width) * 4]) = \
					*(unsigned int *)(&texture->info_i.image[((int)(i + j) \
						* texture->width) * 4]);
			i++;
*/
			dest = ((((int)(j)) * (tmp->width)) + (int)i) * 4;
			src = (((int)(i * cre->width)) * 4 + (((int)(j * cre->height)) * texture->width) * 4);
			i++;
			if (dest > src > cre->size * 4 ||  texture->width * texture->height * 4 < src)
				continue ;
//			printf("%d %d %f %f \n", src , dest, cre->width, cre->height);
			(*(unsigned int *)(&tmp->info_i.image[dest]) = *(unsigned int *)(&texture->info_i.image[src]));
		}
		j++;
	}
	printf("%d %d\n", texture->height, texture->width);
//	printf("%d %d i : %f j : %f\n", tmp->width, tmp->height, i, j);
//	mlx_destroy_image(info->mlx_ptr, texture->image);
	*texture = *tmp;
}

void	ft_check_square(t_info	*info, t_texture *texture)
{
	t_texture	tmp;
	t_create	cre;

	if (texture->width == texture->height)
		return ;
	if (texture->width < texture->height)
	{
		//Not verify
		cre.height = (float)texture->height / (float)texture->width;
		tmp.image = mlx_new_image(info->mlx_ptr, texture->width, texture->width);
		cre.width = 1;
		tmp.height = texture->width;
		tmp.width = texture->width;
		printf("%d %d %d %p\n", tmp.width, tmp.height, texture->height, tmp.image);
		cre.size = texture->width * texture->width;
	}
	if (texture->width > texture->height)
	{
		//working
		cre.width =(float)texture->width / (float)texture->height;
		tmp.image = mlx_new_image(info->mlx_ptr, texture->height, texture->height);
		cre.size = texture->height * texture->height;
		cre.height = 1;
		tmp.height = texture->height;
		tmp.width = texture->height;
		printf("Coucou > %d %d %d %f\n", tmp.width, tmp.height, texture->width, cre.width);
		printf(" > %f %f %d %f\n", cre.width, cre.height, texture->width, (float)cre.width * texture->width);
	}
	if (!tmp.image)
		exit (1);
	tmp.info_i.image = mlx_get_data_addr(tmp.image, &tmp.info_i.bps,\
		&tmp.info_i.size_line, &tmp.info_i.endian);
	printf(" > %d %d %d %f\n", tmp.width, tmp.info_i.size_line, tmp.info_i.bps, cre.width);
	printf(" > %d %d %d %f\n", texture->width * texture->height, tmp.info_i.size_line, tmp.info_i.bps, cre.width);
	printf(" > %d %d %d %f\n", texture->width * texture->height, tmp.info_i.size_line, tmp.info_i.bps, cre.width);
	ft_creation(info, texture, &tmp, &cre);
}
