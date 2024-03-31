/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:59:12 by jteste            #+#    #+#             */
/*   Updated: 2024/03/31 05:52:57 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[], char *env[])
{
	(void)argc;
	t_pipex	s;

	struct_init(argv, env, &s);
	return(0);
}

void	struct_init(char **argv, char** env, t_pipex *s)
{
	s->path_cmd1 = get_path(argv[2],env);
	s->path_cmd2 = get_path(argv[3],env);
	printf("%s\n",s->path_cmd1);
	printf("%s\n",s->path_cmd2);
}
