/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:58:02 by aalokhin          #+#    #+#             */
/*   Updated: 2017/11/07 20:58:12 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	size_t	i;
	size_t	l;

	if (!s || !f)
		return ;
	i = 0;
	l = ft_strlen(s);
	while (i < l)
	{
		f(&s[i]);
		i++;
	}
}
