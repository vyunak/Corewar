/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 10:37:35 by vyunak            #+#    #+#             */
/*   Updated: 2019/07/19 15:52:55 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_list		*list_check(t_list **list, const int fd)
{
	t_list			*tmp;

	tmp = *list;
	while (tmp)
	{
		if (tmp->content_size == (size_t)fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("", fd);
	ft_lstadd(list, tmp);
	return (*list);
}

static	int			re_line(t_list **list, char **line)
{
	char			*str;
	int				i;

	i = 0;
	if (ft_strlen((*list)->content) == 0)
		return (0);
	str = (*list)->content;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	*line = ft_strnew(i + 1);
	ft_strncpy(*line, str, i);
	if (str[i] == '\0')
		str = ft_strdup(ft_strchr(str, '\0'));
	else if (str[i] == '\n')
		str = ft_strdup(ft_strchr(str, '\n') + 1);
	free((*list)->content);
	(*list)->content = ft_strdup(str);
	free(str);
	return (1);
}

char				*gnl_strjoin(const char *s1, const char *s2)
{
	char			*str;
	size_t			i;
	size_t			j;
	size_t			s1_len;
	size_t			s2_len;

	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(str = ft_strnew(s1_len + s2_len + 1)))
		return (NULL);
	i = -1;
	j = -1;
	while (++i < s1_len)
		str[i] = s1[i];
	while (++j < s2_len)
		str[i++] = s2[j];
	return (str);
}

int					get_next_line(const int fd, char **line)
{
	static	t_list	*list;
	char			*buff;
	t_list			*tmp_list;
	int				l_rd;
	char			*tmp;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFF_SIZE < 1)
		return (-1);
	tmp_list = list_check(&list, fd);
	buff = ft_strnew(BUFF_SIZE + 1);
	while (!ft_strchr(tmp_list->content, '\n') &&
	(l_rd = read(fd, buff, BUFF_SIZE)))
	{
		buff[l_rd] = '\0';
		tmp = tmp_list->content;
		tmp_list->content = gnl_strjoin(tmp_list->content, buff);
		free(tmp);
		if (ft_strchr(tmp_list->content, '\n'))
			break ;
	}
	free(buff);
	if ((l_rd = re_line(&tmp_list, line)) == 0)
		return (0);
	return (1);
}
