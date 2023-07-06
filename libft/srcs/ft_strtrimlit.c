/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanglar <tsanglar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:19:19 by tsanglar          #+#    #+#             */
/*   Updated: 2022/11/14 17:11:18 by tsanglar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtriminit(char const *s1, char const *set);
char	*ft_strtrimfin(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*si;
	char	*sf;
	char	*strim;
	int		lenstrim;
	int		i;	

	if (!*s1)
		return (0);
	si = ft_strtriminit(s1, set);
	sf = ft_strtrimfin(s1, set);
	lenstrim = sf - si;
	strim = malloc((sizeof(char) * (lenstrim + 1)));
	if (!strim)
		return (0);
	i = 0;
	while (i <= lenstrim)
	{
		strim[i] = si[i];
		i++;
	}
	strim[i] = 0;
	return (strim);
}

char	*ft_strtriminit(char const *si, char const *set)
{
	int		i;

	i = 0;
	while (si[i] == set[i])
	{
		while (si[i] == set[i] && set[i] != 0)
			i++;
		if (set[i] == 0)
		{
			si = si + i;
			i = 0;
		}
	}
	return ((char *) si);
}

char	*ft_strtrimfin(char const *s1, char const *set)
{
	int		lenset;
	char	*sf;
	char	*setf;
	int		i;

	lenset = ft_strlen (set);
	sf = (char *)s1 + ft_strlen(s1) - 1;
	setf = (char *)set + lenset - 1 ;
	i = 0;
	while (*(sf - i) == *(setf - i))
	{
		while (*(sf - i) == *(setf - i))
			i++;
		if (lenset - i == 0)
		{
			sf = sf - lenset;
			i = 0;
		}
	}
	return (sf);
}	
