/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:36:16 by vyunak            #+#    #+#             */
/*   Updated: 2019/04/04 16:36:19 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		x;
	char	*str;

	if (!s)
		return (NULL);
	x = ft_strlen(s);
	while (s[x - 1] == ' ' || s[x - 1] == '\t' || s[x - 1] == '\n')
		x--;
	i = -1;
	while (s[++i] == ' ' || s[i] == '\t' || s[i] == '\n')
		x--;
	if (x <= 0)
		x = 0;
	if (!(str = (char*)malloc(sizeof(char) * (x + 1))))
		return (NULL);
	s += i;
	i = 0;
	while (i < x)
		str[i++] = *s++;
	str[i] = '\0';
	return (str);
}
