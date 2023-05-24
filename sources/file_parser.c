/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:28:59 by lorobert          #+#    #+#             */
/*   Updated: 2023/05/24 14:57:20 by lorobert         ###   ########.fr       */
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
	int		i;

	split = ft_split(line, ' ');
	if (!split)
		fatal_error(NULL);
	i = 0;
	while (split[i] && ft_strncmp(split[i], "./", 2))
		i++;
	if (!split[i])
		fatal_error("No texture file provided\n");
	if (t == NO)
		info->n_texture = ft_strdup(split[i]);
	else if (t == SO)
		info->s_texture = ft_strdup(split[i]);
	else if (t == WE)
		info->w_texture = ft_strdup(split[i]);
	else if (t == EA)
		info->e_texture = ft_strdup(split[i]);
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
				fatal_error("Color must contain numbers only\n");
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
		fatal_error(NULL);
	if (!split[0] || !split[1] || !split[2])
		fatal_error("Wrong color format, use R,G,B\n");
	check_color_component(split);
	color->red = ft_atoi(split[0]);
	color->green = ft_atoi(split[1]);
	color->blue = ft_atoi(split[2]);
	clear_split(split);
}

static void	extract_color(t_info *info, char *line, t_arg_type t)
{
	char	**split;
	int		i;

	split = ft_split(line, ' ');
	if (!split)
		fatal_error(NULL);
	i = 0;
	while (split[i] && !ft_isdigit(split[i][0]))
		i++;
	if (!split[i])
		fatal_error("No color provided\n");
	if (t == F)
		get_color(split[i], &info->f_color);
	else if (t == C)
		get_color(split[i], &info->c_color);
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

void	parse_file(t_info *info, char *file_name)
{
	int			fd;
	t_list		*tmp;
	t_list		*backup;
	char		*line;
	int			i;

	init_info(info);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		fatal_error(NULL);
	line = parse_header(fd, info);
	tmp = NULL;
	while (line)
	{
		ft_lstadd_back(&tmp, ft_lstnew(ft_strdup(line)));
		free(line);
		line = get_next_line(fd);
	}
	info->nb_lines = ft_lstsize(tmp);
	info->map = malloc(sizeof(char *) * (info->nb_lines + 1));
	if (!info->map)
		fatal_error(NULL);
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
