/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 04:25:15 by aalokhin          #+#    #+#             */
/*   Updated: 2018/06/01 04:25:17 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		neg(intmax_t *tmp, int *sign)
{
	if ((*tmp) < 0)
	{
		(*sign) = 1;
		(*tmp) = -(*tmp);
	}
}

char		*ft_itoa_m(intmax_t value)
{
	intmax_t	tmp;
	int			len;
	int			sign;
	char		*str;

	sign = 0;
	len = 2;
	tmp = value;
	neg(&tmp, &sign);
	value = tmp;
	while (tmp /= 10)
		len++;
	len = len + sign;
	if ((str = (char *)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = (value % 10) + '0';
		value = value / 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}

char		*ft_itoa_base_small(uintmax_t value, int base)
{
	uintmax_t			tmp;
	int					len;
	char				*str;

	len = 2;
	tmp = value;
	while (tmp /= base)
		len++;
	if ((str = (char *)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		if (value % base > 9)
			str[len] = (value % base) + 87;
		else
			str[len] = (value % base) + '0';
		value = value / base;
	}
	return (str);
}

char		*ft_itoa_base(uintmax_t value, int base)
{
	uintmax_t		tmp;
	int				len;
	char			*str;

	len = 2;
	tmp = value;
	while (tmp /= base)
		len++;
	if (!(str = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		if (value % base > 9)
			str[len] = (value % base) + 55;
		else
			str[len] = (value % base) + '0';
		value = value / base;
	}
	return (str);
}
