/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:22:52 by aalokhin          #+#    #+#             */
/*   Updated: 2017/11/07 20:23:00 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	size_t			l;

	if (!s || !f)
		return ;
	i = 0;
	l = ft_strlen(s);
	while (i < l)
	{
		f(i, &s[i]);
		i++;
	}
}
