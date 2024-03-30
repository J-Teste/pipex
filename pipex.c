/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:59:12 by jteste            #+#    #+#             */
/*   Updated: 2024/03/30 23:17:42 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[], char *env[])
{
	(void)argc;
	(void)argv;
	t_pipex	s;
	
	s.paths = ft_split(get_paths(env),':');
	int i = 0;
	while (s.paths[i])
	{
		printf("%s\n",s.paths[i]);
		i++;
	}

	return 0;
}

char*	get_paths(char** env)
{
	int i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i],"PATH=",5) == 0)
		{
			return(env[i]+5);
		}
		i++;
	}
	return(NULL);
}