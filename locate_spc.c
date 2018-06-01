/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate_spc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 04:24:55 by aalokhin          #+#    #+#             */
/*   Updated: 2018/06/01 04:24:57 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_found(t_find *f, va_list ap, t_flags *box)
{
	fill_struct(box);
	ft_fill_width(f, box);
	fill_precision(f->s, box, &f->va);
	ft_find_flags(f->s, box, &f->va);
	ft_find_mods(f->s, box, &f->va);
	ft_percent_sign(f, ap, box);
}

void		fill_struct(t_flags *box)
{
	(*box).hash = 0;
	(*box).zero = 0;
	(*box).space = 0;
	(*box).minus = 0;
	(*box).plus = 0;
	(*box).mod = '\0';
	(*box).sign = 0;
	(*box).wid = 0;
	(*box).pre = 0;
	(*box).dot = 0;
	(*box).specifier = 0;
}

void		percent_sign3(t_find *f, va_list ap, t_flags *box)
{
	if (f->s[f->va] == 'U')
		ft_uns_b(ap, box, &(f->count));
	else if (f->s[f->va] == 'x')
		hex_s(ap, box, &(f->count));
	else if (f->s[f->va] == 'X')
		hex_b(ap, box, &(f->count));
	else if ((f->s[f->va] == 'c' && box->mod == 'l') || f->s[f->va] == 'C')
		char_b(ap, box, &(f->count));
	else if (f->s[f->va] == 'c')
		charik(ap, box, &(f->count));
	else if (f->s[f->va] == 'p')
	{
		box->mod = 'l';
		if (box->wid > box->pre)
			box->hash = 1;
		else
			ft_putstr2("0x", &(f->count));
		hex_s(ap, box, &(f->count));
	}
	else if (f->s[f->va] == 'i')
		decimal(ap, box, &(f->count));
}

void		percent_sign2(t_find *f, va_list ap, t_flags *box)
{
	if ((f->s[f->va] == 's' && box->mod == 'l') || f->s[f->va] == 'S')
		stroka_l(ap, box, &(f->count));
	else if (f->s[f->va] == 's')
		stroka(ap, box, &(f->count));
	else if (f->s[f->va] == 'd')
		decimal(ap, box, &(f->count));
	else if (f->s[f->va] == 'D')
	{
		box->mod = 'l';
		decimal(ap, box, &(f->count));
	}
	else if (f->s[f->va] == 'o')
		octal(ap, box, &(f->count));
	else if (f->s[f->va] == 'O')
	{
		box->mod = 'l';
		octal(ap, box, &(f->count));
	}
	else if (f->s[f->va] == 'u')
		ft_uns(ap, box, &(f->count));
	else
		percent_sign3(f, ap, box);
}

void		ft_percent_sign(t_find *f, va_list ap, t_flags *box)
{
	while (f->s[f->va] != '\0' && !SPECIFIER(f->s[f->va]))
	{
		if (!(ELSE(f->s[f->va])))
		{
			ft_invalid(f->s[f->va], box, &(f->count));
			f->va += 1;
			return ;
		}
		if (f->s[f->va] == '%')
		{
			f->va += 1;
			ft_invalid('%', box, &(f->count));
			return ;
		}
		f->va++;
	}
	percent_sign2(f, ap, box);
	if (f->s[f->va] != '\0')
		f->va++;
}
