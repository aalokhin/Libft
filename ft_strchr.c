/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:09:33 by aalokhin          #+#    #+#             */
/*   Updated: 2017/11/07 21:09:56 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char		search;
	char				*found_it;

	search = c;
	found_it = (char*)s;
	if (search == '\0')
		return (&found_it[ft_strlen(found_it)]);
	while (*found_it != '\0')
	{
		if (*found_it == search)
			return (found_it);
		found_it++;
	}
	return (NULL);
}
