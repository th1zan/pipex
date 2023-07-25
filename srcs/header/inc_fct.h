/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc_fct.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanglar <tsanglar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:17:41 by thibault          #+#    #+#             */
/*   Updated: 2023/07/25 13:35:51 by tsanglar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INC_FCT_H
# define INC_FCT_H

/*pipex.c*/
int		get_fd(char *file, int in_out);
int		pipe_fd(int *fd_tab);
int		fork_fct(int *pipe_tab, char **argv, char **path);
int		exec_function(char *fct, char **path);

/*pipex_adds.c*/
char	**get_path(char **envp);
int		iswhitespace(int c);
int		check_empty(char **tab_str, int from, int to);
int		free_tab(char **tab);
int		check_access(char *fct, char **fct_arg);

/*handle_error.c*/
int		exec_err(char *error_msg, char **fct_arg);
int		empty_fct_err(int cmd);

#endif
