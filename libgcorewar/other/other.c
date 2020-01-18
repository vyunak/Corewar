/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:09:59 by dmatseku          #+#    #+#             */
/*   Updated: 2019/09/24 15:10:01 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	my_strncat(char *const str1, char const *const str2, const size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}
}

size_t	my_strlen(char const *const restrict str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	my_memset(void *const array, const int symbol, size_t size)
{
	char *const	str = (char *const)array;

	while (size--)
		str[size] = (char)symbol;
}

void	my_bzero(void *const array, size_t size)
{
	char *const	str = (char *const)array;

	while (size--)
		str[size] = 0;
}

void	exit_error(char *const restrict str)
{
	write(1, str, my_strlen(str));
	write(1, "\n", 1);
	exit(0);
}
