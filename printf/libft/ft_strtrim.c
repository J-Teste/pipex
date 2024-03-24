/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:33:01 by jteste            #+#    #+#             */
/*   Updated: 2023/10/25 14:44:24 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	size_t	size;
	char	*dst;
	size_t	i;

	start = 0;
	i = -1;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[start] != '\0' && ft_strchr(set, s1[start]) != NULL)
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && ft_strrchr(set, s1[end]) != NULL)
		end --;
	size = (end - start) + 1;
	dst = malloc(size + 1 * sizeof(char));
	if (!dst)
		return (NULL);
	while (++i < size)
		dst[i] = s1[start + i];
	dst[i] = '\0';
	return (dst);
}
