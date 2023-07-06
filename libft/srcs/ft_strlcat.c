/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanglar <tsanglar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:19:02 by tsanglar          #+#    #+#             */
/*   Updated: 2022/11/09 14:25:09 by tsanglar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lensrc;
	size_t	lendst;

	lensrc = 0;
	lendst = 0;
	i = 0;
	while (src[lensrc])
		lensrc++;
	while (dst[lendst])
		lendst++;
	if (dstsize == 0)
		return (lensrc);
	if (dstsize < lendst)
		return (dstsize + lensrc);
	while (lendst + i < dstsize - 1 && src[i] != '\0')
	{
		dst[lendst + i] = src[i];
		i++;
	}
	dst[lendst + i] = '\0';
	return (lendst + lensrc);
}
