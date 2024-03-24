/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:16:33 by jteste            #+#    #+#             */
/*   Updated: 2023/11/21 13:54:52 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_s(va_list args, t_print **head)
{
	char	*tab;
	char	*arg;
	int		size;
	t_print	*new;

	arg = va_arg(args, char *);
	if (arg == NULL)
		tab = ft_strdup("(null)");
	else
		tab = ft_strdup(arg);
	size = ft_strlen(tab);
	new = ft_lstnew_printf(size, tab);
	ft_lstadd_back_pf(head, new);
	return ;
}

void	ft_c(char c, t_print **head)
{
	char	*tab;
	int		size;
	t_print	*new;

	tab = malloc(2 * sizeof(char));
	if (tab == NULL)
		return ;
	tab[0] = c;
	tab[1] = '\0';
	size = 1;
	new = ft_lstnew_printf(size, tab);
	ft_lstadd_back_pf(head, new);
	return ;
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
