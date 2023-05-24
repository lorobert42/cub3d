/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:28:12 by lorobert          #+#    #+#             */
/*   Updated: 2023/05/24 14:33:12 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_color(t_color color)
{
	if (color.red < 0 || color.red > 255)
		fatal_error("Invalid color\n");
	if (color.green < 0 || color.green > 255)
		fatal_error("Invalid color\n");
	if (color.blue < 0 || color.blue > 255)
		fatal_error("Invalid color\n");
}

void	check_info_header(t_info *info)
{
	if (!info->n_texture || !info->s_texture || !info->w_texture ||
		!info->e_texture)
		fatal_error("Missing texture information\n");
	check_color(info->f_color);
	check_color(info->c_color);
}

void	fatal_error(char *msg)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (errno)
		perror(NULL);
	else
		ft_putstr_fd(msg, STDERR_FILENO);
	exit (1);
}
