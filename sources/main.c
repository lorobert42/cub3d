/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:26:23 by lorobert          #+#    #+#             */
/*   Updated: 2023/05/26 12:08:05 by lorobert         ###   ########.fr       */
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
	int		i;
	t_info	info;

	errno = 0;
	check_arg(argc, argv);
	parse_file(&info, argv[1]);
	printf("%s\n", info.n_texture);
	printf("%s\n", info.s_texture);
	printf("%s\n", info.w_texture);
	printf("%s\n", info.e_texture);
	printf("%d, %d, %d\n", info.f_color.red, info.f_color.green, info.f_color.blue);
	printf("%d, %d, %d\n", info.c_color.red, info.c_color.green, info.c_color.blue);
	i = 0;

	printf("\n\n\n\n---------------------------------\n");
	while (info.map[i])
	{
		printf("%02d |%s",i, info.map[i]);
		i++;
	}
	printf("\n");
	i = 0;
	check_map(&info);
	printf("\n\n\n\n---------------------------------\n");
	while (info.map[i])
	{
		printf("%02d |%s",i, info.map[i]);
		i++;
	}
	clear_info(&info);
}
