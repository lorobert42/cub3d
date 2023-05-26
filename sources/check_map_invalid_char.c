/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_invalid_char.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:46:36 by shiroz            #+#    #+#             */
/*   Updated: 2023/05/26 14:17:50 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map_invalid_char(char	**map, t_info *info)
{
	int	i;
	int	j;
	int	position;

	position = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j])
		{
			if ((map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'\
			|| map[i][j] == 'W') && ++position < 2)
			{
				info->start_direction = map[i][j];
				info->start_column = j;
				info->start_line = i;
				map[i][j] = '0';
			}
			else if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != '\n'\
			&& map[i][j] != ' ')
				fatal_error("Invalide character\n", map[i]);
			j++;
		}
		i++;
	}
}
