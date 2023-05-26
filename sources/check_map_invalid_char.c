/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_invalid_char.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:46:36 by shiroz            #+#    #+#             */
/*   Updated: 2023/05/26 10:15:07 by shiroz           ###   ########.fr       */
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
				exit(printf("INVALID CHAR\n"));
			j++;
		}
		i++;
	}
}
