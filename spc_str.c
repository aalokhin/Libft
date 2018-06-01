/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spc_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 04:25:34 by aalokhin          #+#    #+#             */
/*   Updated: 2018/06/01 04:25:36 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char			*ft_str_wp(char *ival, t_flags *box)
{
	t_l			h;

	h.len = ft_strlen(ival);
	h.res = NULL;
	if (box->pre < h.len && box->pre != 0 && h.len != 0)
	{
		h.res = ft_strnew(box->pre);
		ft_strncpy(h.res, ival, box->pre);
		h.res[box->pre] = '\0';
	}
	else
		h.res = ft_strdup(ival);
	if (box->wid > (h.len = ft_strlen(h.res)))
	{
		h.pre = ft_strnew(box->wid - h.len);
		if (box->zero)
			h.pre = ft_memset(h.pre, '0', box->wid - h.len);
		else
			h.pre = ft_memset(h.pre, ' ', box->wid - h.len);
		h.pre[box->wid - h.len] = '\0';
		h.res = (box->minus) ? ft_strjoin_m(&h.res, &h.pre, 1)\
		: ft_strjoin_m(&h.res, &h.pre, 2);
	}
	ft_strdel(&ival);
	return (h.res);
}

void			stroka(va_list ap, t_flags *box, size_t *count)
{
	char		*res;
	char		*ival;
	char		*tmp;

	ival = NULL;
	res = NULL;
	tmp = va_arg(ap, char*);
	if (box->pre == 0 && box->dot == 1)
		ival = ft_strdup("");
	else if (tmp == NULL)
		ival = ft_strdup("(null)");
	else
		ival = ft_strdup(tmp);
	res = ft_str_wp(ival, box);
	ft_putstr2(res, count);
	ft_strdel(&res);
	fill_struct(box);
}
