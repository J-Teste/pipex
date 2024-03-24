/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:22:07 by jteste            #+#    #+#             */
/*   Updated: 2023/10/24 12:28:59 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t size)
{
	size_t	i;
	char	*src;
	char	*dest;

	i = -1;
	dest = (char *)destination;
	src = (char *)source;
	if (destination == NULL && source == NULL)
		return (NULL);
	if (dest > src)
	{
		while (size > 0)
		{
			dest[size - 1] = src[size - 1];
			size--;
		}
	}
	else
	{
		while (++i < size)
		{
			dest[i] = src[i];
		}
	}
	return (dest);
}
