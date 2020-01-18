/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:49:35 by vyunak            #+#    #+#             */
/*   Updated: 2019/04/04 15:00:57 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#define LLM 9223372036854775807

int			ft_atoi(const char *str)
{
	unsigned long long	nbr;
	size_t				i;
	int					sign;

	i = 0;
	sign = 1;
	nbr = 0;
	while (str[i] == ' ' || (str[i] >= 8 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		if (sign == 1 && (nbr > LLM || (nbr == LLM && str[i] > '7')))
			return (-1);
		if (sign == -1 && (nbr > LLM || (nbr == LLM && str[i] > '8')))
			return (0);
		nbr = nbr * 10 + (str[i++] - '0');
	}
	return ((int)(nbr * sign));
}
