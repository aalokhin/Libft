/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 04:27:58 by aalokhin          #+#    #+#             */
/*   Updated: 2018/06/01 04:27:59 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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

size_t		ft_w_strlen(unsigned int *str)
{
	size_t		i;
	size_t		len;

	i = 0;
	len = 0;
	while (str[i] != 0)
	{
		if (str[i] < 255)
			len++;
		else if (str[i] >= 255 && str[i] <= 2047)
			len += 2;
		else if (str[i] > 2047 && str[i] <= 65535)
			len += 3;
		else if (str[i] > 65535 && str[i] <= 1114111)
			len += 4;
		i++;
	}
	return (len);
}

char		*ft_strjoin_m(char **s1, char **s2, int ch)
{
	char	*c;

	c = NULL;
	if (!(*s1) || !(*s2) || !s1 || !s2)
		return (NULL);
	c = (char*)malloc(sizeof(char) * (ft_strlen(*s1) + ft_strlen(*s2) + 1));
	if (c)
	{
		if (ch == 1)
		{
			ft_strcpy(c, *s1);
			ft_strcat(c, *s2);
		}
		else if (ch == 2)
		{
			ft_strcpy(c, *s2);
			ft_strcat(c, *s1);
		}
		ft_strdel(s1);
		ft_strdel(s2);
		return (c);
	}
	return (NULL);
}
