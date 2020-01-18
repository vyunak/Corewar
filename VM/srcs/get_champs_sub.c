/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_champs_sub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaramel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:15:40 by okaramel          #+#    #+#             */
/*   Updated: 2019/09/12 18:15:42 by okaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int				check_magic(int fd)
{
	uint_fast8_t	buf;

	if (!read(fd, &buf, 1) || buf != 0 ||
		!read(fd, &buf, 1) || buf != 234 ||
		!read(fd, &buf, 1) || buf != 131 ||
		!read(fd, &buf, 1) || buf != 243)
		return ((int)error_msg((g_error = 4)));
	return (1);
}

int				check_null(int fd)
{
	uint_fast8_t	buf;

	if (!read(fd, &buf, 1) || buf != 0 ||
		!read(fd, &buf, 1) || buf != 0 ||
		!read(fd, &buf, 1) || buf != 0 ||
		!read(fd, &buf, 1) || buf != 0)
		return ((int)error_msg((g_error = 6)));
	return (1);
}

char			*read_name(int fd)
{
	char			*name;
	uint_fast8_t	buf;
	size_t			i;

	name = (char*)malloc(sizeof(char) * (PROG_NAME_LENGTH + 1));
	i = 0;
	while (++i <= PROG_NAME_LENGTH && read(fd, &buf, 1) > 0)
		name[i - 1] = buf;
	if (i != PROG_NAME_LENGTH + 1)
		return ((char*)error_msg((g_error = 5)));
	return (name);
}

int				read_size(int fd)
{
	uint_fast8_t	buf;
	size_t			size;

	size = 0;
	if (!read(fd, &buf, 1))
		return ((int)error_msg((g_error = 7)));
	size = size * 256 + buf;
	if (!read(fd, &buf, 1))
		return ((int)error_msg((g_error = 7)));
	size = size * 256 + buf;
	if (!read(fd, &buf, 1))
		return ((int)error_msg((g_error = 7)));
	size = size * 256 + buf;
	if (!read(fd, &buf, 1))
		return ((int)error_msg((g_error = 7)));
	size = size * 256 + buf;
	if (!size || size > CHAMP_MAX_SIZE)
		return ((int)error_msg((g_error = 10)));
	return (size);
}

char			*read_comment(int fd)
{
	char			*comm;
	uint_fast8_t	buf;
	size_t			i;

	comm = (char*)malloc(sizeof(char) * (COMMENT_LENGTH + 1));
	i = 0;
	while (++i <= COMMENT_LENGTH && read(fd, &buf, 1) > 0)
		comm[i - 1] = buf;
	if (i != COMMENT_LENGTH + 1)
		return ((char*)error_msg((g_error = 8)));
	return (comm);
}
