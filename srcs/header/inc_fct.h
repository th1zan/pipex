/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc_fct.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:17:41 by thibault          #+#    #+#             */
/*   Updated: 2023/07/19 16:37:42 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INC_FUNCTIONS_H
# define INC_FUNCTIONS_H

/*pipex.c*/
int		get_fd(char *file, int in_out);
int		pipe_fd(int *fd_tab);
int		fork_fct(int *pipe_tab, char **argv, char **path);
int		check_empty(char **tab_str, int from, int to);
int		iswhitespace(int c);
char	**get_path(char **envp);
int		exec_function(char *fct, char **path);
int		free_tab(char **tab);
#endif

