/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 04:55:50 by jteste            #+#    #+#             */
/*   Updated: 2024/03/31 05:52:56 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char*	get_path(char *cmd, char** env)
{
	char **paths;
	int i;
	
	i = 0;
	paths = ft_split(path_line(env),':');
	while (paths[i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		paths[i] = ft_strjoin(paths[i], cmd);
		i++;
	}
	i = 0;
	while (paths[i])
	{
		if (access(paths[i], F_OK | X_OK) == 0)
		{
			return(paths[i]);
		}
		i++;
	}
	return(NULL);
}

char *path_line(char **env)
{
	int i;

	i = 0;
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