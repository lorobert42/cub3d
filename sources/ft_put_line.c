/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:15:11 by shiroz            #+#    #+#             */
/*   Updated: 2023/06/04 19:02:28 by shiroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int ft_put_texture_2(t_info *info, t_texture texture, int middle, int *i)
{
	int		line;
	float	column;

	i = &line;
	line = (int)(info->line_to_print.wall_x * texture.width) * 4;
//	printf("%d\n", line);


///////

//	if (texture.height <= info->line_to_print.wall_size)
		column = ((float)(texture.height) / (float)info->line_to_print.wall_size);
		//* middle * texture.info_i.size_line;
		column *= middle;
//		if (column >= texture.height - 1)
//			return (0);

		if (column >= texture.height - 1)
			column = texture.height - 1;

		int tmp = (int)column;
		return (*(unsigned int *)(&info->n_info.info_i.image[(line + (tmp  * texture.width) * 4)]));

			//printf("%f %d\n", column, texture.height);
//	else
//		column = ((float)info->line_to_print.wall_size /  (float)texture.height - 1);

	//	printf("%d\n", line);

/*	int tmp = (int)column;
	tmp /= 4;
	tmp *= 4;
	tmp = tmp * middle * texture.;
*///	printf("%d\n", tmp);
//	return (*(unsigned int *)(&info->n_info.info_i.image[(line + tmp)]));
///////
	//return (*(unsigned int *)(&info->n_info.info_i.image[(line +  ((int)(column * (float)texture.width\
	//	* (float)middle)  * 4))]));


	return (*(unsigned int *)(&info->n_info.info_i.image[(line + ((int)(column  * (float)texture.width) * 4))]));

	return (*(unsigned int *)(&info->n_info.info_i.image[line + texture.width * 4 * middle]));

//	return (line + texture.width * 4 * middle);
}

	//*tmp = *(unsigned int *)(&info->n_info.info_i.image[(middle * info->n_info.width +\
	//(int)(info->line_to_print.wall_x * 10000)) * 4]);

void	ft_put_line(t_info *info)
{
	unsigned int	*tmp;
	int	i;
	int	start;
	int	end;
	int middle;

//	printf("%d\n", info->n_info.height);
	middle = 0;
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
		info->line_to_print.n_col) * 4]);
		if (info->line_to_print.texture == NO)
			*tmp = ft_put_texture_2(info, info->n_info, middle, &i);
			//*tmp = mlx_get_color_value(info->mlx_ptr, (0 << 24 | 255 << 16 | 0 << 8 | 0));
		else if (info->line_to_print.texture == SO)
			*tmp = ft_put_texture_2(info, info->s_info, middle, &i);
			//*tmp = mlx_get_color_value(info->mlx_ptr, (0 << 24 | 0 << 16 | 255 << 8 | 0));
		else if (info->line_to_print.texture == EA)
			*tmp = ft_put_texture_2(info, info->e_info, middle, &i);
//			*tmp = *(unsigned int *)(&info->n_info.info_i.image[(middle * info->n_info.width +\
//			(int)(info->line_to_print.wall_x * 10000)) * 4]);
//			*tmp = mlx_get_color_value(info->mlx_ptr, (0 << 24 | 0 << 16 | 0 << 8 | 255));
		else
			*tmp = ft_put_texture_2(info, info->w_info, middle, &i);
			//*tmp = 0;
		i++;
		middle++;
//		printf("%d %f\n", (int)info->line_to_print.wall_x, info->line_to_print.wall_x );
	}
	while (i < HEIGHT)
	{
		tmp = (unsigned int *)(&info->image.image[(WIDTH * i + \
		info->line_to_print.n_col) * 4 /* info->image.bits_per_pixel*/]);
		*tmp = info->ceiling;
		i++;
	}
}
