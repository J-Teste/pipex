/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:24:33 by jteste            #+#    #+#             */
/*   Updated: 2023/11/21 13:48:17 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

static size_t	ft_getsize(unsigned long n)
{
	size_t	size;

	size = 0;
	while (n)
	{
		n = n / 16;
		size++;
	}
	return (size);
}

static char	*ft_filltab(long dst_size, char *dst, unsigned long num)
{
	if (num != 0)
	{
		dst[0] = '0';
		dst[1] = 'x';
	}
	dst[dst_size] = '\0';
	while (num != 0)
	{
		dst_size--;
		dst[dst_size] = "0123456789abcdef" [num % 16];
		num = num / 16;
	}
	return (dst);
}

char	*ft_itoa_ptr(unsigned long n)
{
	long			dst_size;
	char			*dst;
	unsigned long	num;

	if (n == 0)
	{
		dst = malloc(6 * sizeof(char));
		if (dst == NULL)
			return (NULL);
		return (ft_strcpy(dst, "0x0"));
	}
	num = n;
	dst_size = ft_getsize(n);
	if (dst_size == 0)
		dst_size++;
	dst = malloc((dst_size + 3) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	return (ft_filltab(dst_size + 2, dst, num));
}
