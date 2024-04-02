# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jteste <jteste@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 11:42:35 by jteste            #+#    #+#              #
#    Updated: 2024/04/02 18:21:55 by jteste           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a

NAME        := libftprintf.a
CC        := gcc
FLAGS    := -Wall -Wextra -Werror -g

SRCS        :=	ft_printf.c \
				ft_itoa_unsigned.c \
				ft_itoa_ptr.c \
				ft_itoa_hex.c \
				ft_itoa_hex_low.c \
				ft_lst_printf.c \
				ft_s.c \
				ft_p.c
				
                          
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
	@$(MAKE) -s bonus -C ./libft
	@cp $(LIBFT) $(NAME)
	@ar -rcs $(NAME) $(OBJS)
	@echo "$(YELLOW)$(NAME) $(GREEN)Created succesfully $(CLR_RMV)"


all:		${NAME}

clean:
	@rm -f $(OBJS)
	@echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
	@$(MAKE) --no-print-directory -C ./libft clean

fclean:
	@rm -f $(NAME)
	@echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
	@$(MAKE) --no-print-directory -C ./libft fclean

re:			fclean all

.PHONY:		all clean fclean re


