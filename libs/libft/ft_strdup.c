/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_research_of_square.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiroz <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:18:15 by shiroz            #+#    #+#             */
/*   Updated: 2022/08/03 19:40:39 by shiroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		a;
	char	*c;

	c = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!c)
		return (0);
	a = 0;
	while (src[a])
	{
		c[a] = src[a];
		a++;
	}
	c[a] = 0;
	return (c);
}
