/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format_dell.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 17:51:47 by vyunak            #+#    #+#             */
/*   Updated: 2019/08/21 17:53:32 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void			parse_op_mark(char *line, int *x)
{
	if (g_data.nline == 0 && stmark(&line[x[1] + 1]) == 1 && g_data.metk == 0)
	{
		g_data.nline = 1;
		(ft_strnslabel(&line[x[0]], x[1] - x[0]) == 0) ?
		print_error("incorrect label char!") : 0;
		write_mark(ft_strndup(line, x[0], x[1] - 1));
	}
	else if (g_data.nline == 1 && stmark(&line[x[1] + 1]) == 1 &&
		g_data.metk == 1)
	{
		(ft_strnslabel(&line[x[0]], x[1] - x[0]) == 0) ?
		print_error("incorrect label char!") : 0;
		g_data.nline = 1;
		write_mark(ft_strndup(line, x[0], x[1] - 1));
	}
	else
		parse_op_mark_2(line, x);
}

void			parse_op_mark_2(char *line, int *x)
{
	if (g_data.nline == 0 && stmark(&line[x[1] + 1]) == 0 &&
		g_data.metk == 0)
	{
		(ft_strnslabel(&line[x[0]], x[1] - x[0]) == 0) ?
		print_error("incorrect label char!") : 0;
		write_mark(ft_strndup(line, x[0], x[1] - 1));
		g_data.nline = 0;
		parse_op(&line[x[1] + 1]);
	}
	else if (g_data.nline == 1 && stmark(&line[x[1] + 1]) == 0 &&
		g_data.metk == 1)
	{
		(ft_strnslabel(&line[x[0]], x[1] - x[0]) == 0) ?
		print_error("incorrect label char!") : 0;
		write_mark(ft_strndup(line, x[0], x[1] - 1));
		parse_op(&line[x[1] + 1]);
		g_data.nline = 0;
	}
	else if (g_data.metk == 0)
	{
		g_data.nline = 0;
		parse_op(&line[(g_data.nline == 1) ? x[0] : 0]);
	}
}

void			parse_all(char *line)
{
	int			x[3];

	ft_bzero(&x, sizeof(x));
	if (g_data.name == 0 || g_data.comment == 0)
		print_error("name or comment do not exist!");
	while (white_space(line[x[0]]))
		x[0]++;
	x[1] = x[0];
	while (line[x[1]] != '\0')
	{
		if (white_space(line[x[1]]) == 1)
			x[2]++;
		if (line[x[1]] == ':' && x[2] == 0)
			break ;
		x[1]++;
	}
	g_data.metk = (x[1] != (int)ft_strlen(line) && g_data.nline == 1) ? 1 : 0;
	(x[0] == x[1]) ? print_error("incorrect label char!") : 0;
	if (x[1] > 0 && (x[1] != (int)ft_strlen(line) || g_data.nline == 1))
		parse_op_mark(line, x);
	else if (x[1] > 0)
		parse_op(line);
	else
		print_error("operation do not exist!");
}

char			*dell_comment(char **pst)
{
	char		*str;
	int			len[2];

	str = *pst;
	len[0] = ft_strlen(str);
	if (ft_strchr(str, COMMENT_CHAR))
	{
		len[1] = ft_strlen(ft_strchr(str, COMMENT_CHAR) -
			((ft_strchr(str, COMMENT_CHAR)[0] == COMMENT_CHAR) ? 0 : 1));
		if (len[1] != 0)
			*pst = ft_strndup(str, 0, len[0] - len[1] - 1);
		else
			*pst = ft_strdup("");
		free(str);
	}
	str = *pst;
	len[0] = ft_strlen(str);
	if (ft_strchr(str, ALT_COMMENT_CHAR))
	{
		len[1] = ft_strlen(ft_strchr(str, ALT_COMMENT_CHAR) - 1);
		*pst = (len[1] != 0) ? ft_strndup(str, 0, len[0] - len[1]) :
				ft_strdup("");
		free(str);
	}
	return (*pst);
}

int				check_end_line(char *str)
{
	size_t		ld[2];
	char		*buff;
	char		*all;
	char		*tmp;

	ld[0] = open(str, 0);
	buff = ft_strnew(BUFF_SIZE);
	all = NULL;
	while ((ld[1] = read(ld[0], buff, BUFF_SIZE)))
	{
		buff[ld[1]] = '\0';
		tmp = all;
		all = gnl_strjoin(all, buff);
		(tmp) ? free(tmp) : 0;
	}
	free(buff);
	if (check_last_line(all, ld[1]))
	{
		(all) ? free(all) : 0;
		return (1);
	}
	(all) ? free(all) : 0;
	return (0);
}
