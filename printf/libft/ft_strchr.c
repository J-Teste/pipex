/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:46:50 by jteste            #+#    #+#             */
/*   Updated: 2023/10/24 11:25:01 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int tofind)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != (char)tofind)
	{
		i++;
	}
	if (str[i] == (char)tofind)
	{
		return ((char *)&str[i]);
	}
	else
		return ((char *) NULL);
}
