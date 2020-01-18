/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 17:37:11 by vyunak            #+#    #+#             */
/*   Updated: 2019/08/21 17:58:30 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include <stdio.h>
# include <fcntl.h>
# include "op.h"
# include "../libft/libft.h"

void			writing_binary_code(t_data *d, t_files *tmp);
int				validator_marks(t_data *d);
void			out_in_file(int32_t nbr, int size, t_data *d);
void			write_name_comment(t_data *d);
void			write_code(t_data *d);
void			write_arg_in_file(t_data *d, t_while *head, char *arg);
int				print_error(char *type);
int				get_comment(char *str);
int				get_name(char *str);
void			check_argv(int ac, char **av);
int				ft_islabel(int c);
int				ft_strisalnum(char *str);
int				witoutnum(char *str);
int				white_space(char x);
int				ft_strislabel(char *str);
int				ft_strnslabel(char *str, int end);
int				st_end(char *c);
int				cw_strncmp(const char *s1, const char *s2);
int				valid_argv(char ***str);
int				len_comm(const char *str);
char			*write_arg(char **str);
int				vy_free_arr(char ***str);
void			create_new_oper(t_while **tmp);
void			parse_op_mark(char *line, int *x);
void			parse_op_mark_2(char *line, int *x);
void			parse_all(char *line);
char			*dell_comment(char **pst);
int				check_last_line(char *all, size_t ld);
int				check_end_line(char *str);
int				next_step_for_valid(char *line);
void			parse_op(char *line);
int				check_is_set(t_marks *mk, char *str);
void			create_new_mark(t_while **tmp);
void			write_mark(char *str);
int				command_check(char *line);
int				ft_arrlab(char **str);
int				calc_arg2(char *str, int l);
int				calc_arg3(char *str, int l);
int				calc(char *str, int l);
int				ft_isascii_wn(int c);
int				get_name_p2(int i[2], char *ln);
int				get_comment_p2(int i[2], char *ln);
void			all_free_while(t_while *ton2);
void			all_free(void);
void			file_struct_malloc(t_files **file);
char			*search_s(char *str);
int				stmark(char *c);

#endif
