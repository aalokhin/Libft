/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_wid_pre.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 04:28:42 by aalokhin          #+#    #+#             */
/*   Updated: 2018/06/01 04:28:43 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			fill_precision(char *str, t_flags *box, size_t *vasia)
{
	size_t		i;

	i = (*vasia);
	while (str[i] && str[i] != '.')
	{
		if (!(SKIP(str[i])) || SPECIFIER(str[i]))
			return ;
		i++;
	}
	if (str[i] == '.')
		box->dot = 1;
	while (str[i] && !(!(SKIP(str[i])) || SPECIFIER(str[i])))
		i++;
	while (str[i - 1] && str[i - 1] != '.')
		i--;
	box->pre = collect(str, i);
}

size_t			collect(char *s, size_t i)
{
	intmax_t	ret;

	ret = ft_atoi_m(&s[i]);
	return (ret);
}

void			ft_fill_width(t_find *f, t_flags *box)
{
	size_t		i;

	i = f->va;
	while (f->s[i] && SKIP(f->s[i]))
	{
		if (f->s[i] == '.')
			return ;
		if (ft_isdigit(f->s[i]) && f->s[i] != '0')
		{
			box->wid = collect(f->s, i);
			return ;
		}
		i++;
	}
}

intmax_t		ft_atoi_m(char *str)
{
	int				sign;
	intmax_t		res;

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
