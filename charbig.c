/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charbig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 01:16:14 by aalokhin          #+#    #+#             */
/*   Updated: 2018/06/01 01:16:16 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char			*ft_char_wp(unsigned int ival, t_flags *box)
{
	size_t		len;
	size_t		i;
	char		*res;

	len = ft_char_len(ival);
	i = 0;
	res = NULL;
	if (box->wid > len)
	{
		res = ft_strnew(box->wid - len);
		if (box->zero)
			res = ft_memset(res, '0', box->wid - len);
		else
			res = ft_memset(res, ' ', box->wid - len);
		res[box->wid - len] = '\0';
	}
	return (res);
}

void			print_char(unsigned int ival, size_t *count)
{
	if (ival < 255)
	{
		write(1, &ival, 1);
		(*count)++;
	}
	else if (ival >= 255 && ival <= 2047)
		u2(2, ival, count);
	else if (ival > 2047 && ival <= 65535)
		u3(3, ival, count);
	else if (ival > 65535 && ival <= 1114111)
		u4(4, ival, count);
}

void			char_b(va_list ap, t_flags *box, size_t *count)
{
	unsigned int		ival;
	char				*res;

	ival = va_arg(ap, unsigned int);
	res = ft_char_wp(ival, box);
	if (!box->minus)
		ft_putstr2(res, count);
	if (MB_CUR_MAX > 1)
		print_char(ival, count);
	else
		write(1, &ival, 1);
	if (box->minus)
		ft_putstr2(res, count);
	ft_strdel(&res);
	fill_struct(box);
}
