/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:29:47 by tsanglar          #+#    #+#             */
/*   Updated: 2023/07/08 18:03:38 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_ptr(unsigned long dec, int *result)
{
	write(1, "0x", 2);
	*result = *result + 2;
	if (dec == 0)
	{
		write(1, "0", 1);
		*result = *result + 1;
	}
	else
		ft_printf_hex(dec, result, 0);
	return (0);
}
