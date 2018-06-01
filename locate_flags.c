/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 04:24:46 by aalokhin          #+#    #+#             */
/*   Updated: 2018/06/01 04:24:49 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			ft_find_flags(char *str, t_flags *box, size_t *vasia)
{
	int		i;

	i = (*vasia);
	while (str[i] && SKIP(str[i]))
	{
		if (FLAGS(str[i]))
			fill_flags(str, i, box);
		if (ft_isdigit(str[i]) && str[i] != '0')
			while (ft_isdigit(str[i]))
				i++;
		if (FLAGS(str[i]))
			fill_flags(str, i, box);
		i++;
	}
}

void			fill_mods(char *str, size_t i, t_flags *box)
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

void			fill_flags(char *str, size_t i, t_flags *box)
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

void			ft_find_mods(char *str, t_flags *box, size_t *vasia)
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
