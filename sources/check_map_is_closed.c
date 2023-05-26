/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_is_closed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:03:46 by shiroz            #+#    #+#             */
/*   Updated: 2023/05/26 14:17:23 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map_is_closed(char **map, int column, int line, int nb_line)
{
	if (line < 0 || ft_strlen(map[line]) <= (size_t)column || column < 0 \
	|| nb_line < line)
	{
		printf("\ncol %d line %d\n", column, line);
		fatal_error("Map not closed\n", NULL);
	}
	if (map[line][column] == ' ' || map[line][column] == '\n')
		fatal_error("Invalid character\n", map[line]);
	if (map[line][column] == '0')
	{
		map[line][column] = '.';
		check_map_is_closed(map, column + 1, line, nb_line);
		check_map_is_closed(map, column - 1, line, nb_line);
		check_map_is_closed(map, column, line + 1, nb_line);
		check_map_is_closed(map, column, line - 1, nb_line);
	}
}

	/*
	if (ft_strlen(map[line]) <= (size_t)column || column <= 0 || line <= 0 \
	|| nb_line < line)
	{
		printf("\ncol %d line %d\n", column, line);
	//	return ;
		exit(printf("MAP NOT CLOSED"));
	}
	else //(map[line][column] == '0' || map[line][column] == '2')
	{
		map[line][column] = '2';
		check_map_is_closed(map, column + 1, line, nb_line);
		check_map_is_closed(map, column - 1, line, nb_line);
		check_map_is_closed(map, column, line + 1, nb_line);
		check_map_is_closed(map, column, line - 1, nb_line);
	}*/
