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

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*a;
	size_t	b;

	b = 0;
	a = malloc(nitems * size);
	if (!a)
		return (0);
	while (b < size * nitems)
	{
		((char *)a)[b] = 0;
		b++;
	}
	return (a);
}
