/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanglar <tsanglar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:13:42 by thibault          #+#    #+#             */
/*   Updated: 2022/12/21 15:04:37 by tsanglar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

// function declaration

int		ft_printf(const char *str, ...);
int		ft_printf_format(const char *s, va_list args, int *r);

int		ft_printf_c(unsigned char c, int *result);
int		ft_printf_s(char *s, int *result);
int		ft_printf_di(int n, int *result);
int		ft_printf_u(unsigned int n, int *result);
int		ft_printf_hex(unsigned long dec, int *result, int cap);
int		ft_printf_ptr(unsigned long dec, int *result);

#endif