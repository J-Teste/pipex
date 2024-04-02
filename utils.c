/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 04:55:50 by jteste            #+#    #+#             */
/*   Updated: 2024/04/02 02:14:01 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	struct_init(char **argv, char** env, t_pipex *s)
{
	s->fd_in = open(argv[1],O_RDONLY);
	if (s->fd_in < 0)
		perror("Error opening in_file");
	s->fd_out = open(argv[4],O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (s->fd_out < 0)
	{
		perror("Error creating out_file");
		exit(EXIT_FAILURE);
	}
	if (pipe(s->pipe_fd) == -1)
	{
		perror("Error with pipe");
		exit(EXIT_FAILURE);
	}
	s->cmd1_args = ft_split(argv[2], ' ');
	s->cmd2_args = ft_split(argv[3], ' ');
	s->path_cmd1 = get_path(s->cmd1_args[0], env, s);
	s->path_cmd2 = get_path(s->cmd2_args[0], env ,s);
}

char*	get_path(char *cmd, char** env, t_pipex *s)
{
	int i;
	char	*full_path;
	char	*cmd_path;
	
	i = 0;
	s->paths = ft_split(path_line(env),':');
	while (s->paths[i])
	{
		full_path = ft_strjoin(s->paths[i], "/");
		cmd_path = ft_strjoin(full_path, cmd);
		free(full_path);
		if (access(cmd_path, F_OK | X_OK) == 0)
		{
			double_tab_free(s->paths);
			return(cmd_path);
		}
		free(cmd_path);
		i++;
	}
	double_tab_free(s->paths);
	return(NULL);
}

char *path_line(char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i],"PATH=",5) == 0)
			return(env[i]+5);
		i++;
	}
	return(NULL);
}
void	free_all(t_pipex *s)
{
	double_tab_free(s->cmd1_args);
	double_tab_free(s->cmd2_args);
	free(s->path_cmd1);
	free(s->path_cmd2);
}
void	double_tab_free(char **tab)
{
	int i;

	i = 0;
	if (!tab)
		return;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);	
}
