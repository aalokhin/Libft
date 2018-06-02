/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:17:54 by aalokhin          #+#    #+#             */
/*   Updated: 2017/11/07 21:17:58 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *s1)
{
	size_t		len;
	size_t		i;
	char		*s2;

	i = 0;
	len = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(*s2) * (len + 1));
	if (!s2)
		return (NULL);
	s2[len] = '\0';
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}
