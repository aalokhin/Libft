/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:17:10 by aalokhin          #+#    #+#             */
/*   Updated: 2017/11/07 20:17:22 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (n == 0)
		return (1);
	if (s1 && s2)
	{
		while (i < n && (s1[i] || s2[i]))
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
	}
	return (1);
}
