/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 11:40:41 by lorobert          #+#    #+#             */
/*   Updated: 2023/06/10 11:41:23 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	extract_texture(t_info *info, char *line, t_arg_type t)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		fatal_error(NULL, line);
	if (!split[1])
		fatal_error("No texture file provided\n", line);
	if (split[2])
		fatal_error("Too many texture files\n", line);
	if (t == NO)
		info->n_texture = ft_strdup(split[1]);
	else if (t == SO)
		info->s_texture = ft_strdup(split[1]);
	else if (t == WE)
		info->w_texture = ft_strdup(split[1]);
	else if (t == EA)
		info->e_texture = ft_strdup(split[1]);
	clear_split(split);
}
