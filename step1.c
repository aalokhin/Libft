/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 14:57:02 by aalokhin          #+#    #+#             */
/*   Updated: 2018/05/26 14:57:04 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		fill_precision(char *str, t_flags *box, size_t *vasia)
{
	size_t		i;

	i = (*vasia);
	while (str[i] && str[i] != '.')
	{
		if (!(SKIP(str[i])) || SPECIFIER(str[i]))
			return ;
		i++;
	}
	if (str[i] == '.')
		box->dot = 1;
	while (str[i] && !(!(SKIP(str[i])) || SPECIFIER(str[i])))
		i++;
	while (str[i - 1] && str[i - 1] != '.')
		i--;
	box->pre = collect(str, i);
}

size_t			collect(char *s, size_t i)
{
	size_t		len;
	char		*nbr;
	intmax_t	ret;

	len = 0;
	nbr = NULL;
	ret = 0;
	while (s[i] && ft_isdigit(s[i]))
	{
		len++;
		i++;
	}
	while (s[i] && !(ft_isdigit(s[i])))
		i--;
	if (!(nbr = ft_strnew(len)))
		return (0);
	nbr[len] = '\0';
	while (s[i] && ft_isdigit(s[i]))
	{
		nbr[--len] = s[i];
		i--;
	}
	if (nbr)
		ret = ft_atoi_m(nbr);
	

	//ft_strdel(&nbr); //ftprintf.com
	return (ret);
}

void		ft_fill_width(t_find *f, t_flags *box)
{
	size_t		i;

	i = f->va;
	while (f->s[i] && SKIP(f->s[i]))
	{
		if (f->s[i] == '.')
			return ;
		if (ft_isdigit(f->s[i]) && f->s[i] != '0')
		{
			box->wid = collect(f->s, i);
			return ;
		}
		i++;
	}
}

void		fill_mods(char *str, size_t i, t_flags *box)
{
	while (str[i] && MOD(str[i]))
	{
		if (str[i] == 'h' && str[i + 1] == 'h')
		{
			box->mod = (box->mod == 0) ? 'H' : box->mod;
			i++;
		}
		else if (str[i] == 'h')
			box->mod = (box->mod == 0 || box->mod == 'H') ? 'h' : box->mod;
		else if (str[i] == 'l' && str[i + 1] == 'l')
		{
			box->mod = (box->mod != 'j' && box->mod != 'z') ? 'L' : box->mod;
			i++;
		}
		else if (str[i] == 'l')
			box->mod = (box->mod == 0 || box->mod == 'h' || box->mod == 'H')\
		? 'l' : box->mod;
		else if (str[i] == 'j')
			box->mod = (box->mod != 'z') ? 'j' : box->mod;
		else if (str[i] == 'z')
			box->mod = 'z';
		i++;
	}
}

void		fill_flags(char *str, size_t i, t_flags *box)
{
	if (str[i] == '#')
		(*box).hash = 1;
	if (str[i] == '0' && (*box).minus == 0)
		(*box).zero = 1;
	if (str[i] == ' ' && !(*box).plus)
		(*box).space = 1;
	if (str[i] == '-')
	{
		(*box).zero = 0;
		(*box).minus = 1;
	}
	if (str[i] == '+')
	{
		(*box).space = 0;
		(*box).plus = 1;
	}
}

void		ft_find_mods(char *str, t_flags *box, size_t *vasia)
{
	size_t		i;

	i = (*vasia);
	while (str[i] && SKIP(str[i]))
	{
		if (MOD(str[i]))
		{
			fill_mods(str, i, box);
			return ;
		}
		i++;
	}
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
