/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_tab_of_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:23:24 by shiroz            #+#    #+#             */
/*   Updated: 2023/05/26 10:50:09 by shiroz           ###   ########.fr       */
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
