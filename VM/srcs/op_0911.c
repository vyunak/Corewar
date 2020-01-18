/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_0911.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaramel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:42:21 by okaramel          #+#    #+#             */
/*   Updated: 2019/09/12 17:42:22 by okaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void			op_zjmp(t_arena **pub, t_carriage **barman)
{
	int_fast32_t	arg;

	arg = CM((*barman)->posit +
	IM(get_arg(*pub, CM((*barman)->posit + 1), 2)));
	(g_flags[2][0] && g_flags[2][1] & 4) ? ft_printf("%d ", get_arg(*pub,
		CM((*barman)->posit + 1), 2)) : 0;
	if ((*barman)->carry)
	{
		(g_flags[2][0] && g_flags[2][1] & 4) ? ft_printf("OK\n") : 0;
		(*barman)->posit = arg;
		new_owner(pub, (*barman)->posit, (*barman)->posit +
		(*barman)->amskip, (*barman)->player);
		(*barman)->amskip = 0;
	}
	else
		(g_flags[2][0] && g_flags[2][1] & 4) ? ft_printf("FAILED\n") : 0;
}

void			op_ldi(t_arena **pub, t_carriage **barman)
{
	int_fast32_t	a[2];
	uint_fast8_t	ix;

	a[0] = 0;
	a[1] = 0;
	if ((*barman)->typarg[0] == 1 && (ix = 1))
		a[0] = (*barman)->reg[get_arg(*pub, CM((*barman)->posit + 2), 1) - 1];
	else if ((*barman)->typarg[0] == 2 && (ix = 2))
		a[0] = get_arg(*pub, CM((*barman)->posit + 2), 2);
	else if ((*barman)->typarg[0] == 3 && (ix = 2))
		a[0] = get_arg(*pub, CM((*barman)->posit +
		IM(get_arg(*pub, CM((*barman)->posit + 2), 2))), 4);
	if ((*barman)->typarg[1] == 1 && (ix += 1))
		a[1] = (*barman)->reg[get_arg(*pub,
		CM((*barman)->posit + 2 + ix - 1), 1) - 1];
	else if ((*barman)->typarg[1] == 2 && (ix += 2))
		a[1] = get_arg(*pub, CM((*barman)->posit + 2 + ix - 2), 2);
	ix = get_arg(*pub, CM((*barman)->posit + 2 + ix), 1) - 1;
	(g_flags[2][0] && g_flags[2][1] & 4) ?
	ft_printf("%d %d r%d\n%7s| -> load from %d + %d = %d (with pc and mod %d)\n"
	, a[0], a[1], (uint_fast8_t)(ix + 1), " ", a[0], a[1], a[0] + a[1],
	IM(a[0] + a[1]) + (*barman)->posit) : 0;
	(*barman)->reg[ix] = get_arg(*pub, CM((*barman)->posit +
	IM(a[0] + a[1])), 4);
}

void			op_sti(t_arena **pub, t_carriage **barman)
{
	int_fast32_t	a[2];
	uint_fast8_t	ix;

	a[0] = 0;
	a[1] = 0;
	if ((*barman)->typarg[1] == 1 && (ix = 1))
		a[0] = (*barman)->reg[get_arg(*pub, CM((*barman)->posit + 3), 1) - 1];
	else if ((*barman)->typarg[1] == 2 && (ix = 2))
		a[0] = get_arg(*pub, CM((*barman)->posit + 3), 2);
	else if ((*barman)->typarg[1] == 3 && (ix = 2))
		a[0] = get_arg(*pub, CM((*barman)->posit +
		IM(get_arg(*pub, CM((*barman)->posit + 3), 2))), 4);
	if ((*barman)->typarg[2] == 1 && (ix += 1))
		a[1] = (*barman)->reg[get_arg(*pub,
		CM((*barman)->posit + 3 + ix - 1), 1) - 1];
	else if ((*barman)->typarg[2] == 2 && (ix += 2))
		a[1] = get_arg(*pub, CM((*barman)->posit + 3 + ix - 2), 2);
	(g_flags[2][0] && g_flags[2][1] & 4) ?
	ft_printf("r%d %d %d\n%7s| -> store to %d + %d = %d (with pc and mod %d)\n",
	get_arg(*pub, CM((*barman)->posit + 2), 1), a[0], a[1], " ", a[0], a[1],
	a[0] + a[1], IM(a[0] + a[1]) + (*barman)->posit) : 0;
	set_arg(pub, CM((*barman)->posit + IM(a[0] + a[1])),
	(*barman)->reg[get_arg(*pub, CM((*barman)->posit + 2), 1) - 1]);
	new_owner(pub, CM((*barman)->posit + IM(a[0] + a[1])),
	CM((*barman)->posit + IM(a[0] + a[1])) + 4, (*barman)->player);
}
