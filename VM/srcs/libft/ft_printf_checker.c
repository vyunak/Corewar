/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 15:39:45 by vyunak            #+#    #+#             */
/*   Updated: 2019/04/10 15:32:34 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			istype(char c)
{
	if (c == 'd' || c == 'D' || c == 'i' || c == 'o' || c == 'O' || c == 'u' ||
		c == 'U' || c == 'x' || c == 'X' || c == 'c' || c == 'C' || c == 's' ||
		c == 'S' || c == 'p' || c == 'f' || c == 'F')
		return (1);
	else
		return (0);
}

int			iscastm(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == 'L')
		return (1);
	else
		return (0);
}

int			isflag(char c)
{
	if (c == ' ' || c == '#' || c == '-' || c == '+' || c == '0')
		return (1);
	else
		return (0);
}
