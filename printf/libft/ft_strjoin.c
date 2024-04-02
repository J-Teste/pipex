/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:46:51 by jteste            #+#    #+#             */
/*   Updated: 2024/04/02 18:47:30 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*str;	

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
	{
		return (NULL);
	}
	len = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (0);
	if (s1)
		while (s1[i] != '\0')
			str[j++] = s1[i++];
	i = 0;
	if (s2)
		while (s2[i] != '\0')
			str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}
