/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:16:45 by jteste            #+#    #+#             */
/*   Updated: 2023/10/18 13:21:34 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cmp(const char *str, const char *tofind, size_t i, size_t len)
{
	int	j;

	j = 0;
	while (tofind[j] != '\0' && str[i + j] != '\0' && (i + j) < len)
	{
		if (str[i + j] != tofind[j])
		{
			return (0);
		}
		j++;
	}
	if (tofind[j] == '\0')
	{
		return (1);
	}
	return (0);
}

char	*ft_strnstr(const char *str, const char *tofind, size_t len)
{
	size_t	i;

	i = 0;
	if (tofind[i] == '\0')
		return ((char *)str);
	while ((str[i] != '\0') && (i < len))
	{
		if (ft_cmp(str, tofind, i, len) == 1)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	return (0);
}
