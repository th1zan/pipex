/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanglar <tsanglar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:30:45 by tsanglar          #+#    #+#             */
/*   Updated: 2023/07/25 13:33:37 by tsanglar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/inc_lib.h"
#include "./header/inc_fct.h"

int	exec_err(char *error_msg, char **fct_arg)
{
	ft_putstr_fd(error_msg, 2);
	ft_putendl_fd(fct_arg[0], 2);
	free_tab(fct_arg);
	return (1);
}

int	empty_fct_err(int cmd)
{
	ft_putstr_fd("pipex: cmd", 2);
	ft_putnbr_fd(cmd, 2);
	ft_putendl_fd(" not valid (empty or contains whitespaces only)", 2);
	return (0);
}
