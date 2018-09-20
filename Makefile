# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: exabanis <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/22 09:43:25 by exabanis          #+#    #+#              #
#    Updated: 2018/08/12 07:40:21 by exabanis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=   libftprintf.a

CC          =   gcc

CFLAGS      =   -Wall -Werror -Wextra

INCLUDE		=   "\./includes/"

SRC			=   ft_printf.c\
				ft_convert.c\
                ft_dir.c\
                ft_flag_handle.c\
                ft_print_int.c\
                ft_print_u.c\
                ft_print_w.c\
                ft_uni.c

SRCL		=	$(addprefix libft/, \
				ft_strlen.c	ft_strlcat.c ft_itoa.c\
				ft_strdup.c ft_strndup.c ft_strcpy.c ft_strncpy.c ft_strnew.c\
				ft_strcat.c ft_strncat.c ft_strchr.c ft_strrchr.c ft_strstr.c\
				ft_strnstr.c ft_strjoin.c ft_strmap.c ft_strmapi.c ft_strsub.c\
				ft_strtrim.c ft_strsplit.c ft_atoi.c ft_isalpha.c ft_isdigit.c\
				ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_isupper.c\
				ft_tolower.c ft_islower.c ft_isspace.c ft_memcmp.c ft_strcmp.c\
				ft_strncmp.c ft_strequ.c ft_strnequ.c ft_bzero.c ft_memalloc.c\
				ft_memccpy.c ft_memchr.c ft_memcpy.c ft_memdel.c ft_memmove.c\
				ft_memset.c ft_strclr.c ft_strdel.c ft_striter.c ft_striteri.c\
				ft_putchar.c ft_putendl.c ft_putnbr.c ft_putstr.c ft_putchar_fd.c\
				ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c\
				)

OBJ			=   $(SRC:.c=.o)

OBJL		=	$(SRCL:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(OBJL)
	@ar -rc $(NAME) $(OBJ) $(OBJL)
	@ranlib $(NAME)
	@echo "\033[32mlibftprintf.a created.\033[0m"

$(OBJ): $(SRC)
	@make -C libft/
	@$(CC) $(CFLAGS) -c -I$(INCLUDE) $(SRC)
	@echo "\033[32mlibftprintf.a sources created.\033[0m"
	
clean:
	@make clean -C libft/
	@rm -f $(OBJ)
	@echo "\033[31mlibftprintf.a sources deleted.\033[0m"

fclean: clean
	@make fclean -C libft/
	@rm -f $(NAME)
	@echo "\033[31mlibftprintf.a deleted.\033[0m"

re: fclean all

.PHONY: all clean fclean re
