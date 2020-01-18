/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 17:43:22 by vyunak            #+#    #+#             */
/*   Updated: 2019/08/21 17:51:59 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int				get_comment(char *str)
{
	int			i[2];

	ft_bzero(&i, sizeof(i));
	while (white_space(str[i[0]]))
		i[0]++;
	if (str[i[0]] != '#' && str[i[0]] != ';')
	{
		i[1] = i[0];
		while (ft_isascii_wn(str[i[1]]) && str[i[1]] != '"')
			i[1]++;
		if (ft_strncmp(&str[i[0]], CAMPCOMMENT, (i[1] > i[0]) ? i[1] - i[0] :
			i[0] - i[1]) != 0)
			return (print_error("incorrect comment!"));
		while (white_space(str[i[1]]))
			i[1]++;
		if (str[i[1]] != '"')
			return (0);
		i[0] = 0;
		return (get_comment_p2(i, &str[i[1]]));
	}
	return (0);
}

int				get_name(char *str)
{
	int			i[2];

	ft_bzero(&i, sizeof(i));
	while (white_space(str[i[0]]))
		i[0]++;
	if (str[i[0]] != '#' && str[i[0]] != ';')
	{
		i[1] = i[0];
		while (ft_isascii_wn(str[i[1]]) && str[i[1]] != '"')
			i[1]++;
		if (ft_strncmp(&str[i[0]], CHAMPNAME, (i[1] > i[0]) ? i[1] - i[0] :
			i[0] - i[1]) != 0)
			return (print_error("incorrect name!"));
		while (white_space(str[i[1]]))
			i[1]++;
		if (str[i[1]] != '"')
			return (0);
		i[0] = 0;
		return (get_name_p2(i, &str[i[1]]));
	}
	return (0);
}

void			check_argv(int ac, char **av)
{
	int		i;
	int		h;
	t_files	*tmp;

	if (ac == 1)
		print_error("Usage: ./asm [filename] [filename-N]");
	if (g_data.error == 0)
	{
		h = 0;
		file_struct_malloc(&g_files);
		tmp = g_files;
		while (++h < ac)
		{
			tmp->name = search_s(av[h]);
			tmp->name_og = av[h];
			if ((i = open(av[h], 0)) == -1 || read(i, NULL, 0) < 0)
				tmp->ok = 1;
			(tmp->ok == 0) ? tmp->fd = open(av[h], 0) : 0;
			if (av[h + 1])
			{
				file_struct_malloc(&tmp->next);
				tmp = tmp->next;
			}
		}
	}
}

void			main_while(t_files *tmp, char *line)
{
	while (get_next_line(tmp->fd, &line) > 0 && g_data.error != 1)
	{
		if (((g_data.name == 1 && !ft_strstr(line, CAMPCOMMENT)) ||
			(g_data.name == 1 && g_data.comment == 1)) ||
			(!ft_strstr(line, CHAMPNAME) && !ft_strstr(line, CAMPCOMMENT)
				&& g_data.error != 1))
			dell_comment(&line);
		if (g_data.name == 0 && ft_strstr(line, CHAMPNAME) != NULL &&
			g_data.error != 1)
			get_name(line);
		else if (g_data.comment == 0 &&
				ft_strstr(line, CAMPCOMMENT) != NULL &&
				g_data.error != 1)
			get_comment(line);
		else if (ft_strisalnum(line) == 1 && g_data.error != 1 &&
				g_data.error != 1)
			parse_all(line);
		else if (line[0] == ':' && g_data.error != 1)
			print_error("incorrect label");
		free(line);
		line = NULL;
	}
	if (line != NULL)
		free(line);
	line = NULL;
}

int				main(int ac, char **av)
{
	t_files		*tmp;
	char		*line;

	ft_bzero(&g_data, sizeof(g_data));
	check_argv(ac, av);
	tmp = g_files;
	line = NULL;
	while (tmp)
	{
		if (tmp->ok == 0)
		{
			all_free();
			ft_bzero(&g_data, sizeof(g_data));
			g_data.list = (t_while*)malloc(sizeof(t_while));
			ft_bzero(&*g_data.list, sizeof(t_while));
			main_while(tmp, line);
			if (check_end_line(tmp->name_og) && g_data.error != 1)
				print_error("end of new line!");
			writing_binary_code(&g_data, tmp);
		}
		else
			ft_printf("%s: file error!\n", tmp->name_og);
		tmp = tmp->next;
	}
	return (1);
}
