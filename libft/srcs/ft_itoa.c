/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanglar <tsanglar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:47:15 by tsanglar          #+#    #+#             */
/*   Updated: 2022/11/22 15:33:04 by tsanglar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_n_len(int n);

int	ft_n_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*result;

	len = ft_n_len(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	result[len] = '\0';
	len--;
	if (n == 0)
		result[len] = '0';
	if (n < 0)
		result[0] = '-';
	while (n != 0)
	{
		if (n < 0)
			*(result + len) = -(n % 10) + '0';
		else
			*(result + len) = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (result);
}
