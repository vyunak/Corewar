/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:46:06 by vyunak            #+#    #+#             */
/*   Updated: 2019/04/04 15:46:13 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i] != c)
		{
			if (str[i] == '\0')
				return (NULL);
			i++;
		}
	}
	return ((char*)str + i);
}
