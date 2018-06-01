/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spc_uns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 04:25:44 by aalokhin          #+#    #+#             */
/*   Updated: 2018/06/01 04:25:45 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			ft_mod_u(uintmax_t *n, t_flags *box)
{
	if ((*box).mod == 'H')
		(*n) = (unsigned char)(*n);
	else if ((*box).mod == 'h')
		(*n) = (unsigned short)(*n);
	else if ((*box).mod == 'l')
		(*n) = (unsigned long)(*n);
	else if ((*box).mod == 'L')
		(*n) = (unsigned long long)(*n);
	else if ((*box).mod == 'j')
		return ;
	else if ((*box).mod == 'z')
		(*n) = (size_t)(*n);
	else
		(*n) = (unsigned int)(*n);
}

void			ft_mod(intmax_t *n, t_flags *box)
{
	if ((*box).mod == 'h')
		(*n) = (short)(*n);
	else if ((*box).mod == 'H')
		(*n) = (char)(*n);
	else if ((*box).mod == 'l')
		(*n) = (long)(*n);
	else if ((*box).mod == 'L')
		(*n) = (long long)(*n);
	else if ((*box).mod == 'j')
		return ;
	else if ((*box).mod == 'z')
		(*n) = (size_t)(*n);
	else
		(*n) = (int)(*n);
}

void			ft_uns_b(va_list ap, t_flags *box, size_t *count)
{
	box->mod = 'l';
	ft_uns(ap, box, count);
}

void			ft_uns(va_list ap, t_flags *box, size_t *count)
{
	uintmax_t	ival;
	char		*res;

	ival = 0;
	ival = va_arg(ap, uintmax_t);
	ft_mod_u(&ival, box);
	if (box->dot == 1 && box->pre == 0 && ival == 0)
		res = ft_strdup("");
	else
		res = ft_itoa_base(ival, 10);
	res = ft_dec_wp(res, box);
	ft_putstr2(res, count);
	ft_strdel(&res);
	fill_struct(box);
}
