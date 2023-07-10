/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_is_closed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:03:46 by shiroz            #+#    #+#             */
/*   Updated: 2023/07/10 16:28:02 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map_is_closed(char **map, int column, int line, int nb_line)
{
	if (line < 0 || nb_line <= line || ft_strlen(map[line]) <= (size_t)column \
		|| column < 0)
	{
		fatal_error("Map not closed\n", NULL);
	}
	if (map[line][column] == ' ' || map[line][column] == '\n')
		fatal_error("Invalid character\n", NULL);
	if (map[line][column] == '0')
	{
		map[line][column] = '.';
		check_map_is_closed(map, column + 1, line, nb_line);
		check_map_is_closed(map, column - 1, line, nb_line);
		check_map_is_closed(map, column, line + 1, nb_line);
		check_map_is_closed(map, column, line - 1, nb_line);
	}
}
