/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 16:46:20 by aalokhin          #+#    #+#             */
/*   Updated: 2017/11/19 16:46:27 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static size_t		ft_lgth(size_t nbr)
{
	int		count;

	count = 1;
	while (nbr != 0)
	{
		nbr = nbr / 16;
		count++;
	}
	return (count);
}

char				*ft_hex(size_t nbr)
{
	char		*res;
	size_t		tmp;
	size_t		i;

	i = 0;
	res = (char*)malloc(sizeof(char) * (ft_lgth(nbr) + 1));
	if (nbr == 0)
		res[i++] = '0';
	while (nbr != 0)
	{
		tmp = nbr % 16;
		if (tmp < 10)
			tmp = tmp + 48;
		else
			tmp = tmp + 55;
		res[i++] = tmp;
		nbr = nbr / 16;
	}
	res[i] = '\0';
	return (res);
}
