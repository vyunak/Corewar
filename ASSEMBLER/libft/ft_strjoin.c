/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:53:27 by vyunak            #+#    #+#             */
/*   Updated: 2019/04/04 15:55:17 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	x;
	size_t	d;

	d = 0;
	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(*str) * (i + 1));
	if (!str)
		return (NULL);
	ft_strcpy(str, (char*)s1);
	x = ft_strlen(str);
	while (s2[d] != '\0')
	{
		str[x + d] = s2[d];
		d++;
	}
	str[x + d] = '\0';
	return (str);
}
