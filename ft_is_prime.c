/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:10:40 by aalokhin          #+#    #+#             */
/*   Updated: 2017/11/17 13:10:45 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t		ft_is_prime(size_t nb)
{
	size_t a;
	size_t b;

	if (nb == 0 || nb == 1)
	{
		return (0);
	}
	a = 2;
	b = 1;
	while (a < nb && b != 0)
	{
		b = nb % a;
		a++;
	}
	if (a == nb)
	{
		return (1);
	}
	return (0);
}
