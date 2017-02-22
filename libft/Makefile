# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 14:11:33 by ryaoi             #+#    #+#              #
#    Updated: 2017/02/22 00:48:29 by ryaoi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRC		= ./ft_atoi.c \
		  ./ft_bzero.c \
		  ./ft_isalnum.c \
		  ./ft_isalpha.c \
		  ./ft_isascii.c \
		  ./ft_isdigit.c \
		  ./ft_isprint.c \
		  ./ft_itoa.c \
		  ./ft_memalloc.c \
		  ./ft_memccpy.c \
		  ./ft_memchr.c \
		  ./ft_memcmp.c \
		  ./ft_memcpy.c \
		  ./ft_memdel.c \
		  ./ft_memmove.c \
		  ./ft_memset.c \
		  ./ft_putchar.c \
		  ./ft_putchar_fd.c \
		  ./ft_putendl.c \
		  ./ft_putendl_fd.c \
		  ./ft_putnbr.c \
		  ./ft_putnbr_fd.c \
		  ./ft_putstr.c \
		  ./ft_putstr_fd.c \
		  ./ft_strcat.c \
		  ./ft_strchr.c \
		  ./ft_strclr.c \
		  ./ft_strcmp.c \
		  ./ft_strcpy.c \
		  ./ft_strdel.c \
		  ./ft_strdup.c \
		  ./ft_strequ.c \
		  ./ft_striter.c \
		  ./ft_striteri.c \
		  ./ft_strjoin.c \
		  ./ft_strlcat.c \
		  ./ft_strlen.c \
		  ./ft_strmap.c \
          ./ft_strmapi.c \
          ./ft_strncat.c \
          ./ft_strncmp.c \
          ./ft_strncpy.c \
          ./ft_strnequ.c \
          ./ft_strnew.c \
          ./ft_strnstr.c \
          ./ft_strrchr.c \
          ./ft_strsplit.c \
          ./ft_strstr.c \
          ./ft_strsub.c \
          ./ft_strtrim.c \
          ./ft_tolower.c \
          ./ft_toupper.c \
		  ./ft_lstnew.c \
		  ./ft_lstdelone.c \
		  ./ft_lstdel.c \
		  ./ft_lstadd.c \
		  ./ft_lstiter.c \
		  ./ft_lstmap.c \
		  ./get_next_line.c \
		  ./add_prefix.c \
		  ./add_prefix_add.c \
		  ./ft_check_dec.c \
		  ./ft_check_hex.c \
		  ./ft_check_oct.c \
		  ./ft_count_digit_base.c \
		  ./ft_hhtoa_base.c \
		  ./ft_htoa_base.c \
		  ./ft_init_pf.c \
		  ./ft_itoa_base.c \
		  ./ft_lltoa_base.c \
		  ./ft_ltoa_base.c \
		  ./ft_printf.c \
		  ./ft_printf_c.c \
		  ./ft_printf_capc.c \
		  ./ft_printf_capd.c \
		  ./ft_printf_capo.c \
		  ./ft_printf_caps.c \
		  ./ft_printf_capu.c \
		  ./ft_printf_capx.c \
		  ./ft_printf_d.c \
		  ./ft_printf_d_add.c \
		  ./ft_printf_o.c \
		  ./ft_printf_p.c \
		  ./ft_printf_pourcent.c \
		  ./ft_printf_s.c \
		  ./ft_printf_s_add.c \
		  ./ft_printf_u.c \
		  ./ft_printf_unicode.c \
		  ./ft_printf_x.c \
		  ./ft_printfcheck.c \
		  ./ft_put_space.c \
		  ./ft_specifer.c \
		  ./ft_str_capitalize.c \
		  ./ft_stradjust.c \
		  ./ft_uhhtoa_base.c \
		  ./ft_uhtoa_base.c \
		  ./ft_uitoa_base.c \
		  ./ft_ulltoa_base.c \
		  ./ft_ultoa_base.c \
		  ./ft_wcharlen.c \
		  ./ft_wstrlen.c \
		  ./length_modifer.c \
		  ./only_pourcent.c \
		  ./ft_strjoini.c \
		  ./ft_strsubfree.c \
		  ./ft_countn.c \
		  ./ft_countspace.c \
		  ./ft_strerase.c \
		  ./ft_strerasef.c \
		  ./ft_strisalpha.c

OBJ		= $(SRC:.c=.o)

INCLUDE = libft.h

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

%.o:%.c 
	$(CC) $(CFLAGS) -I./$(INCLUDE) -o $@ -c $< 

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
