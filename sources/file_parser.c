/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:28:59 by lorobert          #+#    #+#             */
/*   Updated: 2023/06/04 21:07:31 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_arg_type	identify_line(char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
		return (NO);
	else if (!ft_strncmp(line, "SO ", 3))
		return (SO);
	else if (!ft_strncmp(line, "WE ", 3))
		return (WE);
	else if (!ft_strncmp(line, "EA ", 3))
		return (EA);
	else if (!ft_strncmp(line, "F ", 2))
		return (F);
	else if (!ft_strncmp(line, "C ", 2))
		return (C);
	else if (!ft_strncmp(line, "\n", 1))
		return (EMPTY);
	return (NONE);
}

static void	extract_texture(t_info *info, char *line, t_arg_type t)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		fatal_error(NULL, line);
	if (!split[1])
		fatal_error("No texture file provided\n", line);
	if (split[2])
		fatal_error("Too many texture files\n", line);
	if (t == NO)
		info->n_texture = ft_strdup(split[1]);
	else if (t == SO)
		info->s_texture = ft_strdup(split[1]);
	else if (t == WE)
		info->w_texture = ft_strdup(split[1]);
	else if (t == EA)
		info->e_texture = ft_strdup(split[1]);
	clear_split(split);
}

static void	check_color_component(char **color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (color[i][j])
		{
			if (!ft_isdigit(color[i][j]))
				fatal_error("Color must contain numbers only\n", color[i]);
			j++;
		}
		i++;
	}
}

static void	get_color(char *c_str, t_color *color)
{
	char	**split;

	split = ft_split(c_str, ',');
	if (!split)
		fatal_error(NULL, c_str);
	if (!split[0] || !split[1] || !split[2] || split[3])
		fatal_error("Wrong color format, use R,G,B\n", c_str);
	check_color_component(split);
	color->red = ft_atoi(split[0]);
	color->green = ft_atoi(split[1]);
	color->blue = ft_atoi(split[2]);
	color->final = (0 << 24 | color->red << 16 | color->green << 8 | \
		color->blue);
	clear_split(split);
}

static void	extract_color(t_info *info, char *line, t_arg_type t)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		fatal_error(NULL, line);
	if (!split[1])
		fatal_error("No color provided\n", line);
	if (t == F)
		get_color(split[1], &info->f_color);
	else if (t == C)
		get_color(split[1], &info->c_color);
	clear_split(split);
}

static void	extract_line(t_info *info, char *line, t_arg_type t)
{
	char	*n;

	n = ft_strrchr(line, '\n');
	*n = '\0';
	if (t == EMPTY)
		return ;
	else if (t <= 3)
		extract_texture(info, line, t);
	else
		extract_color(info, line, t);
}

static char	*parse_header(int fd, t_info *info)
{
	char		*line;
	t_arg_type	t;

	line = get_next_line(fd);
	while (line)
	{
		t = identify_line(line);
		if (t == NONE)
			break ;
		extract_line(info, line, t);
		free(line);
		line = get_next_line(fd);
	}
	check_info_header(info);
	return (line);
}

static void	creat_map(t_info *info, t_list *tmp)
{
	t_list		*backup;
	int			i;

	info->map = malloc(sizeof(char *) * (info->nb_lines + 1));
	if (!info->map)
		fatal_error(NULL, "map allocation");
	backup = tmp;
	i = 0;
	while (tmp)
	{
		info->map[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	info->map[i] = NULL;
	ft_lstclear(&backup, &del);
}

void	parse_file(t_info *info, char *file_name)
{
	int			fd;
	t_list		*tmp;
	char		*line;

	init_info(info);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		fatal_error(NULL, file_name);
	line = parse_header(fd, info);
	tmp = NULL;
	while (line)
	{
		ft_lstadd_back(&tmp, ft_lstnew(ft_strdup(line)));
		free(line);
		line = get_next_line(fd);
	}
	info->nb_lines = ft_lstsize(tmp);
	creat_map(info, tmp);
	close(fd);
}
