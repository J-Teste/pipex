/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:47:36 by jteste            #+#    #+#             */
/*   Updated: 2023/10/24 14:01:11 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getlen(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	i;

	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (j < len && i >= start)
			j++;
		i++;
	}
	return (j);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (start >= ft_strlen(s))
	{
		dest = malloc(1 * sizeof(char));
		if (!dest)
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	dest = malloc((ft_getlen(s, start, len) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (i < len && s[start] != '\0')
	{
		dest[i] = s[start];
		start++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
