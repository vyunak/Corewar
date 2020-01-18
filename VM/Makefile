# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile corewar                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okaramel <3kayo4137@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 19:35:04 by okaramel          #+#    #+#              #
#    Updated: 2019/09/25 15:39:40 by dmatseku         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

SRC = main.c\
game_on.c\
flags.c\
get_champs_main.c\
get_champs_sub.c\
pub_carriage.c\
op_sub.c\
op_0103.c\
op_0408.c\
op_0911.c\
op_1216.c\

SRCDIR = ./srcs/
SRCO = $(addprefix $(SRCDIR), $(SRC:.c=.o))
FLAGS = -Wall -Wextra -Werror
FAST_FLAG = -Ofast
INCDIR = ./includes/
INCS = op.h vm.h
INC = $(addprefix $(INCDIR), $(INCS))
LIBDIR = $(addprefix $(SRCDIR), libft/)
LIBINC = $(addprefix $(LIBDIR), libft.h)
LIBFT = $(LIBDIR)libft.a
LIBGCOREWAR_DIR = ../libgcorewar/
LIBGCOREWAR_INCDIR = $(LIBGCOREWAR_DIR)include/
LIBGCOREWAR_INC = $(addprefix $(LIBGCOREWAR_INCDIR), libgcorewar.h)
LIBGCOREWAR = $(LIBGCOREWAR_DIR)libgcorewar.a
EXTERNAL_LIBDIRS = -L ~/libs/libglKH/ -L ~/libs/libmatrix -L ~/libs/libglstring -L ~/libs/glew/2.1.0/lib -L ~/libs/freetype/2.10.1/lib/
EXTERNAL_LIBS =  -framework CoreVideo -framework OpenGL -framework IOKit -framework Cocoa -framework Carbon ~/libs/glfw/3.3/lib/libglfw.3.3.dylib ~/libs/glew/2.1.0/lib/libGLEW.2.1.0.dylib -lglKH -lglstring -lmatrix -lfreetype 

all: $(NAME)

$(NAME): $(LIBGCOREWAR) $(LIBFT) $(SRCO) $(LIBINC) $(INC) $(LIBGCOREWAR_INC)
	gcc $(FLAGS) $(FAST_FLAG) -o $(NAME) $(SRCO) $(EXTERNAL_LIBDIRS) $(EXTERNAL_LIBS) -L $(LIBDIR) -lft -L $(LIBGCOREWAR_DIR) -lgcorewar -I $(INCDIR) -I $(LIBDIR) -I $(LIBGCOREWAR_INCDIR)

$(LIBFT):
	make -C $(LIBDIR)

$(LIBGCOREWAR):
	make -C $(LIBGCOREWAR_DIR)


$(SRCDIR)%.o: $(SRCDIR)%.c $(LIBINC) $(INC) -I $(LIBGCOREWAR_INC)
	gcc $(FLAGS) $(FAST_FLAG) -c -o $@ $< -I $(INCDIR) -I $(LIBDIR) -I $(LIBGCOREWAR_INCDIR)

clean:
	make -C $(LIBDIR) clean
	make -C $(LIBGCOREWAR_DIR) clean
	/bin/rm -f $(SRCO)

fclean: clean
	make -C $(LIBDIR) fclean
	make -C $(LIBGCOREWAR_DIR) fclean
	/bin/rm -f $(NAME)

re: fclean all
