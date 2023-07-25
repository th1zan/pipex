/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanglar <tsanglar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:13:29 by thibault          #+#    #+#             */
/*   Updated: 2023/07/25 14:59:55 by tsanglar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/inc_lib.h"
#include "./header/inc_fct.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd_in_out[2];
	int		pipe_tab[2];
	char	**path;

	if (argc != 5)
	{
		ft_putstr_fd("./pipex file1 cmd1 cmd2 file2\n", 2);
		exit(0);
	}
	fd_in_out[0] = get_fd(argv[1], 0);
	fd_in_out[1] = get_fd(argv[4], 1);
	path = get_path(envp);
	check_empty(argv, 2, argc - 1);
	dup2(fd_in_out[0], STDIN_FILENO);
	dup2(fd_in_out[1], STDOUT_FILENO);
	pipe_fd(pipe_tab);
	fork_fct(pipe_tab, argv, path);
	return (0);
}

int	get_fd(char *file, int in_out)
{
	int	fd;

	if (in_out == 0)
	{
		fd = open(file, O_RDONLY, 0777);
		if (fd == -1)
		{
			ft_putstr_fd("pipex: no such file or directory: ", 2);
			ft_putendl_fd(file, 2);
			exit (0);
		}
	}
	if (in_out == 1)
	{
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fd == -1)
		{
			exit (0);
		}
	}
	return (fd);
}

int	pipe_fd(int *fd_tab)
{
	if (pipe(fd_tab) == -1)
	{
		perror("pipex: failed to create the pipe");
		return (-1);
	}
	return (0);
}

int	fork_fct(int *pipe_tab, char **argv, char **path)
{
	pid_t	pid_parent;
	int		status;

	pid_parent = fork();
	if (pid_parent == -1)
	{
		perror("Failed to fork");
		exit (1);
	}
	if (pid_parent == 0)
	{
		dup2(pipe_tab[1], STDOUT_FILENO);
		close(pipe_tab[0]);
		exec_function(argv[2], path);
	}
	else if (pid_parent > 0 && *argv[3] != 0)
	{
		waitpid(-1, &status, 0);
		dup2(pipe_tab[0], STDIN_FILENO);
		close(pipe_tab[1]);
		exec_function(argv[3], path);
	}
	free (path);
	return (0);
}

int	exec_function(char *fct, char **path)
{
	char	**fct_arg;
	char	*temp;
	int		i;

	temp = NULL;
	fct_arg = NULL;
	fct_arg = ft_split(fct, ' ');
	i = 0;
	while (path[i] != 0)
	{
		temp = ft_strjoin(path[i], "/");
		fct = ft_strjoin(temp, fct_arg[0]);
		free(temp);
		if (check_access(fct, fct_arg) == 1)
		{
			if (execve(fct, fct_arg, path) == -1)
				return (exec_err("pipex: error when executing: ", fct_arg));
		}
		else
			i++;
	}
	return (exec_err("pipex: command not found: ", fct_arg));
}
