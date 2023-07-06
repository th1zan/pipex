/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanglar <tsanglar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:31:26 by tsanglar          #+#    #+#             */
/*   Updated: 2022/11/09 14:23:57 by tsanglar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t			i;

	i = 0;
	if (src == 0 && dest == 0)
		return (dest);
	if (src < dest)
	{
		while (len--)
		{
			*((char *)(dest) + len) = *((unsigned char *)(src) + len);
		}
	}	
	else
	{
		while (i < len)
		{
			*((char *)(dest) + i) = *((char *)(src) + i);
			i++;
		}
	}
	return (dest);
}
