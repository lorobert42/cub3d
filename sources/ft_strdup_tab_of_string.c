/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_tab_of_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:23:24 by shiroz            #+#    #+#             */
/*   Updated: 2023/07/10 13:17:54 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**ft_strdup_tab_of_string(char **to_duplicate)
{
	int		i;
	char	**to_return;

	i = 0;
	while (to_duplicate[i])
		i++;
	to_return = ft_calloc(sizeof(char *), i + 1);
	while (--i >= 0)
		to_return[i] = ft_strdup(to_duplicate[i]);
	return (to_return);
}
