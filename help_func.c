/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 14:57:43 by aalokhin          #+#    #+#             */
/*   Updated: 2018/05/26 14:58:35 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_find_flags(char *str, t_flags *box, size_t *vasia)
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

void		ft_putchar2(char c, size_t *count)
{
	write(1, &c, 1);
	(*count)++;
}

int			ft_m_putchar(t_find *p)
{
	write(1, &((*p).s[(*p).va]), 1);
	(*p).va++;
	(*p).count++;
	return (1);
}

void		ft_putstr2(char const *s, size_t *count)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		ft_putchar2(s[i], count);
		i++;
	}
}
