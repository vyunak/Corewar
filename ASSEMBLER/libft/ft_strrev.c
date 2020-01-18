/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:34:30 by vyunak            #+#    #+#             */
/*   Updated: 2019/04/04 16:34:33 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_strrev(char *str)
{
	unsigned int	i;
	unsigned int	x;
	char			t;

	i = ft_strlen(str) - 1;
	x = 0;
	while (x < i)
	{
		t = str[x];
		str[x] = str[i];
		str[i] = t;
		x++;
		i--;
	}
}
