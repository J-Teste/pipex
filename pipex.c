/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:59:12 by jteste            #+#    #+#             */
/*   Updated: 2024/04/01 05:35:34 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(t_pipex *s, char **env, int flag)
{
	if (flag == 0)
	{
		if (execve(s->path_cmd1, s->cmd1_args, env) == -1)
		{
		ft_putendl_fd("Can't execute following commande : ",2);
		ft_putendl_fd(s->cmd1_args[0],2);
		free_all(s);
		exit(EXIT_FAILURE);
		}
	}	
	else if (flag == 1)
	{
		if (execve(s->path_cmd2, s->cmd2_args, env) == -1)
		{
		ft_putendl_fd("Can't execute following commande : ",2);
		ft_putendl_fd(s->cmd2_args[0],2);
		free_all(s);
		exit(EXIT_FAILURE);
		}
	}
}
void	parent_process(t_pipex *s, char **env)
{
	close(s->pipe_fd[1]);
	dup2(s->pipe_fd[0],STDIN_FILENO);
	dup2(s->fd_out, STDOUT_FILENO);
	exec_cmd(s, env, 1);	
}

void	child_process(t_pipex *s, char **env)
{
	close(s->pipe_fd[0]);
	dup2(s->fd_in, STDIN_FILENO);
	dup2(s->pipe_fd[1],STDOUT_FILENO);
	exec_cmd(s, env, 0);

}

int main(int argc, char *argv[], char *env[])
{
	t_pipex	s;

	if (argc != 5)
	{
		ft_putendl_fd("Execute pipex as follow : ./pipex in_file cmd1 cmd2 out_file",2);
		return(-1);
	}
	ft_bzero(&s,sizeof(t_pipex));
	struct_init(argv, env, &s);
	s.pid = fork();
	if (s.pid == -1)
	{
		free_all(&s);
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	if (s.pid == 0)
		child_process(&s, env);
	else
		parent_process(&s,env);
	return(0);
}

