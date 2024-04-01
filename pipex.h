/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:00:29 by jteste            #+#    #+#             */
/*   Updated: 2024/04/01 05:27:14 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./printf/ft_printf.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>
# include <limits.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	char** 	paths;
	char*	path_cmd1;
	char*	path_cmd2;
	char**	cmd1_args;
	char**	cmd2_args;
	pid_t	pid;
	int		fd_in;
	int		fd_out;
	int		pipe_fd[2];
	
}	t_pipex;

char*	get_path(char *cmd, char** env, t_pipex *s);
char*	path_line(char **env);
void	struct_init(char **argv, char** env, t_pipex *s);
void	double_tab_free(char **tab);
void	free_all(t_pipex *s);
void	child_process(t_pipex *s, char **env);
void	parent_process(t_pipex *s, char **env);
void	exec_cmd(t_pipex *s, char **env, int flag);

#endif