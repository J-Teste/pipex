/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:41:17 by jteste            #+#    #+#             */
/*   Updated: 2023/10/25 16:45:44 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dst;
	size_t	i;

	if (s == NULL)
		return (NULL);
	dst = malloc((ft_strlen(s)+1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	dst[ft_strlen(s)] = '\0';
	i = -1;
	while (s[++i] != '\0')
	{
		dst[i] = f(i, s[i]);
	}
	dst[i] = '\0';
	return (dst);
}
