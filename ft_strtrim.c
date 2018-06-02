/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:11:53 by aalokhin          #+#    #+#             */
/*   Updated: 2017/11/07 20:12:17 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static size_t		ft_empty_check(char const *s)
{
	size_t		count;

	count = 0;
	while (s && *s)
	{
		if (!(*s == ' ' || *s == '\t' || *s == '\n'))
			count++;
		s++;
	}
	return (count);
}

static size_t		ft_start(char const *s)
{
	size_t		i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		if (!(s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
			return (i);
		i++;
	}
	return (i);
}

static size_t		ft_finish(char const *s)
{
	size_t		j;

	j = ft_strlen(s) - 1;
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
	{
		if (!(s[j] == ' ' || s[j] == '\t' || s[j] == '\n'))
			return (j);
		j--;
	}
	return (j);
}

char				*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		j;
	size_t		n;
	char		*trim;

	if (!s)
		return (NULL);
	i = ft_start(s);
	j = ft_finish(s);
	n = 0;
	if (*s == '\0')
		return ((char *)s);
	if (ft_empty_check(s) == 0)
		return (ft_strdup(""));
	trim = (char *)malloc(sizeof(char) * ((j - i) + 2));
	if (!trim)
		return (NULL);
	while (i <= j)
	{
		trim[n] = s[i];
		n++;
		i++;
	}
	trim[n] = '\0';
	return (trim);
}
