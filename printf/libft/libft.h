/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 09:35:12 by jteste            #+#    #+#             */
/*   Updated: 2024/02/13 13:01:00 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include "./printf.h"

int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
void		*ft_memcpy(void *destination, const void *source, size_t size);
void		ft_bzero(void *s, size_t n);
void		*ft_memmove(void *destination, const void *source, size_t size);
void		*ft_memset( void *ptr, int value, size_t count);
char		*ft_strchr(const char *str, int tofind);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strrchr(const char *str, int tofind);
int			ft_tolower(int c);
int			ft_toupper(int c);
void		*ft_memchr(const void *memory, int tofind, size_t size);
int			ft_memcmp(const void *ptr1, const void *ptr2, size_t size);
char		*ft_strnstr(const char *str, const char *tofind, size_t len);
long long	ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putendl_fd(char *s, int fd);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *src);
char		*ft_strtrim(char const *s1, char const *set);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_itoa(int n);
char		**ft_split(char const *s, char c);

#endif