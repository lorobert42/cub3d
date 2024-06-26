/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:28:12 by lorobert          #+#    #+#             */
/*   Updated: 2023/05/26 12:04:50 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_color(t_color color, char *which)
{
	if (color.red < 0 || color.green < 0 || color.blue < 0)
		fatal_error("Missing color\n", which);
	if (color.red > 255 || color.green > 255 || color.blue > 255)
		fatal_error("Invalid color\n", which);
}

void	check_info_header(t_info *info)
{
	if (!info->n_texture)
		fatal_error("Missing texture information\n", "NO");
	if (!info->s_texture)
		fatal_error("Missing texture information\n", "SO");
	if (!info->w_texture)
		fatal_error("Missing texture information\n", "WE");
	if (!info->e_texture)
		fatal_error("Missing texture information\n", "EA");
	check_color(info->f_color, "Floor");
	check_color(info->c_color, "Ceiling");
}

void	fatal_error(char *msg, char *element)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (errno)
		perror(element);
	else
	{
		if (element)
		{
			ft_putstr_fd(element, STDERR_FILENO);
			ft_putstr_fd(": ", STDERR_FILENO);
		}
		ft_putstr_fd(msg, STDERR_FILENO);
	}
	exit (1);
}
