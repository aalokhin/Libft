/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liba.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 15:03:05 by aalokhin          #+#    #+#             */
/*   Updated: 2018/05/26 15:03:06 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_memdel(void **ap)
{
	if (ap != NULL && *ap != NULL)
	{
		free(*ap);
		*ap = NULL;
	}
}

void	*ft_memalloc(size_t size)
{
	unsigned char	*res;

	res = (unsigned char *)malloc(sizeof(unsigned char) * size);
	if (!res)
		return (NULL);
	ft_bzero(res, size);
	return ((void *)res);
}

intmax_t	ft_atoi_m(char *str)
{
	int				sign;
	intmax_t		res;

	res = 0;
	sign = 1;
	while (*str == ' ' || *str == '\n' || *str == '\v' || *str == '\t' \
		|| *str == '\r' || *str == '\f')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = 10 * res + sign * (*str - '0');
		str++;
	}
	return (res);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char*)dst;
	s2 = (unsigned char*)src;
	i = 0;
	while (n > 0)
	{
		s1[i] = s2[i];
		n--;
		i++;
	}
	return (s1);
}

void	*ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*s2;

	i = -1;
	s2 = s;
	while (++i < n)
		s2[i] = 0;
	return (s2);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *)str;
	while (i < n)
	{
		s[i] = c;
		i++;
	}
	return ((void *)s);
}

char	*ft_strcat(char *s1, const char *s2)
{
	size_t i;

	i = ft_strlen(s1);
	while (*s2 != '\0')
	{
		s1[i] = *s2;
		i++;
		s2++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_strjoin_m(char **s1, char **s2, int ch)
{
	char	*c;

	c = NULL;
	if (!(*s1) || !(*s2) || !s1 || !s2)
		return (NULL);
	c = (char*)malloc(sizeof(char) * (ft_strlen(*s1) + ft_strlen(*s2) + 1));
	if (c)
	{
		if (ch == 1)
		{
			ft_strcpy(c, *s1);
			ft_strcat(c, *s2);
		}
		else if (ch == 2)
		{
			ft_strcpy(c, *s2);
			ft_strcat(c, *s1);
		}
		ft_strdel(s1);
		ft_strdel(s2);
		return (c);
	}
	return (NULL);
}

void	ft_strdel(char **as)
{
	if (as != NULL && *as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}

char	*ft_strdup(const char *s1)
{
	size_t		len;
	size_t		i;
	char		*s2;

	i = 0;
	len = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(*s2) * (len + 1));
	if (!s2)
		return (NULL);
	s2[len] = '\0';
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}

int		ft_strcmp(const char *s11, const char *s22)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)s11;
	s2 = (unsigned char *)s22;
	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int		ft_isdigit(int c)
{
	if (!(c >= 48 && c <= 57))
		return (0);
	return (1);
}

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (i < len && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

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
	str[i] = '\0';
	return (str);
}

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
