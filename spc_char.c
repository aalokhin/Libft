/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spc_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 04:27:21 by aalokhin          #+#    #+#             */
/*   Updated: 2018/06/01 04:27:23 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_invalid(int ival, t_flags *box, size_t *count)
{
	char	*res;

	res = ft_strnew(1);
	ft_memset(res, ival, 1);
	res[1] = '\0';
	res = ft_str_wp(res, box);
	ft_putstr2(res, count);
	ft_strdel(&res);
}

void		charik(va_list ap, t_flags *box, size_t *count)
{
	char	ival;
	char	*res;

	ival = 0;
	ival = va_arg(ap, int);
	res = ft_strnew(1);
	ft_memset(res, ival, 1);
	res[1] = '\0';
	if (ft_strcmp(res, "") == 0 && box->wid > 0)
		box->wid--;
	res = ft_str_wp(res, box);
	ft_putstr2(res, count);
	if (ival == 0)
		ft_putchar2(ival, count);
	ft_strdel(&res);
}
