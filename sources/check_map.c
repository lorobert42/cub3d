/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:14:44 by shiroz            #+#    #+#             */
/*   Updated: 2023/05/26 11:55:40 by shiroz           ###   ########.fr       */
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
		fatal_error("Missing begining\n", "map");
	check_map_is_closed(map, info->start_column, info->start_line, info->nb_lines);
//	info->map = map;
	mfree(map);
}
