/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_champs_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaramel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:09:28 by okaramel          #+#    #+#             */
/*   Updated: 2019/09/12 18:09:29 by okaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

uint_fast8_t	*read_execute(int fd, size_t size)
{
	uint_fast8_t	*exec;
	uint_fast8_t	buf;
	size_t			i;

	exec = (uint_fast8_t*)malloc(sizeof(uint_fast8_t) * (size + 1));
	i = 0;
	while (++i <= size && read(fd, &buf, 1) > 0)
		exec[i - 1] = buf;
	exec[i - 1] = '\0';
	if (i != size + 1 || read(fd, &buf, 1))
		return ((uint_fast8_t*)error_msg((g_error = 9)));
	return (exec);
}

t_champ			*new_champ(void)
{
	t_champ			*new;

	new = malloc(sizeof(t_champ));
	new->id = 1;
	new->name = NULL;
	new->size = 0;
	new->comm = NULL;
	new->exec = NULL;
	return (new);
}

t_champ			*read_champ(char *name)
{
	t_champ			*mate;
	int				fd;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		return ((t_champ*)error_msg((g_error = 2)));
	if (!ft_strrchr(name, '.') ||
	ft_strcmp("cor", ft_strrchr(name, '.') + 1))
		return ((t_champ*)error_msg((g_error = 3)));
	if (!check_magic(fd) ||
	!(mate = new_champ()) ||
	!(mate->name = read_name(fd)) ||
	!check_null(fd) ||
	!(mate->size = read_size(fd)) ||
	!(mate->comm = read_comment(fd)) ||
	!check_null(fd) ||
	!(mate->exec = read_execute(fd, mate->size)))
		return (0);
	return (mate);
}

t_champ			**make_buddies(int ac, char **av)
{
	int				i;
	int				k;
	t_champ			**mate;

	mate = (t_champ**)malloc(sizeof(t_champ*) * 5);
	ft_bzero(mate, 5 * sizeof(t_champ*));
	i = 0;
	k = 3;
	while (++i < ac)
	{
		if (av[i][0] == '-' && !ft_strchr(av[i], '.') &&
			(!av[i + 1] || !ft_strcmp(av[++i], "--silent") || ft_atoi(av[i])))
			continue ;
		if (!(mate[g_flags[k++][1] - 1] = read_champ(av[i])))
			return (0);
		else if ((mate[g_flags[k - 1][1] - 1]->id = g_flags[k - 1][1]))
			g_pamount++;
	}
	if ((g_flags[3][0] && g_flags[3][1] > g_pamount) || (g_flags[4][0] &&
		g_flags[4][1] > g_pamount) || (g_flags[5][0] && g_flags[5][1] >
		g_pamount) || (g_flags[6][0] && g_flags[6][1] > g_pamount))
		print_usage();
	return (mate);
}
