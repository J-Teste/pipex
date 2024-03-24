/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:26:59 by jteste            #+#    #+#             */
/*   Updated: 2023/10/20 11:10:44 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memory, int tofind, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (((const char *)memory)[i] == (char)tofind)
		{
			return ((void *)((const char *)memory + i));
		}
		i++;
	}
	return (NULL);
}
