/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:23:58 by lorobert          #+#    #+#             */
/*   Updated: 2023/06/04 12:56:19 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	forward(t_info *info)
{
	if (info->map[info->nb_lines - (int)info->pos.y] \
		[(int)(info->pos.x + info->dir.x * MOVE_SPEED)] != '1')
		info->pos.x += info->dir.x * MOVE_SPEED;
	if (info->map[info->nb_lines - (int)(info->pos.y \
		+ info->dir.y * MOVE_SPEED)][(int)(info->pos.x)] != '1')
		info->pos.y += info->dir.y * MOVE_SPEED;
}

void	backward(t_info *info)
{
	if (info->map[info->nb_lines - (int)info->pos.y][(int)(info->pos.x - \
		info->dir.x * MOVE_SPEED)] != '1')
		info->pos.x -= info->dir.x * MOVE_SPEED;
	if (info->map[info->nb_lines - (int)(info->pos.y - \
		info->dir.y * MOVE_SPEED)][(int)(info->pos.x)] != '1')
		info->pos.y -= info->dir.y * MOVE_SPEED;
}

void	left(t_info *info)
{
	if (info->map[info->nb_lines - (int)info->pos.y][(int)(info->pos.x - \
		info->plane.x * MOVE_SPEED)] != '1')
		info->pos.x -= info->plane.x * MOVE_SPEED;
	if (info->map[info->nb_lines - (int)(info->pos.y - \
		info->plane.y * MOVE_SPEED)][(int)(info->pos.x)] != '1')
		info->pos.y -= info->plane.y * MOVE_SPEED;
}

void	right(t_info *info)
{
	if (info->map[info->nb_lines - (int)info->pos.y][(int)(info->pos.x + \
		info->plane.x * MOVE_SPEED)] != '1')
		info->pos.x += info->plane.x * MOVE_SPEED;
	if (info->map[info->nb_lines - (int)(info->pos.y + \
		info->plane.y * MOVE_SPEED)][(int)(info->pos.x)] != '1')
		info->pos.y += info->plane.y * MOVE_SPEED;
}
