/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_0408.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaramel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:42:12 by okaramel          #+#    #+#             */
/*   Updated: 2019/09/12 17:42:16 by okaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void			op_add(t_arena **pub, t_carriage **barman)
{
	int_fast32_t	arg1;
	int_fast32_t	arg2;
	uint_fast8_t	ix1;
	uint_fast8_t	ix2;
	uint_fast8_t	ix3;

	ix1 = get_arg(*pub, CM((*barman)->posit + 2), 1) - 1;
	arg1 = (*barman)->reg[ix1];
	ix2 = get_arg(*pub, CM((*barman)->posit + 3), 1) - 1;
	arg2 = (*barman)->reg[ix2];
	ix3 = get_arg(*pub, CM((*barman)->posit + 4), 1) - 1;
	(g_flags[2][0] && g_flags[2][1] & 4) ?
	ft_printf("r%d r%d r%d\n", ix1 + 1, ix2 + 1, ix3 + 1) : 0;
	(*barman)->reg[ix3] = arg1 + arg2;
	(*barman)->carry = (!(arg1 + arg2)) ? 1 : 0;
}

void			op_sub(t_arena **pub, t_carriage **barman)
{
	int_fast32_t	arg1;
	int_fast32_t	arg2;
	uint_fast8_t	ix1;
	uint_fast8_t	ix2;
	uint_fast8_t	ix3;

	ix1 = get_arg(*pub, CM((*barman)->posit + 2), 1) - 1;
	arg1 = (*barman)->reg[ix1];
	ix2 = get_arg(*pub, CM((*barman)->posit + 3), 1) - 1;
	arg2 = (*barman)->reg[ix2];
	ix3 = get_arg(*pub, CM((*barman)->posit + 4), 1) - 1;
	(g_flags[2][0] && g_flags[2][1] & 4) ?
	ft_printf("r%d r%d r%d\n", ix1 + 1, ix2 + 1, ix3 + 1) : 0;
	(*barman)->reg[ix3] = arg1 - arg2;
	(*barman)->carry = (!(arg1 - arg2)) ? 1 : 0;
}

void			op_and(t_arena **pub, t_carriage **barman)
{
	int_fast32_t	arg1;
	int_fast32_t	arg2;
	uint_fast8_t	ix;

	arg1 = 0;
	arg2 = 0;
	if ((*barman)->typarg[0] == 1 && (ix = 1))
		arg1 = (*barman)->reg[get_arg(*pub, CM((*barman)->posit + 2), 1) - 1];
	else if ((*barman)->typarg[0] == 2 && (ix = 4))
		arg1 = get_arg(*pub, CM((*barman)->posit + 2), 4);
	else if ((*barman)->typarg[0] == 3 && (ix = 2))
		arg1 = get_arg(*pub, CM((*barman)->posit + 2), 2);
	if ((*barman)->typarg[1] == 1 && (ix += 1))
		arg2 = (*barman)->reg[get_arg(*pub, CM((*barman)->posit + 2 + ix -
		1), 1)];
	else if ((*barman)->typarg[1] == 2 && (ix += 4))
		arg2 = get_arg(*pub, CM((*barman)->posit + 2 + ix - 4), 4);
	else if ((*barman)->typarg[1] == 3 && (ix += 2))
		arg2 = get_arg(*pub, CM((*barman)->posit + 2 + ix - 2), 2);
	ix = get_arg(*pub, CM((*barman)->posit + 2 + ix), 1) - 1;
	(g_flags[2][0] && g_flags[2][1] & 4) ?
	ft_printf("%d %d r%d\n", arg1, arg2, ix + 1) : 0;
	(*barman)->reg[ix] = arg1 & arg2;
	(*barman)->carry = (!(arg1 & arg2)) ? 1 : 0;
}

void			op_or(t_arena **pub, t_carriage **barman)
{
	int_fast32_t	arg1;
	int_fast32_t	arg2;
	uint_fast8_t	ix;

	arg1 = 0;
	arg2 = 0;
	if ((*barman)->typarg[0] == 1 && (ix = 1))
		arg1 = (*barman)->reg[get_arg(*pub, CM((*barman)->posit + 2), 1) - 1];
	else if ((*barman)->typarg[0] == 2 && (ix = 4))
		arg1 = get_arg(*pub, CM((*barman)->posit + 2), 4);
	else if ((*barman)->typarg[0] == 3 && (ix = 2))
		arg1 = get_arg(*pub, CM((*barman)->posit + 2), 2);
	if ((*barman)->typarg[1] == 1 && (ix += 1))
		arg2 = (*barman)->reg[get_arg(*pub, CM((*barman)->posit + 2 + ix -
		1), 1) - 1];
	else if ((*barman)->typarg[1] == 2 && (ix += 4))
		arg2 = get_arg(*pub, CM((*barman)->posit + 2 + ix - 4), 4);
	else if ((*barman)->typarg[1] == 3 && (ix += 2))
		arg2 = get_arg(*pub, CM((*barman)->posit + 2 + ix - 2), 2);
	ix = get_arg(*pub, CM((*barman)->posit + 2 + ix), 1) - 1;
	(g_flags[2][0] && g_flags[2][1] & 4) ?
	ft_printf("%d %d r%d\n", arg1, arg2, ix + 1) : 0;
	(*barman)->reg[ix] = arg1 | arg2;
	(*barman)->carry = (!(arg1 | arg2)) ? 1 : 0;
}

void			op_xor(t_arena **pub, t_carriage **barman)
{
	int_fast32_t	arg1;
	int_fast32_t	arg2;
	uint_fast8_t	ix;

	arg1 = 0;
	arg2 = 0;
	if ((*barman)->typarg[0] == 1 && (ix = 1))
		arg1 = (*barman)->reg[get_arg(*pub, CM((*barman)->posit + 2), 1) - 1];
	else if ((*barman)->typarg[0] == 2 && (ix = 4))
		arg1 = get_arg(*pub, CM((*barman)->posit + 2), 4);
	else if ((*barman)->typarg[0] == 3 && (ix = 2))
		arg1 = get_arg(*pub, CM((*barman)->posit + 2), 2);
	if ((*barman)->typarg[1] == 1 && (ix += 1))
		arg2 = (*barman)->reg[get_arg(*pub, CM((*barman)->posit + 2 + ix -
			1), 1) - 1];
	else if ((*barman)->typarg[1] == 2 && (ix += 4))
		arg2 = get_arg(*pub, CM((*barman)->posit + 2 + ix - 4), 4);
	else if ((*barman)->typarg[1] == 3 && (ix += 2))
		arg2 = get_arg(*pub, CM((*barman)->posit + 2 + ix - 2), 2);
	ix = get_arg(*pub, CM((*barman)->posit + 2 + ix), 1) - 1;
	(g_flags[2][0] && g_flags[2][1] & 4) ?
	ft_printf("%d %d r%d\n", arg1, arg2, ix + 1) : 0;
	(*barman)->reg[ix] = arg1 ^ arg2;
	(*barman)->carry = (!(arg1 ^ arg2)) ? 1 : 0;
}
