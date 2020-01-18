/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaramel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by okaramel          #+#    #+#             */
/*   Updated: 2013/11/06 14:21:46 by okaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdint.h>
# include <errno.h>
# include "op.h"
# include "../srcs/libft/libft.h"

# define CM(x) ((x) % MEM_SIZE)
# define IM(x) ((x) % IDX_MOD)

int						g_error;
int						g_pamount;
int						g_id;
int						g_flags[8][2];

typedef _Bool			t_bool;

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
	t_bool				alive;
	int					cylive;
	uint_fast8_t		exec;
	unsigned int		cyexec;
	char				typarg[3];
	unsigned int		posit;
	unsigned int		amskip;
	t_bool				carry;
	int_fast32_t		reg[REG_NUMBER];
	struct s_carriage	*next;
	struct s_carriage	*prev;
}						t_carriage;

typedef struct			s_op
{
	char				*name;
	char				ac;
	unsigned int		arg[3];
	char				id;
	unsigned int		cyexec;
	char				*comm;
	t_bool				typarg;
	t_bool				adir;
}						t_op;

t_champ					**g_mate;
static t_op				g_optab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "substraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

void					*error_msg(int mode);
int						out_arena(t_arena *pub, unsigned int len);

void					print_usage(void);
int						parse_flags(char **av);
void					player_order(void);

int						check_magic(int fd);
int						check_null(int fd);
char					*read_name(int fd);
int						read_size(int fd);
char					*read_comment(int fd);
uint_fast8_t			*read_execute(int fd, size_t size);
t_champ					*new_champ(void);
t_champ					*read_champ(char *name);
t_champ					**make_buddies(int ac, char **av);

t_arena					*find_pub(void);
t_carriage				*new_carriage(void);
t_carriage				*put_carriage(t_arena **pub, t_champ *mate);
t_carriage				*gentlemen_meeting(t_arena **pub, t_champ **mate);
int						del_carriage(t_arena **pub, t_carriage **barman);

int_fast32_t			get_arg(t_arena *pub, uint_fast32_t posit,
								uint_fast8_t size);
void					set_arg(t_arena **pub, uint_fast32_t posit,
								int_fast32_t arg);
char					code_to_siz(uint_fast8_t number, t_bool flag);
char					code_to_t(uint_fast8_t number);
int						check_reg(t_arena *pub, t_carriage **barman);
void					new_owner(t_arena **pub, int from, int to, char owner);

void					op_live(t_arena **pub, t_carriage **barman);
void					op_ld(t_arena **pub, t_carriage **barman);
void					op_st(t_arena **pub, t_carriage **barman);
void					op_add(t_arena **pub, t_carriage **barman);
void					op_sub(t_arena **pub, t_carriage **barman);
void					op_and(t_arena **pub, t_carriage **barman);
void					op_or(t_arena **pub, t_carriage **barman);
void					op_xor(t_arena **pub, t_carriage **barman);
void					op_zjmp(t_arena **pub, t_carriage **barman);
void					op_ldi(t_arena **pub, t_carriage **barman);
void					op_sti(t_arena **pub, t_carriage **barman);
void					op_fork(t_arena **pub, t_carriage **barman);
void					op_lld(t_arena **pub, t_carriage **barman);
void					op_lldi(t_arena **pub, t_carriage **barman);
void					op_lfork(t_arena **pub, t_carriage **barman);
void					op_aff(t_arena **pub, t_carriage **barman);

int						valid_order(t_arena *pub, t_carriage **barman);
int						drink_it(t_arena **pub, t_carriage **barman);
void					slainte(t_arena **pub, t_carriage **barman);
int						take_order(t_arena **pub, t_carriage **barman);
void					the_talk(t_arena **pub, t_carriage **barman);

char					corewar_visual_init(t_champ const **champions,
											t_arena const *arena,
											t_carriage **carriages);
void					corewar_visual_step(t_arena const *arena,
											t_carriage **carriages);
void					corewar_visual_destroy(t_champ *champion);

#endif
