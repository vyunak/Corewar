/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pub_carriage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaramel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:06:54 by okaramel          #+#    #+#             */
/*   Updated: 2019/09/12 18:06:57 by okaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

t_arena			*find_pub(void)
{
	t_arena			*new;

	new = malloc(sizeof(t_arena));
	new->iter[0] = 1;
	new->iter[1] = 0;
	new->check = 0;
	new->sumlive = 0;
	new->lastlive = -g_pamount;
	new->survived = g_pamount;
	new->cydeath = CYCLE_TO_DIE;
	ft_bzero(new->cell, MEM_SIZE);
	ft_bzero(new->owner, MEM_SIZE);
	return (new);
}

t_carriage		*new_carriage(void)
{
	int				i;
	t_carriage		*new;

	new = malloc(sizeof(t_carriage));
	new->id = 0;
	new->player = 0;
	new->alive = 1;
	new->cylive = 0;
	new->exec = 0;
	new->cyexec = 0;
	new->typarg[0] = 0;
	new->typarg[1] = 0;
	new->typarg[2] = 0;
	new->posit = 0;
	new->amskip = 0;
	new->carry = 0;
	i = -1;
	while (++i < REG_NUMBER)
		new->reg[i] = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_carriage		*put_carriage(t_arena **pub, t_champ *mate)
{
	t_carriage		*barman;
	size_t			i;

	i = MEM_SIZE / g_pamount * (mate->id - 1);
	barman = new_carriage();
	barman->id = mate->id;
	barman->player = mate->id;
	barman->reg[0] = barman->id * (-1);
	barman->posit = i;
	ft_memcpy((*pub)->cell + i, mate->exec, mate->size);
	ft_memset((*pub)->owner + i, mate->id, mate->size);
	return (barman);
}

t_carriage		*gentlemen_meeting(t_arena **pub, t_champ **mate)
{
	t_carriage		*barman;

	barman = put_carriage(pub, *mate);
	while (*++mate)
	{
		barman->prev = put_carriage(pub, *mate);
		barman->prev->next = barman;
		barman = barman->prev;
	}
	mate -= g_pamount - 1;
	return (barman);
}

int				del_carriage(t_arena **pub, t_carriage **barman)
{
	int			surv;
	t_carriage	*current;

	surv = 0;
	current = *barman;
	while (current)
	{
		if (current->alive && current->cylive >= (*pub)->cydeath)
		{
			(g_flags[2][0] && g_flags[2][1] & 8) ?
			ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
			current->id, current->cylive, (*pub)->cydeath) : 0;
			current->alive = 0;
		}
		else if (current->alive)
			surv++;
		current = current->next;
	}
	return (!!surv);
}
