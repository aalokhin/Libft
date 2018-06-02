/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:05:58 by aalokhin          #+#    #+#             */
/*   Updated: 2017/11/07 21:06:10 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char		search;
	char				*str;
	int					i;

	i = ft_strlen(s);
	search = c;
	str = (char*)s;
	if (search == '\0')
		return (&str[ft_strlen(str)]);
	while (i != -1)
	{
		if (str[i] == search)
			return (&str[i]);
		i--;
	}
	return (NULL);
}
