# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/25 14:43:16 by dmatseku          #+#    #+#              #
#    Updated: 2019/09/25 16:37:35 by ashypilo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgcorewar.a

SRC = init/corewar_visual_init.c\
other/other.c\
init/init_set_drawable_elems.c\
init/frame/create_frame_vao.c\
init/shaders/frame_shaders.c\
init/frame/create_frame_shader_program.c\
draw/draw.c\
init/str_step_counter/str_step_counter_draw_init.c\
init/str_champions/str_champions_create.c\
init/str_champions/str_champions_draw_init.c\
init/create_pictures/create_picture_carriage.c\
init/carriages/create_carriage_vao.c\
draw/carriage_draw.c\
init/str_map/str_map_create.c\
other/other_2.c\
init/str_map/str_map_draw_function.c\
step/corewar_visual_step.c\
step/update_map.c\
draw/step_draw.c\
step/str_step_carriage.c\
init/carriages/create_carriage.c\
other/other_3.c draw/frame_draw.c\
init/static_string_animation_init/static_string_animation_init.c\
init/str_xlogins/str_xlogins_create.c\
init/lines/lines.c\
draw/lines_draw.c\
init/create_pictures/create_picture_x.c\
init/x/create_x_vao.c\
init/x/create_x.c\
init/shaders/x_shaders.c\
init/x/create_x_shader_program.c\
draw/x_draw.c\
t_carriage_list/carriage_list_update.c\
t_carriage_list/carriage_list_add.c\
t_carriage_list/carriage_list_del.c\
init/str_counters/str_counters_create.c\
step/step_x.c\
destroy/corewar_visual_destroy.c\
keys/key_left_right.c\
keys/key_escape.c\
keys/key_space.c\
keys/key_shift.c\
destroy/string_animation_destroy.c\
draw/destroy_draw.c\
destroy/string_winner_animation_init.c\
t_carriage_list/carriage_list_update_module.c

SRCDIR = ./
SRCO = $(addprefix $(SRCDIR), $(SRC:.c=.o))
FLAGS = -Wall -Wextra -Werror
INCDIR = ./include/
INC = $(addprefix $(INCDIR), libgcorewar.h)
FAST_FLAG = -Ofast
INC_KEYS_DIR = ./keys/
INC_LIBGLKH_DIR = ~/libs/libglKH/includes/
INC_LIBGLSTRING_DIR = ~/libs/libglstring/includes/
INC_LIBMATRIX_DIR = ~/libs/libmatrix/includes/
INC_FREETYPE_DIR = ~/libs/freetype/2.10.1/include/freetype2/
INC_GLEW_DIR = ~/libs/glew/2.1.0/include/
INC_GLFW_DIR = ~/libs/glfw/3.3/include/

INC_KEYS = $(addprefix $(INC_KEYS_DIR), keys.h)
INC_LIBGLKH = $(addprefix $(INC_LIBGLKH_DIR), libglKH.h)
INC_LIBGLSTRING = $(addprefix $(INC_LIBGLSTRING_DIR), libglstring.h)
INC_LGS = $(addprefix $(INC_LIBGLSTRING_DIR), lgs.h)
INC_LIBMATRIX = $(addprefix $(INC_LIBMATRIX_DIR), libmatrix.h)
INC_GLEW = $(addprefix $(INC_GLEW_DIR), GL/glew.h)
INC_GLFW = $(addprefix $(INC_GLFW_DIR), GLFW/glfw3.h)

all: $(NAME)

$(NAME): $(SRCO) $(INC) $(INC_KEYS) $(INC_LIBGLKH) $(INC_LIBGLSTRING) $(INC_LGS) $(INC_LIBMATRIX) $(INC_GLEW) $(INC_GLFW)
	ar rc $(NAME) $(SRCO)
#	gcc $(FLAGS) $(FAST_FLAG) -o $(NAME) $(SRCO)-I $(INCDIR)

$(SRCDIR)%.o: $(SRCDIR)%.c $(INC) $(INC_KEYS) $(INC_LIBGLKH) $(INC_LIBGLSTRING) $(INC_LGS) $(INC_LIBMATRIX) $(INC_GLEW) $(INC_GLFW)
	gcc $(FLAGS) $(FAST_FLAG) -c -o $@ $< -I $(INCDIR) -I $(INC_KEYS_DIR) -I $(INC_LIBGLKH_DIR) -I $(INC_LIBGLSTRING_DIR) -I $(INC_LIBMATRIX_DIR) -I $(INC_GLEW_DIR) -I $(INC_GLFW_DIR) -I $(INC_FREETYPE_DIR)

clean:
	/bin/rm -f $(SRCO)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all


.PHONY: clean fclean all re
