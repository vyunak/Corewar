/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:28:56 by vyunak            #+#    #+#             */
/*   Updated: 2019/04/04 16:29:00 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmap(char const *s, char (*f)(char))
{
	size_t			i;
	size_t			d;
	char			*str;

	if (!s && !f)
		return (NULL);
	i = ft_strlen(s);
	d = 0;
	if (!(str = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	while (i > d)
	{
		str[d] = (*f)((char)s[d]);
		d++;
	}
	str[i] = '\0';
	return (str);
}
