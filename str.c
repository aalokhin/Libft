/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 14:56:35 by aalokhin          #+#    #+#             */
/*   Updated: 2018/05/26 14:56:37 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char			*ft_str_wp(char *ival, t_flags *box)
{
	size_t		len;
	char		*pre;
	char		*res;

	len = ft_strlen(ival);
	res = NULL;
	if (box->pre < len && box->pre != 0 && len != 0)
	{
		res = ft_strnew(box->pre);
		ft_strncpy(res, ival, box->pre);
		res[box->pre] = '\0';
	}
	else
		res = ft_strdup(ival);
	if (box->wid > (len = ft_strlen(res)))
	{
		pre = ft_strnew(box->wid - len);
		if (box->zero)
			pre = ft_memset(pre, '0', box->wid - len);
		else
			pre = ft_memset(pre, ' ', box->wid - len);
		pre[box->wid - len] = '\0';
		res = (box->minus) ? ft_strjoin_m(&res, &pre, 1) : ft_strjoin_m(&res, &pre, 2);
	}
	ft_strdel(&ival);
	return (res);
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
