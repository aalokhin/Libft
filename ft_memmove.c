/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:10:48 by aalokhin          #+#    #+#             */
/*   Updated: 2017/11/07 21:10:58 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst1;
	const unsigned char	*src1;

	dst1 = dst;
	src1 = src;
	i = 0;
	if (dst1 <= src1)
	{
		while (i < n)
		{
			dst1[i] = src1[i];
			i++;
		}
	}
	else
	{
		i = n + 1;
		while (--i > 0)
			dst1[i - 1] = src1[i - 1];
	}
	return (dst1);
}
