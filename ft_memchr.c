/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:07:59 by aalokhin          #+#    #+#             */
/*   Updated: 2017/11/07 21:08:42 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;

	s1 = (unsigned char*)s;
	while (n)
	{
		if (*s1 == (unsigned char)c)
			return ((void *)s1);
		s1++;
		n--;
	}
	return (NULL);
}
