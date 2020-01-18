# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ashypilo <ashypilo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/30 13:34:20 by vyunak            #+#    #+#              #
#    Updated: 2019/09/25 16:35:29 by ashypilo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../asm

SRC =	cwa_lib_p1.c          main.c                validator_marks.c\
		cwa_lib_p2.c          op.c                  write_arg_in_file.c\
		format_parse_agv.c    write_code.c			format_valid_arg.c\
		parse_format_dell.c   write_name_comment.c	valid_parse_2_arv.c\
		writing_binary_code.c main_p2.c
SRCDIR = ./src/
LIBDIR = ./libft/
RWDIR = ./libft/
SRCO = $(addprefix $(SRCDIR), $(SRC:.c=.o))
WWE = -Wall -Wextra -Werror -g
O = N
FAST_FLAG = -Ofast
INCDIR = ./src/
INC = $(addprefix $(INCDIR), functions.h)
INC2 = $(addprefix $(INCDIR), op.h)
LIBINC = $(addprefix $(LIBDIR), libft.h)
LIBFT = $(LIBDIR)libft.a

all: $(NAME)

ifeq ($(O),O)
$(NAME): $(LIBFT) $(SRCO) $(LIBINC) $(INC) $(INC2)
	gcc $(WWE) $(FAST_FLAG) -o $(NAME) $(SRCO) -L $(LIBDIR) -lft  -I $(INCDIR) -I $(LIBDIR)

$(LIBFT):
	make -C $(LIBDIR) O=O

$(SRCDIR)%.o: $(SRCDIR)%.c $(LIBINC) $(INC) $(INC2)
	gcc $(WWE) $(FAST_FLAG) -c -o $@ $<  -I $(INCDIR) -I $(LIBDIR)
else
$(NAME): $(LIBFT) $(SRCO) $(LIBINC) $(INC) $(INC2)
	gcc $(WWE) -o $(NAME) $(SRCO) -L $(LIBDIR) -lft -I $(INCDIR) -I $(LIBDIR)

$(LIBFT):
	make -C $(LIBDIR)

$(SRCDIR)%.o: $(SRCDIR)%.c $(LIBINC) $(INC) $(INC2)
	gcc $(WWE) -c -o $@ $< -I $(INCDIR) -I $(LIBDIR)
endif

clean:
	make -C $(LIBDIR) clean
	/bin/rm -f $(SRCO)

fclean: clean
	make -C $(LIBDIR) fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
