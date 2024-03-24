/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:08:06 by jteste            #+#    #+#             */
/*   Updated: 2023/11/02 11:02:41 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *s, char c)
{
	int	i;
	int	boolean;
	int	words;

	i = 0;
	words = 0;
	boolean = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && boolean == 0)
		{
			boolean = 1;
			words++;
		}
		else if (s[i] == c)
			boolean = 0;
		i++;
	}
	return (words);
}

static char	**ft_doubletabfree(int i, char **dest)
{
	while (i > 0)
	{
		i--;
		free(dest[i]);
	}
	free(dest);
	return (NULL);
}

static	char	**ft_filltab(char const *s, char c, char **dest)
{
	int	start;
	int	end;
	int	i;

	start = 0;
	end = 0;
	i = 0;
	while (s[start] != '\0' && i < ft_countwords(s, c))
	{
		while (s[start] != '\0' && s[start] == c)
			start++;
		end = start;
		while (s[end] != '\0' && s[end] != c)
			end++;
		dest[i] = ft_substr(s, start, end - start);
		if (dest[i] == NULL)
			return (ft_doubletabfree(i, dest));
		i++;
		start = end;
	}
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;

	if (!s)
		return (NULL);
	dest = malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (dest == NULL)
		return (NULL);
	dest[ft_countwords(s, c)] = NULL;
	dest = ft_filltab(s, c, dest);
	return (dest);
}
