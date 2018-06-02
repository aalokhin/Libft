/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:21:58 by aalokhin          #+#    #+#             */
/*   Updated: 2017/11/07 20:22:02 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	size_t i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (s1 && s2)
	{
		while (s1[i] != '\0' || s2[i] != '\0')
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
	}
	return (1);
}
