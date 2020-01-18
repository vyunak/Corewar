/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 17:01:57 by vyunak            #+#    #+#             */
/*   Updated: 2019/08/21 17:46:02 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				(4*1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define COMMENT_CHAR			'#'
# define ALT_COMMENT_CHAR       ';'
# define LABEL_CHAR				':'
# define DIRECT_CHAR				'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define CHAMPNAME				".name"
# define CAMPCOMMENT			".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA				50
# define NBR_LIVE				21
# define MAX_CHECKS				10

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8
# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef struct					s_header
{
	unsigned int				magic;
	char						prog_name[PROG_NAME_LENGTH + 1];
	unsigned int				prog_size;
	char						comment[COMMENT_LENGTH + 1];
}								t_header;

typedef struct					s_argc
{
	int							arg1;
	int							arg2;
	int							arg3;
}								t_argc;

typedef struct					s_op
{
	char						*op;
	int							x;
	struct s_argc				ac;
	int							num_op;
	int							cycle;
	char						*desc;
	int							carry;
	int							code_ar;
	int							size_dir;
}								t_op;

typedef struct					s_oper
{
	char						*name;
	char						*av1;
	char						*av2;
	char						*av3;
	int							num;
}								t_oper;

typedef struct					s_marks
{
	char						*mark;
	struct s_marks				*next;
}								t_marks;

typedef struct					s_while
{
	struct s_marks				*marks;
	struct s_oper				*oper;
	struct s_while				*next;
	struct s_while				*prev;
	int							size;
}								t_while;

typedef struct					s_files
{

	char						*name;
	char						*name_og;
	int							ok;
	int							fd;
	struct s_files				*next;
}								t_files;

typedef struct					s_data
{
	char						*binary_code;
	char						*end_file;
	char						*num;
	int							fd;
	int							name;
	char						*cp_name;
	char						*cp_comment;
	int							space;
	int							comment;
	int							metk;
	int							oper;
	int							nline;
	int							i;
	int							x;
	int							d;
	int							h;
	int							l;
	int							o;
	int							p;
	int							error;
	t_while						*head;
	t_while						*list;
}								t_data;

t_op							g_op_tab[17];
t_data							g_data;
t_argc							g_calc_op[9];
t_files							*g_files;

#endif
