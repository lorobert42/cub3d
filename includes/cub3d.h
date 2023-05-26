/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:53:27 by shiroz            #+#    #+#             */
/*   Updated: 2023/05/26 09:14:15 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/errno.h>
# include "libft.h"

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

/*#BSQ map[ligne][coloumn]*/
typedef struct s_info
{
	char	**map;
	int		nb_lines;

//////////////////shiroz///////////////////////


//////////////////lorobert///////////////////////
	char	*n_texture;
	char	*s_texture;
	char	*w_texture;
	char	*e_texture;
	t_color	f_color;
	t_color	c_color;
}	t_info;

typedef enum e_arg_type
{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
	EMPTY,
	NONE
}	t_arg_type;

void	parse_file(t_info *info, char *file_name);
void	fatal_error(char *msg, char *element);
void	check_info_header(t_info *info);
void	clear_split(char **split);
void	clear_info(t_info *info);
void	del(void *content);
void	init_info(t_info *info);

#endif