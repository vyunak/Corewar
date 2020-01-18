/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_on.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaramel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:22:05 by okaramel          #+#    #+#             */
/*   Updated: 2019/09/25 14:52:23 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int				valid_order(t_arena *pub, t_carriage **barman)
{
	uint_fast8_t	i[3];

	ft_bzero(i, 3 * sizeof(uint_fast8_t));
	if (!g_optab[(*barman)->exec - 1].typarg)
		i[0] = DIR_CODE;
	else if ((i[0] = pub->cell[CM((*barman)->posit + 1)] / 64 % 4) || !i[0])
		if ((i[1] = pub->cell[CM((*barman)->posit + 1)] / 16 % 4) || !i[1])
			i[2] = pub->cell[CM((*barman)->posit + 1)] / 4 % 4;
	(*barman)->amskip = 1 + !!g_optab[(*barman)->exec - 1].typarg +
	code_to_siz(i[0], g_optab[(*barman)->exec - 1].adir) +
	code_to_siz(i[1], g_optab[(*barman)->exec - 1].adir) *
	(g_optab[(*barman)->exec - 1].ac > 1) +
	code_to_siz(i[2], g_optab[(*barman)->exec - 1].adir) *
	(g_optab[(*barman)->exec - 1].ac > 2);
	ft_memcpy((*barman)->typarg, i, 3 * sizeof(uint_fast8_t));
	if ((g_optab[(*barman)->exec - 1].ac == 1 && (!(code_to_t(i[0]) &
		g_optab[(*barman)->exec - 1].arg[0]))) || (g_optab[(*barman)->exec -
		1].ac == 2 && (!(code_to_t(i[0]) & g_optab[(*barman)->exec - 1].arg[0])
		|| !(code_to_t(i[1]) & g_optab[(*barman)->exec - 1].arg[1]))) ||
		(g_optab[(*barman)->exec - 1].ac == 3 && (!(code_to_t(i[0]) &
		g_optab[(*barman)->exec - 1].arg[0]) || !(code_to_t(i[1]) &
		g_optab[(*barman)->exec - 1].arg[1]) || !(code_to_t(i[2]) &
		g_optab[(*barman)->exec - 1].arg[2]))) || !check_reg(pub, barman))
		return (0);
	return (1);
}

int				drink_it(t_arena **pub, t_carriage **barman)
{
	((*barman)->exec != 16 && g_flags[2][0] && g_flags[2][1] & 4) ?
	ft_printf("P%5d | %s ", (*barman)->id,
	g_optab[(*barman)->exec - 1].name) : 0;
	((*barman)->exec == 1) ? op_live(pub, barman) : 0;
	((*barman)->exec == 2) ? op_ld(pub, barman) : 0;
	((*barman)->exec == 3) ? op_st(pub, barman) : 0;
	((*barman)->exec == 4) ? op_add(pub, barman) : 0;
	((*barman)->exec == 5) ? op_sub(pub, barman) : 0;
	((*barman)->exec == 6) ? op_and(pub, barman) : 0;
	((*barman)->exec == 7) ? op_or(pub, barman) : 0;
	((*barman)->exec == 8) ? op_xor(pub, barman) : 0;
	((*barman)->exec == 9) ? op_zjmp(pub, barman) : 0;
	((*barman)->exec == 10) ? op_ldi(pub, barman) : 0;
	((*barman)->exec == 11) ? op_sti(pub, barman) : 0;
	((*barman)->exec == 12) ? op_fork(pub, barman) : 0;
	((*barman)->exec == 13) ? op_lld(pub, barman) : 0;
	((*barman)->exec == 14) ? op_lldi(pub, barman) : 0;
	((*barman)->exec == 15) ? op_lfork(pub, barman) : 0;
	((*barman)->exec == 16) ? op_aff(pub, barman) : 0;
	return (1);
}

void			slainte(t_arena **pub, t_carriage **barman)
{
	unsigned int	args;

	args = 0;
	(valid_order(*pub, barman)) ? drink_it(pub, barman) : 0;
	(*barman)->typarg[0] = 0;
	(*barman)->typarg[1] = 0;
	(*barman)->typarg[2] = 0;
	if (g_flags[2][0] && g_flags[2][1] & 16 && ((*barman)->exec != 9 ||
		!(*barman)->carry))
	{
		ft_printf("ADV %d (%.4p -> %.4p)", (*barman)->amskip,
		(*barman)->posit, (*barman)->posit + (*barman)->amskip);
		while (args < (*barman)->amskip)
			ft_printf(" %.2x",
			(*pub)->cell[CM((*barman)->posit + args++)]);
		ft_printf(" \n");
	}
	new_owner(pub, (*barman)->posit, (*barman)->posit +
	(*barman)->amskip, (*barman)->player);
	(*barman)->posit = CM((*barman)->posit + (*barman)->amskip);
	(*barman)->amskip = 0;
	(*barman)->exec = 0;
}

int				take_order(t_arena **pub, t_carriage **barman)
{
	(g_flags[2][0] && g_flags[2][1] & 2) ?
	ft_printf("It is now cycle %d\n", (*pub)->iter[0]) : 0;
	while (++(*barman)->cylive && ++(*pub)->survived)
	{
		if (!(*barman)->alive && (*pub)->survived-- && !(*barman)->next)
			break ;
		if (!(*barman)->alive && (*barman = (*barman)->next))
			continue ;
		(*pub)->owner[(*barman)->posit] = (*barman)->player;
		(*barman)->cyexec -= !!(*barman)->cyexec;
		if (!(*barman)->exec && (!(*pub)->cell[(*barman)->posit] ||
			(*pub)->cell[(*barman)->posit] > 16))
			(*barman)->posit = CM((*barman)->posit + 1);
		else if (!(*barman)->exec &&
			((*barman)->exec = (*pub)->cell[(*barman)->posit]))
			(*barman)->cyexec = g_optab[(*pub)->cell[(*barman)->posit] -
				1].cyexec - 1;
		(!(*barman)->cyexec && (*barman)->exec) ? slainte(pub, barman) : 0;
		if (!(*barman)->next)
			break ;
		*barman = (*barman)->next;
	}
	while ((*barman)->prev)
		*barman = (*barman)->prev;
	return (1);
}

void			the_talk(t_arena **pub, t_carriage **barman)
{
	while ((*pub)->survived && !((*pub)->sumlive = 0))
	{
		while ((*pub)->survived && (*pub)->iter[0] <=
			(*pub)->iter[1] + (((*pub)->cydeath > 0) ? (*pub)->cydeath : 1))
		{
			(*pub)->survived = 0;
			take_order(pub, barman);
			(g_flags[7][0]) ? corewar_visual_step(*pub, barman) : 0;
			if ((g_flags[0][0] && (*pub)->iter[0] == g_flags[0][1]) ||
			(g_flags[1][0] && (*pub)->iter[0] == g_flags[1][1]))
				break ;
			(*pub)->iter[0]++;
		}
		if ((g_flags[0][0] && (*pub)->iter[0] == g_flags[0][1]) ||
			(g_flags[1][0] && (*pub)->iter[0] == g_flags[1][1]))
			exit(0 * out_arena(*pub, 64 - 32 * g_flags[0][0]));
		if (!del_carriage(pub, barman))
			break ;
		if (!((*pub)->sumlive < NBR_LIVE && ++(*pub)->check < MAX_CHECKS))
			if (!((*pub)->check = 0))
				if (((*pub)->cydeath -= CYCLE_DELTA) || !(*pub)->cydeath)
					(g_flags[2][0] && g_flags[2][1] & 8) ?
					ft_printf("Cycle to die is now %d\n", (*pub)->cydeath) : 0;
		(*pub)->iter[1] = (*pub)->iter[0] - 1;
	}
}
