# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jteste <jteste@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 11:42:35 by jteste            #+#    #+#              #
#    Updated: 2024/04/02 18:20:25 by jteste           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := libft.a
CC        := gcc
FLAGS    := -Wall -Wextra -Werror 

SRCS        :=      ft_substr.c \
                          ft_calloc.c \
                          ft_putendl_fd.c \
                          ft_bzero.c \
                          ft_strncmp.c \
                          ft_isprint.c \
                          ft_putnbr_fd.c \
                          ft_isdigit.c \
                          ft_isascii.c \
                          ft_memcmp.c \
                          ft_putstr_fd.c \
                          ft_strlcat.c \
                          ft_strlen.c \
                          ft_strnstr.c \
                          ft_strjoin.c \
                          ft_memcpy.c \
                          ft_isalnum.c \
                          ft_toupper.c \
                          ft_memset.c \
                          ft_atoi.c \
                          ft_strlcpy.c \
                          ft_strdup.c \
                          ft_memmove.c \
                          ft_putchar_fd.c \
                          ft_isalpha.c \
                          ft_strchr.c \
                          ft_strrchr.c \
                          ft_memchr.c \
                          ft_tolower.c \
						  ft_strtrim.c \
						  ft_striteri.c \
						  ft_strmapi.c \
						  ft_itoa.c \
						  ft_split.c
                                    
OBJS        := $(SRCS:.c=.o)

.c.o:
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o}

CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

$(NAME): $(OBJS)
	@echo "Linking $@"
	@ar rc $(NAME) $(OBJS)
	@echo "$(YELLOW)$(NAME) $(GREEN)Created succesfully $(CLR_RMV)"


all:		${NAME}

bonus: $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@echo "$(YELLOW)$(NAME) $(GREEN)Created succesfully $(CLR_RMV)"


clean:
			@rm -f $(OBJS)
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️" 

fclean:		
			@rm -f $(NAME)
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re


