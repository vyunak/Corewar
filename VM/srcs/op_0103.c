/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_0103.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaramel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:42:03 by okaramel          #+#    #+#             */
/*   Updated: 2019/09/12 17:42:08 by okaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void			op_live(t_arena **pub, t_carriage **barman)
{
	int_fast32_t	arg;

	(*barman)->cylive = 0;
	(*pub)->sumlive++;
	arg = get_arg(*pub, CM((*barman)->posit + 1), 4);
	(g_flags[2][0] && g_flags[2][1] & 4) ? ft_printf("%d\n", arg) : 0;
	if (arg >= g_pamount * (-1) && arg < 0)
	{
		if (g_flags[2][0] && g_flags[2][1] & 1)
			ft_printf("Player %d (%s) is said to be alive\n", arg * (-1),
			g_mate[(arg + 1) * (-1)]->name);
		(*pub)->lastlive = arg;
	}
}

void			op_ld(t_arena **pub, t_carriage **barman)
{
	int_fast32_t	arg;
	uint_fast8_t	ix;

	arg = get_arg(*pub, ((*barman)->typarg[0] == 2) ?
	CM((*barman)->posit + 2) : CM((*barman)->posit +
	IM(get_arg(*pub, CM((*barman)->posit + 2), 2))), 4);
	ix = get_arg(*pub, ((*barman)->typarg[0] == 2) ? CM((*barman)->posit + 6)
	: CM((*barman)->posit + 4), 1) - 1;
	(*barman)->reg[ix] = arg;
	(*barman)->carry = (!arg) ? 1 : 0;
	(g_flags[2][0] && g_flags[2][1] & 4) ?
	ft_printf("%d r%d\n", arg, (uint_fast8_t)(ix + 1)) : 0;
}

void			op_st(t_arena **pub, t_carriage **barman)
{
	int_fast32_t	arg;
	uint_fast32_t	ix;

	arg = get_arg(*pub, CM((*barman)->posit + 2), 1) - 1;
	if ((*barman)->typarg[1] == 1)
	{
		ix = get_arg(*pub, CM((*barman)->posit + 3), 1) - 1;
		(g_flags[2][0] && g_flags[2][1] & 4) ?
		ft_printf("r%d %d\n", arg + 1, ix + 1) : 0;
		(*barman)->reg[ix] = (*barman)->reg[arg];
	}
	else
	{
		ix = CM((*barman)->posit + IM(get_arg(*pub,
		CM((*barman)->posit + 3), 2)));
		(g_flags[2][0] && g_flags[2][1] & 4) ? ft_printf("r%d %d\n",
		arg + 1, get_arg(*pub, CM((*barman)->posit + 3), 2)) : 0;
		set_arg(pub, ix, (*barman)->reg[arg]);
		new_owner(pub, ix, ix + 4, (*barman)->player);
	}
}
