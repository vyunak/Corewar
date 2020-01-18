/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgcorewar.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 20:42:46 by dmatseku          #+#    #+#             */
/*   Updated: 2019/09/25 15:28:50 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGCOREWAR_H
# define LIBGCOREWAR_H

# define GLEW_STATIC
# define WINDOW_WIDTH 2400
# define WINDOW_HEIGHT 1250

# define M_W 0.35f

# define S_H 0.005f

# define S_1 0.75f
# define S_2 0.5f
# define S_3 -0.6f
# define S_4 -0.85f
# define S_5 -0.33f

# define STR_C_F 180

# define STR_S_FS 110

# define STR_I_FS 60

# define STR_CH_SS 0.08f
# define STR_CH_FS 120
# define STR_CH_ML 11

# define STR_M_RL 64
# define STR_M_FS 35

# define STR_D_FS 60

# define STR_CO_FS 40

# define CO_LD 10
# define CO_LW 100

# define XL_FS 37
# define XL_D -2

# define X_D 50

# define WI_FS 200

# define ME_C vec4(0.21568627451f, 0.21568627451f, 0.21568627451f, 0.0f)

# define SP_C vec4(0.28235294117f, 0.28235294117f, 0.28235294117f, 0.0f)

# define STR_ST_IT 1.5f
# define STR_ST_IDT 0.3f

# define X_T 0.3f

# define STR_CH_T 1.6f

# define FONT_PATH "./Oswald-Regular.ttf"

# define FR_C 6

# define FU_SC 3

# define STR_S_T 1.0f

# define MEM_SIZE 4096

# define REG_NUMBER 16

# define DELTA_STEP 0.01f

# include <GL/glew.h>
# include <GLFW/glfw3.h>
# include <libmatrix.h>
# include <libglstring.h>
# include <lgs.h>
# include <stdio.h>
# include <stdint.h>

typedef unsigned int	t_uint;

typedef struct			s_line
{
	GLuint				vao;
	GLuint				vbo;
	t_vec4				color;
}						t_line;

typedef struct			s_champ
{
	char				id;
	char				*name;
	unsigned int		size;
	char				*comm;
	uint_fast8_t		*exec;
}						t_champ;

typedef struct			s_arena
{
	int					iter[2];
	unsigned int		check;
	int					cydeath;
	unsigned int		sumlive;
	char				lastlive;
	unsigned int		survived;
	uint_fast8_t		owner[MEM_SIZE];
	uint_fast8_t		cell[MEM_SIZE];
}						t_arena;

typedef struct			s_carriage
{
	unsigned int		id;
	char				player;
	char				alive;
	int					cylive;
	uint_fast8_t		exec;
	unsigned int		cyexec;
	char				typarg[3];
	unsigned int		posit;
	unsigned int		amskip;
	char				carry;
	int_fast32_t		reg[REG_NUMBER];
	struct s_carriage	*next;
	struct s_carriage	*prev;
}						t_carriage;

typedef struct			s_v_x
{
	t_mat4				model;
	GLuint				vao;
	GLuint				vbo;
	GLuint				ebo;
	GLuint				picture;
	char				draw;
	char				init;
	char				position;
	t_vec4				color;
}						t_v_x;

typedef struct			s_v_carriage
{
	GLuint				picture;
	t_mat4				model;
	GLuint				vao;
	GLuint				vbo;
	GLuint				ebo;
}						t_v_carriage;

typedef struct			s_carr_lst
{
	unsigned int		id;
	char				player;
	int					position;
	int					prev_position;
	char				alive;
	float				x;
	float				y;
	float				prev_x;
	float				prev_y;
	struct s_carr_lst	*prev;
	struct s_carr_lst	*next;
}						t_carr_lst;

typedef struct			s_v_frame
{
	GLuint				vao;
	GLuint				vbo;
	GLuint				ebo;
	t_vec4				color;
}						t_v_frame;

typedef struct			s_create_frame_vao_args
{
	t_vec4				args;
	t_v_frame			*vao;
}						t_create_frame_vao_args;

void					(*g_update_map)(unsigned char const *map,
										unsigned char const *owner);
void					(*g_carriages_draw)(void);

t_string				*g_str_winner;

t_carr_lst				*g_carriage_lst;

t_string				*g_str_cyc_to_die_intro;

t_string				*g_str_speed_intro;

int						g_last_cyc_to_die;

t_string				*g_str_cyc_to_die;

t_string				*g_str_speed;

t_string				*g_str_dead;

t_string				*g_str_corewar;

unsigned char			*g_map;

t_string				**g_str_map;

float					g_map_opacity;

t_string				*g_str_step_counter;

t_string				*g_str_step;

GLuint					g_frame_shader_program;

GLuint					g_x_shader_program;

t_v_carriage			g_v_carriage;

size_t					g_carriage_width;

size_t					g_carriage_height;

t_v_frame				g_v_frame[FR_C];

GLFWwindow				*g_window;

int						g_w_width;

int						g_w_height;

char					g_number_of_champions;

t_string				**g_str_champions;

t_line					*g_lines;

t_string				*g_str_xlogins[4];

t_v_x					g_x;

unsigned int			*g_counts;

t_string				**g_counters;

char					g_hidden;

float					g_step_time;

char					g_pause;

size_t					my_strlen(char const *str);

void					exit_error(char *str);

GLchar const			*get_frame_shader_vert(void);

GLchar const			*get_frame_shader_frag(void);

void					create_frame_shader_program(void);

void					create_x_shader_program(void);

void					create_frame_vao(t_create_frame_vao_args args);

void					init_set_drawable_elems(t_champ const **champions,
								t_arena const *arena, t_carriage **carriages);

void					draw_arena(void);

char					corewar_visual_init(t_champ const **champions,
							t_arena const *arena,
							t_carriage **carriages);

char					str_step_counter_draw_init(char init, double time);

char					str_champions_draw_init(char init, double time);

char					str_static_animation_init(char init, double time);

void					my_bzero(void *array, size_t size);

void					my_memset(void *array, int symbol, size_t size);

char					*my_uitoa(uintmax_t n);

void					my_base(unsigned char nb, char *str);

void					my_memcpy(void *src, void const *dst, size_t len);

void					my_strncat(char *str1, char const *str2, size_t n);

void					str_champions_create(t_champ const **champions);

GLuint					create_picture_carriege(size_t width, size_t height,
											size_t frame_length);

GLuint					create_picture_x(size_t width);

void					create_carriage_vao(size_t width, size_t height);

void					create_x_vao(size_t width);

GLchar const			*get_x_shader_vert(void);

GLchar const			*get_x_shader_frag(void);

void					carriages_draw(void);

void					non_carriages_draw(void);

void					frames_draw(void);

void					lines_draw(void);

void					x_draw(void);

void					str_map_create(unsigned char const *map,
										unsigned char const *owner);

void					*str_map_draw_function(t_string const *string,
														void *param);

void					update_map(unsigned char const *map,
										unsigned char const *owner);

void					non_update_map(unsigned char const *map,
										unsigned char const *owner);

size_t					math_length(void);

void					corewar_visual_step(t_arena const *arena,
							t_carriage **carriages);

void					create_carriage(void);

char					str_step_carriage(char init, double time);

void					step_draw(char new_position);

void					str_xlogins_create(void);

void					create_line_vao(int index, float x, float y,
															int width);

void					create_x(void);

void					carriage_list_add(t_carr_lst **lst, t_carr_lst *elem);

void					carriage_list_del(t_carr_lst **lst, t_carr_lst *elem);

void					carriage_list_update(t_carriage **carriages);

void					create_elem(t_carriage const *carriage);

void					free_carriage(t_carriage *del);

void					free_first_carriage(t_carriage **elem);

void					str_counters_create(void);

char					x_step(double time, char init, char new_position);

void					corewar_visual_destroy(t_champ *champion);

char					str_static_animation_destroy(char init, double time);

void					destroy_draw(void);

char					string_winner_animation_init(char init, double time);

#endif
