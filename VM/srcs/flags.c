/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaramel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:44:19 by okaramel          #+#    #+#             */
/*   Updated: 2019/09/15 13:44:22 by okaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void			print_usage(void)
{
	ft_printf("Usage: ./corewar [-dump N -m N -v N] [[-n N] champion1.cor]"
" ...\n"
"#### TEXT OUTPUT MODE ########################################################"
"##\n"
"    -dump N   : Dumps memory after N cycles then exits (32 octets per line)\n"
"    -m N      : Dumps memory after N cycles then exits (64 octets per line)\n"
"    -v N      : Verbosity levels, can be added together to enable several\n"
"                - 1 : Show lives\n"
"                - 2 : Show cycles\n"
"                - 4 : Show operations (Params are NOT literal ...)\n"
"                - 8 : Show deaths\n"
"                - 16 : Show PC movements (Except for jumps)\n"
"    -n N      : Sets the number of the next player. Can be from 0 to MAX_PLAYE"
"RS\n"
"#### VISUAL OUTPUT MODE ######################################################"
"##\n"
"    -visual   : Activates visual output mode\n");
	exit(0);
}

void			player_order(void)
{
	int				i;
	int				j;
	int				taken[4];

	taken[0] = 1;
	taken[1] = 2;
	taken[2] = 3;
	taken[3] = 4;
	(g_flags[3][1]) ? taken[g_flags[3][1] - 1] = 0 : 0;
	(g_flags[4][1]) ? taken[g_flags[4][1] - 1] = 0 : 0;
	(g_flags[5][1]) ? taken[g_flags[5][1] - 1] = 0 : 0;
	(g_flags[6][1]) ? taken[g_flags[6][1] - 1] = 0 : 0;
	i = 2;
	while (++i < MAX_PLAYERS + 3 && !(j = 0))
	{
		while (!taken[j])
			j++;
		if (!(g_flags[i][1]) && (g_flags[i][1] = taken[j]))
			taken[j++] = 0;
	}
	if (!(g_flags[3][1] ^ g_flags[4][1]) || !(g_flags[3][1] ^ g_flags[5][1]) ||
		!(g_flags[3][1] ^ g_flags[6][1]) || !(g_flags[4][1] ^ g_flags[5][1]) ||
		!(g_flags[4][1] ^ g_flags[6][1]) || !(g_flags[5][1] ^ g_flags[6][1]))
		exit(0 * ft_printf("ERROR: contains players with same number\n"));
}

int				parse_flags(char **av)
{
	int				i[2];

	ft_bzero(i, 2 * sizeof(int));
	while (*++av)
	{
		if (ft_strrchr(*av, '.') && !ft_strcmp("cor", ft_strrchr(*av, '.') + 1))
			i[0]++;
		if (!ft_strcmp(*av, "-dump"))
			(*++av && (g_flags[0][1] = ft_atoi(*av)) > 0) ?
			g_flags[0][0] = 1 : print_usage();
		else if (!ft_strcmp(*av, "-m"))
			(*++av && (g_flags[1][1] = ft_atoi(*av)) > 0)
			? g_flags[1][0] = 1 : print_usage();
		else if (!ft_strcmp(*av, "-v"))
			(*++av && (g_flags[2][1] = ft_atoi(*av)) > 0 &&
			g_flags[2][1] < 32) ? g_flags[2][0] = 1 : print_usage();
		else if (!ft_strcmp(*av, "-n") && *++av && (i[1] = ft_atoi(*av)) > 0)
			(i[1] <= MAX_PLAYERS && *++av && (g_flags[i[0] + 3][0] = 1)) ?
			g_flags[i[0]++ + 3][1] = i[1] : print_usage();
		else if (!ft_strcmp(*av, "-visual") && (g_flags[7][0] = 1))
			g_flags[7][1] = (*(av + 1) && !ft_strcmp(*++av, "--silent"));
		else if (**av == '-' && !ft_strchr(*av, '.'))
			return (0 * ft_printf("ERROR: Invalid flag %s\n", *av));
	}
	return (1);
}
