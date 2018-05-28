/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 14:59:07 by aalokhin          #+#    #+#             */
/*   Updated: 2018/05/26 14:59:10 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int					ft_printf(const char *format, ...)
{
	va_list			ap;
	t_find			p;
	t_flags			box;

	va_start(ap, format);
	fill_struct(&box);
	p.s = (char*)format;
	p.va = 0;
	p.count = 0;
	while (p.s[p.va])
	{
		if (p.s[p.va] == '%')
		{
			fill_struct(&box);
			p.va += 1;
			ft_found(&p, ap, &box);
		}
		else
			ft_m_putchar(&p);
	}
	va_end(ap);
	return (p.count);
}
