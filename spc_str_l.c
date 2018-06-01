/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spc_str_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 04:25:27 by aalokhin          #+#    #+#             */
/*   Updated: 2018/06/01 04:25:29 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t			count_check(unsigned int *s, size_t size)
{
	size_t		i;
	size_t		check;
	size_t		len;

	check = 0;
	i = 0;
	len = ft_w_strlen(s);
	while (s[i] != '\0' && i < len)
	{
		if (s[i] < 255 && (check + 1) <= size)
			check += 1;
		else if (s[i] >= 255 && s[i] <= 2047 && (check + 2) <= size)
			check += 2;
		else if (s[i] > 2047 && s[i] <= 65535 && (check + 3) <= size)
			check += 3;
		else if (s[i] > 65535 && s[i] <= 1114111 && (check + 4) <= size)
			check += 4;
		i++;
	}
	return (size - check);
}

void			check_print(t_s *a, size_t *count)
{
	if (a->j < 255 && (a->check + 1) <= a->size)
	{
		write(1, &(a->j), 1);
		(*count)++;
		a->check += 1;
	}
	else if (a->j >= 255 && a->j <= 2047 && (a->check + 2) <= a->size)
	{
		u2(2, a->j, count);
		a->check += 2;
	}
	else if (a->j > 2047 && a->j <= 65535 && (a->check + 3) <= a->size)
	{
		u3(3, a->j, count);
		a->check += 3;
	}
	else if (a->j > 65535 && a->j <= 1114111 && (a->check + 4) <= a->size)
	{
		u4(4, a->j, count);
		a->check += 4;
	}
}

void			print_us_1(unsigned int *s, size_t *count, size_t size)
{
	t_s			a;
	size_t		i;
	size_t		len;

	a.check = 0;
	a.size = size;
	i = 0;
	len = ft_w_strlen(s);
	while (s[i] != '\0' && i < len)
	{
		a.j = s[i];
		check_print(&a, count);
		i++;
	}
}

char			*ft_ls_wp(unsigned int *ival, t_flags *box)
{
	size_t		len;
	size_t		i;
	size_t		dif;
	char		*res;

	dif = 0;
	len = ft_w_strlen(ival);
	i = 0;
	res = NULL;
	if (box->pre < len && box->pre != 0 && len != 0)
		len = box->pre;
	if (box->wid > len)
	{
		res = ft_strnew(box->wid - len);
		dif = count_check(ival, len);
		if (box->zero)
			res = ft_memset(res, '0', box->wid - len + dif);
		else
			res = ft_memset(res, ' ', box->wid - len + dif);
		res[box->wid - len + dif] = '\0';
	}
	return (res);
}

void			stroka_l(va_list ap, t_flags *box, size_t *count)
{
	size_t			len;
	char			*res;
	unsigned int	*ival;

	ival = va_arg(ap, unsigned int *);
	if (ival == NULL)
	{
		ft_putstr2("(null)", count);
		return ;
	}
	if (box->pre == 0 && box->dot == 1)
	{
		ival = ft_memalloc(1);
		ft_bzero(ival, 1);
	}
	len = ft_w_strlen(ival);
	len = (box->pre < len && box->pre != 0 && len != 0) ? box->pre : len;
	res = ft_ls_wp(ival, box);
	if (!box->minus)
		ft_putstr2(res, count);
	print_us_1(ival, count, len);
	if (box->minus)
		ft_putstr2(res, count);
	ft_strdel(&res);
	fill_struct(box);
}
