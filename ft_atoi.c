/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:03:35 by aalokhin          #+#    #+#             */
/*   Updated: 2017/11/07 21:03:43 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_atoi(const char *str)
{
	int sign;
	int res;

	res = 0;
	sign = 1;
	while (*str == ' ' || *str == '\n' || *str == '\v' || *str == '\t' \
		|| *str == '\r' || *str == '\f')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = 10 * res + sign * (*str - '0');
		str++;
	}
	return (res);
}
