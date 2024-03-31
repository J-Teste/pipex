/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:00:29 by jteste            #+#    #+#             */
/*   Updated: 2024/03/31 05:53:00 by jteste           ###   ########.fr       */
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

// Struct
typedef struct s_pipex
{
	char* path_cmd1;
	char* path_cmd2;
	char*	file_in;
	char*	file_out;
	int		fd_in;
	int		fd_out;
	int		pipe_fd[2];
	
}	t_pipex;


char*	get_path(char *cmd, char** env);
char *path_line(char **env);
void	struct_init(char **argv, char** env, t_pipex *s);

#endif