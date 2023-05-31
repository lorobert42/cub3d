/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:26:23 by lorobert          #+#    #+#             */
/*   Updated: 2023/05/31 12:02:15 by shiroz           ###   ########.fr       */
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
	init_player(&info);
	init_mlx(&info);
	check_texture(&info);
	hooks(&info);
	raycast(&info);
//	mlx_put_image_to_window(info.mlx_ptr, info.win_ptr, info.s_info.image, 0, 0);
	ft_put_line(&info);
	printf("%s\n", info.image.image);
	mlx_put_image_to_window(info.mlx_ptr, info.win_ptr, info.image.data, 0, 0);
	mlx_loop(info.mlx_ptr);
	clear_info(&info);
}
