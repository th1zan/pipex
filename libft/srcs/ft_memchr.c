/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanglar <tsanglar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:28:34 by tsanglar          #+#    #+#             */
/*   Updated: 2022/11/09 14:29:07 by tsanglar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{	
	while (!s || n--)
	{
		if (*(unsigned char *)s == (unsigned char) c)
			return ((void *) s);
		s++;
	}
	return (0);
}
