/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 11:38:37 by lorobert          #+#    #+#             */
/*   Updated: 2023/06/10 11:41:20 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_color_component(char **color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (color[i][j])
		{
			if (!ft_isdigit(color[i][j]))
				fatal_error("Color must contain numbers only\n", color[i]);
			j++;
		}
		i++;
	}
}

static void	get_color(char *c_str, t_color *color)
{
	char	**split;

	split = ft_split(c_str, ',');
	if (!split)
		fatal_error(NULL, c_str);
	if (!split[0] || !split[1] || !split[2] || split[3])
		fatal_error("Wrong color format, use R,G,B\n", c_str);
	check_color_component(split);
	color->red = ft_atoi(split[0]);
	color->green = ft_atoi(split[1]);
	color->blue = ft_atoi(split[2]);
	color->final = (0 << 24 | color->red << 16 | color->green << 8 | \
		color->blue);
	clear_split(split);
}

void	extract_color(t_info *info, char *line, t_arg_type t)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		fatal_error(NULL, line);
	if (!split[1])
		fatal_error("No color provided\n", line);
	if (t == F)
		get_color(split[1], &info->f_color);
	else if (t == C)
		get_color(split[1], &info->c_color);
	clear_split(split);
}
