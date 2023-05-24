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

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*c;
	unsigned int	a;

	c = malloc(sizeof(char) * (ft_strlen(s) + 1));
	a = 0;
	if (!c)
		return (0);
	while (s[a])
	{
		c[a] = (*f)(a, s[a]);
		a++;
	}
	c[a] = 0;
	return (c);
}
