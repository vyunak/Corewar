/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:57:00 by vyunak            #+#    #+#             */
/*   Updated: 2019/04/04 17:57:01 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			i;
	unsigned int	d;
	char			*str;

	if (!s && !f)
		return (NULL);
	i = ft_strlen(s);
	d = 0;
	if (!(str = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	while (i > d)
	{
		str[d] = (*f)((unsigned int)d, (char)s[d]);
		d++;
	}
	str[i] = '\0';
	return (str);
}
