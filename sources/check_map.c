/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:14:44 by shiroz            #+#    #+#             */
/*   Updated: 2023/05/26 10:51:21 by shiroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map(t_info *info)
{
	char	**map;

	map = ft_strdup_tab_of_string(info->map);
	check_map_invalid_char(map, info);
	check_map_is_closed(map, info->start_column, info->start_line, info->nb_lines);
	info->map = map;
}
