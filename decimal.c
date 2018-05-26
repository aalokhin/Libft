/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 14:56:47 by aalokhin          #+#    #+#             */
/*   Updated: 2018/05/26 14:56:49 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			dec2(int len, char **res, t_flags *box)
{
	char	*pre;

	pre = NULL;
	if (box->sign != 0)
	{
		pre = ft_strnew(1);
		ft_memset(pre, box->sign, 1);
		pre[1] = '\0';
		(*res) = ft_strjoin(pre, *res);
		ft_strdel(&pre);
	}
	if ((int)box->wid > (len = ft_strlen(*res)))
	{
		pre = ft_strnew(box->wid - len);
		ft_memset(pre, ' ', box->wid - len);
		pre[box->wid - len] = '\0';
		if (box->minus)
			(*res) = ft_strjoin(*res, pre);
		else
			(*res) = ft_strjoin(pre, *res);
		ft_strdel(&pre);
	}
}

void			ft_dec_wp(char **res, t_flags *box)
{
	int		len;
	char	*pre;

	len = ft_strlen(*res);
	if (box->zero != 0)
	{
		if (box->sign != 0)
			box->wid--;
		box->pre = box->wid;
	}
	if ((int)box->pre > len)
	{
		pre = ft_strnew(box->pre - len);
		ft_memset(pre, '0', box->pre - len);
		pre[box->pre - len] = '\0';
		(*res) = ft_strjoin(pre, *res);
		ft_strdel(&pre);
	}
	dec2(len, res, box);
}

void			dec1(intmax_t *ival, t_flags *box)
{
	if ((*ival) < 0)
	{
		box->sign = '-';
		(*ival) = -(*ival);
	}
	else
	{
		if (box->plus == 1)
			box->sign = '+';
		if (box->space == 1)
			box->sign = ' ';
	}
}

void			decimal(va_list ap, t_flags *box, size_t *count)
{
	intmax_t	ival;
	uintmax_t	ival2;
	char		*res;

	if (box->dot)
		box->zero = 0;
	ival = va_arg(ap, intmax_t);
	ft_mod(&ival, box);
	dec1(&ival, box);
	ival2 = (uintmax_t)ival;
	if (box->dot == 1 && box->pre == 0 && ival == 0)
		res = ft_strdup("");
	else
		res = ft_itoa_base((uintmax_t)ival2, 10);
	ft_dec_wp(&res, box);
	ft_putstr2(res, count);
	fill_struct(box);
	//ft_strdel(&res);
}
