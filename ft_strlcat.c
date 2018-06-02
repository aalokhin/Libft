/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:18:07 by aalokhin          #+#    #+#             */
/*   Updated: 2017/11/07 21:18:14 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static size_t		ft_dlen(const char *s, size_t size)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && size)
	{
		size--;
		i++;
	}
	return (i);
}

size_t				ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	j;
	size_t	left;
	size_t	i;

	dlen = ft_dlen(dst, size);
	i = dlen;
	left = size - dlen;
	j = 0;
	if (left == 0)
		return (dlen + ft_strlen(src));
	while (src[j] != '\0')
	{
		if (left != 1)
		{
			dst[i++] = src[j];
			left--;
		}
		j++;
	}
	dst[i] = '\0';
	return (dlen + j);
}
