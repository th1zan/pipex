/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_adds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanglar <tsanglar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:39:19 by tsanglar          #+#    #+#             */
/*   Updated: 2023/07/25 13:35:35 by tsanglar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/inc_lib.h"
#include "./header/inc_fct.h"

char	**get_path(char **envp)
{
	char	**path;
	int		i;

	path = NULL;
	i = 0;
	while (envp[i] != 0)
	{
		if (ft_strnstr(envp[i], "PATH=", 5) != 0)
			break ;
		i++;
	}
	path = ft_split(envp[i], ':');
	return (path);
}

int	check_empty(char **tab_str, int from, int to)
{
	int	i;
	int	j;
	int	ws;

	i = from;
	while (i < to)
	{
		if (tab_str[i] == NULL)
		{
			perror("./pipex file1 cmd1 cmd2 file2\n");
			exit (0);
		}
		j = 0;
		ws = 0;
		while (tab_str[i][j] != 0)
		{
			ws = ws + iswhitespace(tab_str[i][j]);
			j++;
		}
		if (ws == 0)
			exit (empty_fct_err(i - 1));
		i++;
	}
	return (0);
}

int	iswhitespace(int c)
{
	if (c == '\t' || c == '\v' || c == '\n')
		return (0);
	if (c == ' ' || c == '\r' || c == '\f')
		return (0);
	else
		return (1);
}

int	free_tab(char **tab)
{
	int	i;

	if (tab == NULL)
		return (-1);
	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

int	check_access(char *fct, char **fct_arg)
{
	int	get_access;

	get_access = 0;
	if (access(fct, F_OK) == 0)
	{
		if (access(fct, X_OK) == -1)
		{
			ft_putstr_fd("pipex: cmd can't be executed by the user: ", 2);
			ft_putendl_fd(fct_arg[0], 2);
			return (1);
		}
		get_access = 1;
	}
	return (get_access);
}
