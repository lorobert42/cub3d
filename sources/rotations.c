/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 13:00:06 by lorobert          #+#    #+#             */
/*   Updated: 2023/06/04 13:05:18 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rright(t_info *info)
{
	float	old_dir;
	float	old_plane;

	old_dir = info->dir.x;
	info->dir.x = info->dir.x * cos(-ROT_SPEED) - \
		info->dir.y * sin(-ROT_SPEED);
	info->dir.y = old_dir * sin(-ROT_SPEED) + info->dir.y * cos(-ROT_SPEED);
	old_plane = info->plane.x;
	info->plane.x = info->plane.x * cos(-ROT_SPEED) - \
		info->plane.y * sin(-ROT_SPEED);
	info->plane.y = old_plane * sin(-ROT_SPEED) + \
		info->plane.y * cos(-ROT_SPEED);
}

void	rleft(t_info *info)
{
	float	old_dir;
	float	old_plane;

	old_dir = info->dir.x;
	info->dir.x = info->dir.x * cos(ROT_SPEED) - info->dir.y * sin(ROT_SPEED);
	info->dir.y = old_dir * sin(ROT_SPEED) + info->dir.y * cos(ROT_SPEED);
	old_plane = info->plane.x;
	info->plane.x = info->plane.x * cos(ROT_SPEED) - \
		info->plane.y * sin(ROT_SPEED);
	info->plane.y = old_plane * sin(ROT_SPEED) + \
		info->plane.y * cos(ROT_SPEED);
}
