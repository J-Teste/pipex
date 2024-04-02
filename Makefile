# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jteste <jteste@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 11:42:35 by jteste            #+#    #+#              #
#    Updated: 2024/04/02 23:56:11 by jteste           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME		:= pipex
CFLAGS		:= -Wextra -Wall -Werror
FTPRINTF	:= ./printf

LIBS	:= $(FTPRINTF)/libftprintf.a
SRCS	:= 	pipex.c \
			utils.c \


OBJS	:= $(SRCS:.c=.o)
CC 		= gcc $(CFLAGS)

all: ftprintf $(NAME)

CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
GREEN_BG	:= \033[42m
YELLOW_UNDERLINE := \033[4;33m
RM		    := rm -f
	
ftprintf:
	bash pipex.sh
	@$(MAKE) --no-print-directory -C $(FTPRINTF)

$(NAME): $(SRCS) $(OBJS)
	@$(CC) $(OBJS) $(LIBS) -o $(NAME)
	@echo "\n $(YELLOW)$(NAME) $(GREEN)Created succesfully \n$(CLR_RMV)"
	@echo "$(GREEN)$(YELLOW_UNDERLINE)Usage: ./pipex infile cmd1 cmd2 outfile\n$(CLR_RMV)"
	
	

clean:
	@rm -f $(OBJS)
	@echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
	@$(MAKE) --no-print-directory -C $(FTPRINTF) clean

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
	@$(MAKE) --no-print-directory -C $(FTPRINTF) fclean


re: clean all

.PHONY: all, clean, fclean, re
