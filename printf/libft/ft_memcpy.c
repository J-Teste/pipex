/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:57:52 by jteste            #+#    #+#             */
/*   Updated: 2023/10/20 12:03:44 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	size_t	i;

	i = 0;
	if (!destination && !source)
		return (0);
	while (i < size)
	{
		((char *)destination)[i] = ((char *)source)[i];
		i++;
	}
	return (destination);
}
