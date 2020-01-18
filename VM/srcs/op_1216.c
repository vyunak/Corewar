/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_1216.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaramel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:42:29 by okaramel          #+#    #+#             */
/*   Updated: 2019/09/12 17:42:30 by okaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void			op_fork(t_arena **pub, t_carriage **barman)
{
	t_carriage		*start;
	uint_fast8_t	ix;

	start = *barman;
	while (start->prev)
		start = start->prev;
	start->prev = new_carriage();
	start->prev->id = ++g_id;
	start->prev->player = (*barman)->player;
	start->prev->cylive = (*barman)->cylive;
	start->prev->carry = (*barman)->carry;
	ix = -1;
	while (++ix < REG_NUMBER)
		start->prev->reg[ix] = (*barman)->reg[ix];
	(g_flags[2][0] && g_flags[2][1] & 4) ? ft_printf("%d (%d)\n", get_arg(*pub,
	CM((*barman)->posit + 1), 2), (*barman)->posit +
	IM(get_arg(*pub, CM((*barman)->posit + 1), 2))) : 0;
	start->prev->posit = CM((*barman)->posit +
	IM(get_arg(*pub, CM((*barman)->posit + 1), 2)));
	start->prev->next = start;
}

void			op_lld(t_arena **pub, t_carriage **barman)
{
	int_fast32_t	arg;
	uint_fast8_t	ix;

	arg = get_arg(*pub, ((*barman)->typarg[0] == 2) ?
	CM((*barman)->posit + 2) :
	CM((*barman)->posit + get_arg(*pub, CM((*barman)->posit + 2), 2)), 4);
	ix = get_arg(*pub, ((*barman)->typarg[0] == 2) ? CM((*barman)->posit + 6)
	: CM((*barman)->posit + 4), 1) - 1;
	(*barman)->reg[ix] = arg;
	(*barman)->carry = (!arg) ? 1 : 0;
	(g_flags[2][0] && g_flags[2][1] & 4) ?
	ft_printf("%d r%d\n", arg, (uint_fast8_t)(ix + 1)) : 0;
}

void			op_lldi(t_arena **pub, t_carriage **barman)
{
	int_fast32_t	arg1;
	int_fast32_t	arg2;
	uint_fast8_t	ix;

	arg1 = 0;
	arg2 = 0;
	if ((*barman)->typarg[0] == 1 && (ix = 1))
		arg1 = (*barman)->reg[get_arg(*pub, CM((*barman)->posit + 2), 1)
		- 1];
	else if ((*barman)->typarg[0] == 2 && (ix = 2))
		arg1 = get_arg(*pub, CM((*barman)->posit + 2), 2);
	else if ((*barman)->typarg[0] == 3 && (ix = 2))
		arg1 = get_arg(*pub, CM((*barman)->posit +
		IM(get_arg(*pub, CM((*barman)->posit + 2), 2))), 4);
	if ((*barman)->typarg[1] == 1 && (ix += 1))
		arg2 = (*barman)->reg[get_arg(*pub,
		CM((*barman)->posit + 2 + ix - 1), 1) - 1];
	else if ((*barman)->typarg[1] == 2 && (ix += 2))
		arg2 = get_arg(*pub, CM((*barman)->posit + 2 + ix - 2), 2);
	ix = get_arg(*pub, CM((*barman)->posit + 2 + ix), 1) - 1;
	(g_flags[2][0] && g_flags[2][1] & 4) ?
	ft_printf("%d %d r%d\n%7s| -> load from %d + %d = %d (with pc and mod %d)\n"
	, arg1, arg2, (uint_fast8_t)(ix + 1), " ", arg1, arg2, arg1 + arg2,
	arg1 + arg2 + (*barman)->posit) : 0;
	(*barman)->reg[ix] = get_arg(*pub, CM((*barman)->posit + arg1 + arg2), 4);
}

void			op_lfork(t_arena **pub, t_carriage **barman)
{
	t_carriage		*start;
	uint_fast8_t	ix;

	start = *barman;
	while (start->prev)
		start = start->prev;
	start->prev = new_carriage();
	start->prev->id = ++g_id;
	start->prev->player = (*barman)->player;
	start->prev->cylive = (*barman)->cylive;
	start->prev->carry = (*barman)->carry;
	ix = -1;
	while (++ix < REG_NUMBER)
		start->prev->reg[ix] = (*barman)->reg[ix];
	(g_flags[2][0] && g_flags[2][1] & 4) ? ft_printf("%d (%d)\n",
	get_arg(*pub, CM((*barman)->posit + 1), 2), (*barman)->posit +
	get_arg(*pub, CM((*barman)->posit + 1), 2)) : 0;
	start->prev->posit = CM((*barman)->posit +
	get_arg(*pub, CM((*barman)->posit + 1), 2));
	start->prev->next = start;
}

void			op_aff(t_arena **pub, t_carriage **barman)
{
	(g_flags[2][0] && g_flags[2][1] & 4) ? ft_printf("Aff: %c\n",
	(char)((*barman)->reg[get_arg(*pub, CM((*barman)->posit + 2), 1) - 1])) : 0;
}
