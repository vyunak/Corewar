# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 14:44:02 by vyunak            #+#    #+#              #
#    Updated: 2019/04/10 15:20:50 by vyunak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
FILENAME	=	ft_atoi\
				ft_bzero\
				ft_isalnum\
				ft_isalpha\
				ft_isascii\
				ft_isdigit\
				ft_islower\
				ft_isprint\
				ft_isupper\
				ft_itoa\
				ft_lstadd\
				ft_lstdel\
				ft_lstdelone\
				ft_lstiter\
				ft_lstmap\
				ft_lstnew\
				ft_memalloc\
				ft_memccpy\
				ft_memchr\
				ft_memcmp\
				ft_memcpy\
				ft_memdel\
				ft_memmove\
				ft_memset\
				ft_putchar\
				ft_putchar_fd\
				ft_putendl\
				ft_putendl_fd\
				ft_putnbr\
				ft_putnbr_fd\
				ft_putstr\
				ft_putstr_fd\
				ft_strcat\
				ft_strchr\
				ft_strclr\
				ft_strcmp\
				ft_strcpy\
				ft_strdel\
				ft_strdup\
				ft_strequ\
				ft_striter\
				ft_striteri\
				ft_strjoin\
				ft_strlcat\
				ft_strlen\
				ft_strmap\
				ft_strncat\
				ft_strncmp\
				ft_strncpy\
				ft_strnequ\
				ft_strnew\
				ft_strnstr\
				ft_strrchr\
				ft_strrev\
				ft_strsplit\
				ft_strstr\
				ft_strsub\
				ft_strtrim\
				ft_tolower\
				ft_toupper\
				ft_strmapi\
				ft_get_size\
				get_next_line\
				ft_printf\
				ft_printf_set\
				ft_printf_checker\
				type_c\
				type_f\
				type_f_2\
				ft_itoa\
				ft_lib_part_1\
				type_s\
				type_int\
				type_unsigned\
				ft_itoa_base\
				ft_atoi_base\
				type_o\
				type_x\
				ft_strndup
FLAGS		=	-Wall -Wextra -Werror -g
OBJECTS		=	$(FILENAME:=.o)
FILE		=	$(FILENAME:=.c)

all: $(NAME)

$(NAME): $(FILE)
	@clang -c $(FILE) $(FLAGS)
	@ar rc $(NAME) $(OBJECTS)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)
	@rm -f *.gch .DS_Store

test: fclean
	@gcc $(FILE) $(T).c -c
	@gcc $(OBJECTS) $(T).o -o $(NAME:.a=.libft) -g
	@rm -fr *.o
	@./$(NAME:.a=.libft)

re: fclean $(NAME)

.PHONY: clean fclean all re
