/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:28:59 by lorobert          #+#    #+#             */
/*   Updated: 2023/07/10 13:16:32 by lorobert         ###   ########.fr       */
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

static void	create_map(t_info *info, t_list *tmp)
{
	t_list		*backup;
	int			i;

	info->map = malloc(sizeof(char *) * (info->nb_lines + 1));
	if (!info->map)
		fatal_error("Unable to allocate map\n", NULL);
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
	create_map(info, tmp);
	if (close(fd) == -1)
		fatal_error(NULL, file_name);
}
