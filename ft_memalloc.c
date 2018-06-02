/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:50:35 by aalokhin          #+#    #+#             */
/*   Updated: 2017/11/07 19:49:03 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*res;

	res = (unsigned char *)malloc(sizeof(unsigned char) * size);
	if (!res)
		return (NULL);
	ft_bzero(res, size);
	return ((void *)res);
}
