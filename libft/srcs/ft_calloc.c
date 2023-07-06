/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanglar <tsanglar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:51:13 by tsanglar          #+#    #+#             */
/*   Updated: 2022/11/09 16:37:11 by tsanglar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	i;

	p = (void *) malloc(size * count);
	if (!p)
		return (NULL);
	i = 0;
	while (i < size * count)
	{	
		p[i] = 0;
		i++;
	}
	return ((void *) p);
}
