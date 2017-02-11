# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/30 16:48:59 by ryaoi             #+#    #+#              #
#    Updated: 2017/02/10 17:28:26 by ryaoi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell

DIR_LIB	= libft

LIBFT	= $(DIR_LIB)/libft.a

SRC		= additional_env.c \
		  exec_bin.c \
		  exec_cd.c \
		  exec_echo.c \
		  exec_env.c \
		  exec_setenv.c \
		  exec_unsetenv.c \
		  ft_check.c \
		  ft_cmds.c \
		  ft_env.c \
		  ft_free.c \
		  getquote.c \
		  init_msh.c \
		  main.c \
		  read_stdin.c \
		  ft_envtostr.c \
		  ft_straddonei.c \
		  init_term.c \
		  handle_signal.c \
		  getquotezero.c

OBJ		= $(SRC:.c=.o)

INCLUDE	= -Iminishell.h \
		  -I./libft/libft.h

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -I./$(INCLUDE) -o $@ -c $<

$(LIBFT):
	make -C $(DIR_LIB)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) ./libft/libft.a $(OBJ) $(INCLUDE) -ltermcap

clean:
	make clean -C $(DIR_LIB)
	rm -rf $(OBJ)

fclean: clean
	make fclean -C $(DIR_LIB)
	rm -rf $(NAME)

re: fclean all
