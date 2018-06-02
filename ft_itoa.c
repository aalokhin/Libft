/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:00:02 by aalokhin          #+#    #+#             */
/*   Updated: 2017/11/07 21:00:05 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static size_t		ft_count(int n)
{
	size_t	count;

	count = 0;
	if (n < 0)
	{
		count = 2;
		n = -n;
	}
	else
		count = 1;
	while (n / 10)
	{
		n = n / 10;
		count++;
	}
	count = count + 1;
	return (count);
}

static int			to_power(int n)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	while (count > 0)
	{
		i = i * 10;
		count--;
	}
	return (i);
}

static char			*create(size_t count, size_t j, int n)
{
	char	*res;

	if (!(res = (char *)malloc(sizeof(char) * ft_count(n))))
		return (NULL);
	if (n < 0)
	{
		res[j++] = '-';
		if (n == -2147483648)
		{
			res[j++] = '2';
			n = -147483648;
		}
		n *= -1;
	}
	count = to_power(n);
	while (count >= 10)
	{
		res[j++] = (n / count) + '0';
		n = n % count;
		count = count / 10;
	}
	if (count == 1)
		res[j++] = n + '0';
	res[j] = '\0';
	return (res);
}

char				*ft_itoa(int n)
{
	size_t	count;
	size_t	j;
	char	*res;

	j = 0;
	count = 0;
	res = create(count, j, n);
	return (res);
}
