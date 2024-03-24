/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:51:56 by jteste            #+#    #+#             */
/*   Updated: 2023/11/16 11:48:02 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_p(va_list args, t_print **head)
{
	char	*tab;
	int		size;
	t_print	*new;

	tab = ft_itoa_ptr(va_arg(args, unsigned long));
	size = ft_strlen(tab);
	new = ft_lstnew_printf(size, tab);
	ft_lstadd_back_pf(head, new);
	return ;
}

void	ft_id(va_list args, t_print **head)
{
	char	*tab;
	int		size;
	t_print	*new;

	tab = ft_itoa(va_arg(args, unsigned long));
	size = ft_strlen(tab);
	new = ft_lstnew_printf(size, tab);
	ft_lstadd_back_pf(head, new);
	return ;
}

void	ft_u(va_list args, t_print **head)
{
	char	*tab;
	int		size;
	t_print	*new;

	tab = ft_itoa_unsigned(va_arg(args, unsigned long));
	size = ft_strlen(tab);
	new = ft_lstnew_printf(size, tab);
	ft_lstadd_back_pf(head, new);
	return ;
}

void	ft_x_low(va_list args, t_print **head)
{
	char	*tab;
	int		size;
	t_print	*new;

	tab = ft_itoa_hex_low(va_arg(args, unsigned long));
	size = ft_strlen(tab);
	new = ft_lstnew_printf(size, tab);
	ft_lstadd_back_pf(head, new);
	return ;
}

void	ft_x(va_list args, t_print **head)
{
	char	*tab;
	int		size;
	t_print	*new;

	tab = ft_itoa_hex(va_arg(args, unsigned long));
	size = ft_strlen(tab);
	new = ft_lstnew_printf(size, tab);
	ft_lstadd_back_pf(head, new);
	return ;
}
