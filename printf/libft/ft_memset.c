/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:09:21 by jteste            #+#    #+#             */
/*   Updated: 2023/10/18 13:21:19 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset( void *ptr, int value, size_t count )
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		((char *)ptr)[i] = value;
		i++;
	}
	return (ptr);
}
