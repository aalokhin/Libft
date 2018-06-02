/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:12:26 by aalokhin          #+#    #+#             */
/*   Updated: 2017/11/07 20:13:20 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*substr;
	size_t		j;

	if (!s)
		return (NULL);
	substr = (char *)malloc(sizeof(*substr) * (len + 1));
	if (!substr)
		return (NULL);
	else
	{
		j = 0;
		while (j < len && s[start])
		{
			substr[j] = s[start];
			j++;
			start++;
		}
		substr[j] = '\0';
		return (substr);
	}
}
