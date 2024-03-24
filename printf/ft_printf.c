/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:22:42 by jteste            #+#    #+#             */
/*   Updated: 2023/11/21 14:39:37 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

void	ft_checkformat(char format, va_list args, t_print **head)
{
	if (format == 'c')
		ft_c(va_arg(args, int), head);
	if (format == 's')
		ft_s(args, head);
	if (format == 'p')
		ft_p(args, head);
	if ((format == 'd') || (format == 'i'))
		ft_id(args, head);
	if (format == 'u')
		ft_u(args, head);
	if (format == 'x')
		ft_x_low(args, head);
	if (format == 'X')
		ft_x(args, head);
	if (format == '%')
		ft_c('%', head);
}

int	ft_getsize(t_print *head)
{
	int	tabsize;

	tabsize = 0;
	while (head != NULL)
	{
		tabsize = tabsize + head->size;
		head = head->next;
	}
	return (tabsize);
}

int	ft_tab(t_print *head)
{
	int		j;
	int		i;
	int		tabsize;
	char	*tab;
	t_print	*temp;

	i = 0;
	tabsize = 0;
	temp = head;
	tabsize = ft_getsize(head);
	tab = malloc((tabsize + 1) * sizeof(char));
	tab[tabsize] = '\0';
	head = temp;
	while (head != NULL)
	{
		j = 0;
		while (j < head->size)
			tab[i++] = head->str[j++];
		head = head->next;
	}
	head = temp;
	write(1, tab, tabsize);
	ft_lstclear_pf(&head);
	free(tab);
	return (tabsize);
}

int	ft_printf(const char *format, ...)
{
	int				index;
	va_list			args;
	t_print			*head;

	head = NULL;
	va_start (args, format);
	index = 0;
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			index++;
			ft_checkformat(format[index], args, &head);
			index++;
		}
		else
		{
			ft_c(format[index], &head);
			index ++;
		}
	}
	va_end(args);
	return (ft_tab(head));
}
