/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:16:35 by aalokhin          #+#    #+#             */
/*   Updated: 2017/11/07 20:17:02 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnew(size_t size)
{
	char		*str;
	size_t		i;

	i = 0;
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (str && str[i])
	{
		str[i] = '\0';
		i++;
	}
	i = '\0';
	return (str);
}
