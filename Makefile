#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yguzman <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            # #    Created: 2016/07/18 11:38:09 by yguzman           #+#    #+#              #
#    Updated: 2017/12/28 15:04:48 by jcoutare         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC			=		clang

NAME		=		./lem-in

DIR_SRC		=		./src/

SRCS		=		$(DIR_SRC)main.c					\
					$(DIR_SRC)read_and_fill.c			\
					$(DIR_SRC)check_line.c				\
					$(DIR_SRC)create_cpy_file.c			\
					$(DIR_SRC)pars_data.c				\
					$(DIR_SRC)pars_data1.c				\
					$(DIR_SRC)ant_ant.c					\
					$(DIR_SRC)ft_list_size.c					\
					$(DIR_SRC)fill_data.c				\
					$(DIR_SRC)algo.c					\
					$(DIR_SRC)tools.c					\
					$(DIR_SRC)algo_list.c				\
					$(DIR_SRC)ft_list_cpy.c				\
				

OBJS		=		$(SRCS:.c=.o)

CFLAGS		+=		-Iinclude
CFLAGS		+=		-Wall -Wextra -g -g3

RM			=		rm -f

LIB			=		./libft/libft.a

ECHO		=		printf

all			:		$(NAME)

$(NAME)		:		$(OBJS)
					@make -C libft 
					@$(ECHO) "\033[35m[~~~~COMPILATION PROJECT~~~~]\n\033[0m"
					@$(CC) -o $(NAME) -Llibft -lft -lncurses $(OBJS) && $(ECHO) "\033[33;32m["$@"]\n\033[0m" || $(ECHO) "\033[31m["$@"]\n\033[0m"

%.o			:		%.c
					@$(ECHO) "\033[35m[~~~Comipilation obj //project~~~]-->\033[0m"
					@$(CC) $(CFLAGS) -o $@ -c $< && $(ECHO) "\033[33;32m ["$@"]\n\033[0m" || $(ECHO) "\033[31m ["$@"]\n\033[0m"

clean_lib	:
					@make -C libft clean

clean		:		clean_lib
					@$(ECHO) "\033[31m[~~~~~~Supression des .o //project~~~~~~]\n\033[0m"
					@$(RM) $(OBJS)

fclean_lib	:
					@make -C libft fclean

fclean		:		fclean_lib
					@$(ECHO) "\033[31m[~~~~~~Supression des .o //project~~~~~~]\n\033[0m"
					@$(RM) $(OBJS)
					@$(ECHO) "\033[31m[~~~~Supression du Binaire~~~~]\n\033[0m"
					@$(RM) $(NAME)

re			:		fclean all

depend		:		$(SRCS)
					@makedepend -- -Yinclude/ -- $^ 2> /dev/null

.PHONY		:		all depend clean flean re

# DO NOT DELETE THIS LINE -- make depend depends on it.
