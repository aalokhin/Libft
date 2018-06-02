/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:17:32 by aalokhin          #+#    #+#             */
/*   Updated: 2017/11/07 20:18:19 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t		len;
	size_t		i;
	char		*res;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	res = (char*)malloc(sizeof(*res) * (len + 1));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = f(s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
