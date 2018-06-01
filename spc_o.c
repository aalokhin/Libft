/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spc_o.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 04:26:39 by aalokhin          #+#    #+#             */
/*   Updated: 2018/06/01 04:26:40 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void				ft_hash_o(char **str)
{
	int				i;
	int				j;
	char			*res;

	j = 0;
	i = 1;
	res = ft_strdup(*str);
	(*str) = ft_strnew(ft_strlen(res) + 1);
	(*str)[0] = '0';
	(*str)[1] = '\0';
	while (res[j] != '\0')
		(*str)[i++] = res[j++];
	(*str)[i] = '\0';
	ft_strdel(&res);
}

void				octal(va_list ap, t_flags *box, size_t *count)
{
	uintmax_t		ival;
	char			*res;

	ival = 0;
	ival = va_arg(ap, uintmax_t);
	if (box->dot)
		box->zero = 0;
	ft_mod_u(&ival, box);
	box->sign = 0;
	if (box->dot == 1 && box->pre == 0 && ival == 0)
		res = ft_strdup("");
	else
		res = ft_itoa_base(ival, 8);
	if ((*box).hash && !box->zero &&\
	!(box->pre == 0 && ival == 0 && !box->dot))
		ft_hash_o(&res);
	res = ft_dec_wp(res, box);
	ft_putstr2(res, count);
	ft_strdel(&res);
	fill_struct(box);
}
