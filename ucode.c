/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ucode.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 04:25:04 by aalokhin          #+#    #+#             */
/*   Updated: 2018/06/01 04:25:07 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			u2(int bytes, unsigned int s, size_t *count)
{
	int				i;
	unsigned int	res[bytes];
	unsigned char	oct[2];
	unsigned int	m;

	m = 49280;
	i = 0;
	oct[1] = (s << 26) >> 26;
	oct[0] = ((s >> 6) << 27) >> 27;
	res[0] = (m >> 8) | oct[0];
	res[1] = ((m << 24) >> 24) | oct[1];
	res[2] = '\0';
	while (i < bytes)
	{
		write(1, &res[i], 1);
		(*count)++;
		i++;
	}
}

void			u3(int bytes, unsigned int s, size_t *count)
{
	int				i;
	unsigned int	res[bytes];
	unsigned char	oct[3];
	unsigned int	m;

	m = 14712960;
	i = 0;
	oct[2] = (s << 26) >> 26;
	oct[1] = ((s >> 6) << 26) >> 26;
	oct[0] = ((s >> 12) << 28) >> 28;
	res[0] = (m >> 16) | oct[0];
	res[1] = ((m << 16) >> 24) | oct[1];
	res[2] = ((m << 24) >> 24) | oct[2];
	while (i < bytes)
	{
		write(1, &res[i], 1);
		(*count)++;
		i++;
	}
}

void			u4(int bytes, unsigned int s, size_t *count)
{
	int				i;
	unsigned int	res[bytes];
	unsigned char	oct[4];
	unsigned int	m;

	m = 4034953344;
	i = 0;
	oct[3] = (s << 26) >> 26;
	oct[2] = ((s >> 6) << 26) >> 26;
	oct[1] = ((s >> 12) << 26) >> 26;
	oct[0] = ((s >> 18) << 29) >> 29;
	res[0] = (m >> 24) | oct[0];
	res[1] = ((m << 8) >> 24) | oct[1];
	res[2] = ((m << 16) >> 24) | oct[2];
	res[3] = ((m << 24) >> 24) | oct[3];
	while (i < bytes)
	{
		write(1, &res[i], 1);
		(*count)++;
		i++;
	}
}

void			print_us(unsigned int *s, size_t *count)
{
	size_t		i;
	size_t		len;

	i = 0;
	len = ft_w_strlen(s);
	while (s[i] != '\0' && i < len)
	{
		if (MB_CUR_MAX == 1 && s[i] < 255)
		{
			write(1, &s[i], 1);
			(*count)++;
		}
		else if (MB_CUR_MAX == 1)
			return ;
		else if (s[i] >= 255 && s[i] <= 2047)
			u2(2, s[i], count);
		else if (s[i] > 2047 && s[i] <= 65535)
			u3(3, s[i], count);
		else if (s[i] > 65535 && s[i] <= 1114111)
			u4(4, s[i], count);
		i++;
	}
}

size_t			ft_char_len(unsigned int c)
{
	size_t		len;

	len = 0;
	if (c < 255)
		len++;
	else if (c >= 255 && c <= 2047)
		len += 2;
	else if (c > 2047 && c <= 65535)
		len += 3;
	else if (c > 65535 && c <= 1114111)
		len += 4;
	return (len);
}
