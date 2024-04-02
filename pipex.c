/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:59:12 by jteste            #+#    #+#             */
/*   Updated: 2024/04/02 18:42:08 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(t_pipex *s, char **env, int flag)
{
	if (flag == 0)
	{
		if (s->fd_in == -1)
			exit(EXIT_FAILURE);
		if (execve(s->path_cmd1, s->cmd1_args, env) == -1)
		{
			ft_putendl_fd("Can't execute following commande : ", 2);
			ft_putendl_fd(s->cmd1_args[0], 2);
			free_all(s);
			exit(EXIT_FAILURE);
		}
	}	
	else if (flag == 1)
	{
		if (execve(s->path_cmd2, s->cmd2_args, env) == -1)
		{
			ft_putendl_fd("Can't execute following commande : ", 2);
			ft_putendl_fd(s->cmd2_args[0], 2);
			free_all(s);
			exit(EXIT_FAILURE);
		}
	}
}

void	second_child_process(t_pipex *s, char **env)
{
	close(s->pipe_fd[1]);
	dup2(s->pipe_fd[0], STDIN_FILENO);
	dup2(s->fd_out, STDOUT_FILENO);
	exec_cmd(s, env, 1);
}

void	first_child_process(t_pipex *s, char **env)
{
	close(s->pipe_fd[0]);
	dup2(s->fd_in, STDIN_FILENO);
	dup2(s->pipe_fd[1], STDOUT_FILENO);
	exec_cmd(s, env, 0);
}

int	main(int argc, char *argv[], char *env[])
{
	t_pipex	s;

	if (argc != 5)
	{
		ft_putendl_fd("./pipex in_file cmd1 cmd2 out_file", 2);
		return (-1);
	}
	struct_init(argv, env, &s);
	s.pid1 = fork();
	if (s.pid1 == -1)
		return (perror("Fork error"), free_all(&s), EXIT_FAILURE);
	if (s.pid1 == 0)
		first_child_process(&s, env);
	s.pid2 = fork();
	if (s.pid2 == -1)
		return (perror("Fork error"), free_all(&s), EXIT_FAILURE);
	if (s.pid2 == 0)
		second_child_process(&s, env);
	close(s.pipe_fd[0]);
	close(s.pipe_fd[1]);
	waitpid(s.pid1, NULL, 0);
	waitpid(s.pid2, NULL, 0);
	free_all(&s);
	return (0);
}
