/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:18:54 by aalokhin          #+#    #+#             */
/*   Updated: 2017/11/07 20:19:10 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*c;

	if (!s1 || !s2)
		return (NULL);
	c = (char *)malloc(sizeof(char*) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (c)
	{
		ft_strcpy(c, s1);
		ft_strcat(c, s2);
		return (c);
	}
	return (NULL);
}
