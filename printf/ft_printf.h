/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:24:41 by jteste            #+#    #+#             */
/*   Updated: 2023/11/16 14:20:27 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdio.h>
# include <stdarg.h>

typedef struct s_print
{
	int				size;
	char			*str;
	struct s_print	*next;
}	t_print;

int		ft_printf(const char *format, ...);
void	ft_putptr(void	*ptr);
t_print	*ft_lstnew_printf(int size, char *str);
char	*ft_itoa_unsigned(unsigned int n);
char	*ft_itoa_ptr(unsigned long n);
char	*ft_itoa_hex(unsigned int n);
char	*ft_itoa_hex_low(unsigned int n);
void	ft_p(va_list args, t_print **head);
void	ft_id(va_list args, t_print **head);
void	ft_u(va_list args, t_print **head);
void	ft_x(va_list args, t_print **head);
void	ft_x_low(va_list args, t_print **head);
void	ft_s(va_list args, t_print **head);
void	ft_c(char c, t_print **head);
void	ft_lstadd_back_pf(t_print **lst, t_print *new);
void	ft_lstclear_pf(t_print **lst);
char	*ft_strcpy(char *dest, char *src);

#endif
