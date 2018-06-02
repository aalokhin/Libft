/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:05:06 by aalokhin          #+#    #+#             */
/*   Updated: 2017/11/07 21:05:43 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static size_t		lets_search(char *look_in, char *look_for)
{
	size_t			i;

	i = 0;
	while (look_in[i] != '\0' && look_in[i] == look_for[i])
	{
		if (look_for[i + 1] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char				*ft_strstr(const char *big, const char *little)
{
	char			*look_for;
	char			*look_in;

	look_in = (char *)big;
	look_for = (char *)little;
	if (*look_for == '\0')
		return (look_in);
	while (*look_in != '\0')
	{
		if (*look_in == *look_for)
		{
			if (lets_search(look_in, look_for))
				return (look_in);
		}
		look_in++;
	}
	return (NULL);
}
