/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:06:29 by aalokhin          #+#    #+#             */
/*   Updated: 2017/11/07 21:06:49 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static size_t		lets_search(char *look_in, char *look_for, size_t len)
{
	size_t i;

	i = 0;
	while (len > 0 && look_in[i] == look_for[i] && look_in[i] != '\0')
	{
		if (look_for[i + 1] == '\0')
			return (1);
		i++;
		len--;
	}
	return (0);
}

char				*ft_strnstr(const char *big, const char *little, size_t len)
{
	char			*look_for;
	char			*look_in;

	look_in = (char *)big;
	look_for = (char *)little;
	if (*look_for == '\0')
		return (look_in);
	while (len > 0 && *look_in != '\0')
	{
		if (*look_in == *look_for)
		{
			if (lets_search(look_in, look_for, len))
				return (look_in);
		}
		look_in++;
		len--;
	}
	return (NULL);
}
