/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:51:19 by vyunak            #+#    #+#             */
/*   Updated: 2019/07/19 15:52:56 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strndup(const char *src, int start, int finish)
{
	int		i;
	int		j;
	int		x;
	char	*crs;

	i = 0;
	j = 0;
	x = start;
	while (start <= finish && src[i++])
		start++;
	if ((crs = (char*)malloc(sizeof(char) * (i + 1))))
	{
		while (j < i)
		{
			crs[j] = src[x++];
			j++;
		}
		crs[j] = '\0';
		return (crs);
	}
	return (0);
}
