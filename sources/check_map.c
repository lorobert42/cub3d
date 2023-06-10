/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:14:44 by shiroz            #+#    #+#             */
/*   Updated: 2023/06/10 11:24:01 by shiroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map(t_info *info)
{
	char	**map;

	info->start_direction = '\0';
	if (!info->map || !info->map[0])
		fatal_error("Not found\n", "map");
	map = ft_strdup_tab_of_string(info->map);
	check_map_invalid_char(map, info);
	if (info->start_direction == '\0')
		fatal_error("Missing start position\n", "map");
	check_map_is_closed(map, info->start_column, info->start_line, \
		info->nb_lines);
	mfree(map);
}
