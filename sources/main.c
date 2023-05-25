/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:26:23 by lorobert          #+#    #+#             */
/*   Updated: 2023/05/25 15:02:13 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	int		i;
	t_info	info;
	// TODO: check arguments
	(void)argc;
	parse_file(&info, argv[1]);
	printf("%s\n", info.n_texture);
	printf("%s\n", info.s_texture);
	printf("%s\n", info.w_texture);
	printf("%s\n", info.e_texture);
	printf("%d, %d, %d\n", info.f_color.red, info.f_color.green, info.f_color.blue);
	printf("%d, %d, %d\n", info.c_color.red, info.c_color.green, info.c_color.blue);
	i = 0;
	while (info.map[i])
	{
		printf("%s", info.map[i]);
		i++;
	}
	clear_info(&info);
}
