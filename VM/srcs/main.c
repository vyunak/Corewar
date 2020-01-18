/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaramel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 18:21:08 by okaramel          #+#    #+#             */
/*   Updated: 2019/09/25 14:52:04 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void			*error_msg(int mode)
{
	ft_printf("ERROR: ");
	(mode == 1) ? ft_printf("invalid number of champions\n") : 0;
	(mode == 2) ? ft_printf("invalid file\n") : 0;
	(mode == 3) ? ft_printf("invalid file type\n") : 0;
	(mode == 4) ? ft_printf("invalid magic header\n") : 0;
	(mode == 5) ? ft_printf("file ended while reading name\n") : 0;
	(mode == 6) ? ft_printf("null terminator is missing\n") : 0;
	(mode == 7) ? ft_printf("file ended while reading size of "
	"executing code\n") : 0;
	(mode == 8) ? ft_printf("file ended while reading comment\n") : 0;
	(mode == 9) ? ft_printf("file ended while reading executing code "
	"or actual size of said code mismatch read size of it\n") : 0;
	(mode == 10) ? ft_printf("size is zero or bigger than allowed "
	"maximum\n") : 0;
	return (0);
}

int				out_arena(t_arena *pub, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i && !(i % len))
			ft_printf("\n");
		if (!(i % len))
			ft_printf("0x%.4x : ", i);
		ft_printf("%.2x ", pub->cell[i]);
		i++;
	}
	ft_printf("\n");
	return (1);
}

void			new_owner(t_arena **pub, int from, int to, char owner)
{
	while (from < to)
		(*pub)->owner[CM(from++)] = owner;
}

void			introduce(void)
{
	ft_printf("Introducing contestants...\n");
	(g_mate[0]) ?
	ft_printf("* Player %d, weighing %u bytes, \"%s\" (\"%s\") !\n",
	g_mate[0]->id, g_mate[0]->size, g_mate[0]->name, g_mate[0]->comm) : 0;
	(g_mate[1]) ?
	ft_printf("* Player %d, weighing %u bytes, \"%s\" (\"%s\") !\n",
	g_mate[1]->id, g_mate[1]->size, g_mate[1]->name, g_mate[1]->comm) : 0;
	(g_mate[2]) ?
	ft_printf("* Player %d, weighing %u bytes, \"%s\" (\"%s\") !\n",
	g_mate[2]->id, g_mate[2]->size, g_mate[2]->name, g_mate[2]->comm) : 0;
	(g_mate[3]) ?
	ft_printf("* Player %d, weighing %u bytes, \"%s\" (\"%s\") !\n",
	g_mate[3]->id, g_mate[3]->size, g_mate[3]->name, g_mate[3]->comm) : 0;
}

int				main(int ac, char **av)
{
	t_arena			*pub;
	t_carriage		*barman;

	if (ac == 1)
		print_usage();
	if (!parse_flags(av))
		return (0);
	player_order();
	if (!(g_mate = make_buddies(ac, av)))
		return (0);
	if (!(pub = find_pub()))
		return (0);
	if (!(g_id = g_pamount))
		return ((int)error_msg((g_error = 1)));
	if (!(barman = gentlemen_meeting(&pub, g_mate)))
		return (0);
	(!g_flags[7][0]) ? introduce() : 0;
	(g_flags[7][0]) ? corewar_visual_init((const t_champ**)g_mate, pub,
	&barman) : 0;
	the_talk(&pub, &barman);
	pub->lastlive = (pub->lastlive * (-1)) - 1;
	(!g_flags[7][0]) ? ft_printf("Contestant %d, \"%s\", has won !\n",
	pub->lastlive + 1, g_mate[(int)pub->lastlive]->name) : 0;
	(g_flags[7][0]) ? corewar_visual_destroy(g_mate[(int)pub->lastlive]) : 0;
	return (0);
}
