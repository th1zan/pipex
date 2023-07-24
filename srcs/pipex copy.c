/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:13:29 by thibault          #+#    #+#             */
/*   Updated: 2023/07/17 19:51:27 by thibault         ###   ########.fr       */
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
		ft_putstr_fd("./pipex file1 cmd1 cmd2 file2\n", 1);
		exit(0);
	}
	/* Get file descriptor */
	fd_in_out[0] = get_fd(argv[1], 0);
	fd_in_out[1] = get_fd(argv[4], 1);

	/* Get paths */
	path = get_path(envp);

	/* Redirection of SDTIN */
	dup2(fd_in_out[0], STDIN_FILENO);
	/* Redirection of STDOUT */
	dup2(fd_in_out[1], STDOUT_FILENO);

	/*Pipe creation*/
	pipe_fd(pipe_tab);
	/* Execution */
	exec_fct(pipe_tab, argv, path);


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
			perror("Failed to open the INPUT file");
			return (1);
		}
	}
	if (in_out == 1)
	{
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fd == -1)
		{
			perror("Failed to open the OUTPUT file");
			return (1);
		}
	}
	return (fd);
}

int	pipe_fd(int *fd_tab)
{
	/*
	Pipe creation:
		end[0] will be read
		end[1] will be writed
	*/
	if (pipe(fd_tab) == -1)
	{
		perror("Failed to create the pipe");
		return (1);
	}
	return (0);
}

int exec_fct(int *pipe_tab, char **argv, char **path)
{
	
	pid_t 	pid_parent;
	int		status;

	/* Fork the process */
	/* Execution of fct 1 (child) then 2 (parent)*/
	pid_parent = fork();
	/*
	Instruction for cases:
		1.Fail
		2.Child (-> pid_parent = 0)
		3. Parents (-> pid_parent != 0)
	*/
	if (pid_parent == -1)
	{
		perror("Fail to fork");
		return (1);
	}
	if (pid_parent == 0)
	{
		/* Parent's output to pipe's input */
		dup2(pipe_tab[1], STDOUT_FILENO);
		close(pipe_tab[0]);

		/* Execution of the function*/
		exec_function(argv[2], path);
	}
	else if (pid_parent > 0 && *argv[3] != 0)
	{
		/* Wait for the end of child process */
		waitpid(-1, &status, 0);

		/* Child's input from pipe's output */
		dup2(pipe_tab[0], STDIN_FILENO);
		close(pipe_tab[1]);

		/* Execution of the function*/
		exec_function(argv[3], path);
	}
	free (path);
	return (0);
}

char	**get_path(char **envp)
{
	char	**path;
	int		i;

	path = NULL;
	i = 0;
	while (envp[i] != 0)
	{
		if (ft_strnstr(envp[i], "PATH=", 5) != 0)
			break;
		i++;
	}
	path = ft_split(envp[i], ':');
	return (path);
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

int	exec_function(char *fct, char **path)
{
	char	**fct_arg;
	char	*temp;
	int		i;

	temp = NULL;
	fct_arg = NULL;
	
	/* Separate function and args*/
	fct_arg = ft_split(fct, ' ');

	i = 0 ;
	/* Check different path*/
	while (path[i] != 0)
	{
		temp = ft_strjoin(path[i], "/");
		fct = ft_strjoin(temp, fct_arg[0]);
		free (temp);

		/* Check if fct exist and can be executed by the user */
		if (access(fct, F_OK) == 0)
		{
			if (access(fct, X_OK) == -1)
			{
				perror("The function exists but can't be executed by the user");
				return (1);
			}
			if (execve(fct, fct_arg, path) == -1)
			{
				perror("Error when executing the function");
				return (1);
			}
		}
		else
			i++;
	}
	free_tab(fct_arg);
	if (access(fct, F_OK) == -1)
	{
		perror("The function doesn't exist");
		return (1);
	}
	return (0);
}

//  < file1 grep s | wc -w > file2
// ./pipex file1 fonction1 fonction2 file2
//"PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin"