/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:49:08 by jteste            #+#    #+#             */
/*   Updated: 2023/11/15 16:48:53 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getsize(int n)
{
	size_t	size;

	size = 0;
	if (n < 0)
		n = -n;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static char	*ft_filltab(int dst_size, int i, char *dst, long int num)
{
	dst[dst_size] = '\0';
	while (dst_size > i)
	{
		dst_size--;
		dst[dst_size] = (num % 10) + '0';
		num = num / 10;
	}
	return (dst);
}

char	*ft_itoa(int n)
{
	int			dst_size;
	char		*dst;
	int			i;
	long int	num;

	num = n;
	dst_size = ft_getsize(n);
	i = 0;
	if (n < 0 || dst_size == 0)
		dst_size++;
	dst = malloc((dst_size + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	if (num < 0)
	{
		num = -num;
		dst[0] = '-';
		i++;
	}
	return (ft_filltab(dst_size, i, dst, num));
}
