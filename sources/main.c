/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:26:23 by lorobert          #+#    #+#             */
/*   Updated: 2023/05/26 13:57:13 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_arg(int argc, char **argv)
{
	char	*point;

	if (argc > 2)
		fatal_error("Too many arguments\n", NULL);
	else if (argc < 2)
		fatal_error("Missing map argument\n", NULL);
	point = ft_strrchr(argv[1], '.');
	if (!point || ft_strncmp(point, ".cub", 5))
		fatal_error(".cub file required\n", NULL);
}

int	main(int argc, char **argv)
{
	t_info	info;

	errno = 0;
	check_arg(argc, argv);
	parse_file(&info, argv[1]);
	check_map(&info);
	init_mlx(&info);
	printf("%d, %d, %c\n", info.start_column, info.start_line, info.start_direction);
	hooks(&info);
	mlx_loop(info.mlx_ptr);
	clear_info(&info);
}
