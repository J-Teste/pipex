/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:49:40 by jteste            #+#    #+#             */
/*   Updated: 2023/10/20 10:53:58 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t size)
{
	size_t				i;
	const unsigned char	*s1;
	const unsigned char	*s2;

	s1 = (const unsigned char *)ptr1;
	s2 = (const unsigned char *)ptr2;
	i = 0;
	while ((i < size) && (s1[i] == s2[i]))
	{
		i++;
	}
	if (i == size)
	{
		return (0);
	}
	return (s1[i] - s2[i]);
}
