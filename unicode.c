#include "printf.h"

void			u2(int bytes, wchar_t s, size_t *count)
{
	int			i;
	int			shift;
	int			res[4];

	i = 0;
	shift = 6 * (bytes - 1);
	while (i < bytes)
	{
		res[i] = s >> shift;
		if (i == 0)
			res[i] = (res[i] & 63) + 192;
		else
			res[i] = (res[i] & 63) + 128;
		shift -= 6;
		i++;
	}
	i = 0;
	while (i < bytes)
	{
		write(1, &res[i], 1);
		(*count)++;
		i++;
	}
}

void			u3(int bytes, wchar_t s, size_t *count)
{
	int			i;
	int			shift;
	int			res[4];

	i = 0;
	shift = 12;
	while (i < bytes)
	{
		res[i] = s >> shift;
		if (i == 0)
			res[i] = (res[i] & 15) + 224;
		else
			res[i] = (res[i] & 63) + 128;
		shift -= 6;
		i++;
	}
	i = 0;
	while (i < bytes)
	{
		write(1, &res[i], 1);
		(*count)++;
		i++;
	}
}

void			u4(int bytes, wchar_t s, size_t *count)
{
	int			i;
	int			shift;
	int			res[4];

	i = 0;
	shift = 18;
	while (i < bytes)
	{
		res[i] = s >> shift;
		if (i == 0)
			res[i] = (res[i] & 7) + 240;
		else
			res[i] = (res[i] & 63) + 128;
		shift -= 6;
		i++;
	}
	i = 0;
	while (i < bytes)
	{
		write(1, &res[i], 1);
		(*count)++;
		i++;
	}
}

void			print_us(wchar_t *s, size_t *count)
{
	size_t		i;
	size_t		len;

	i = 0;
	len = ft_w_strlen(s);
	while (s[i] != '\0' && i < len)
	{
		if (s[i] <= 127 && i < len)
		{
			write(1, &s[i], 1);
			(*count)++;
		}
		else if (s[i] > 127 && s[i] <= 2047)
			u2(2, s[i], count);
		else if (s[i] > 2047 && s[i] <= 65535)
			u3(3, s[i], count);
		else if (s[i] > 65535 && s[i] <= 1114111)
			u4(4, s[i], count);
		i++;
	}
}

size_t			ft_char_len(wchar_t c)
{
	size_t		len;

	len = 0;
	if (c <= 127)
		len++;
	else if (c > 127 && c <= 2047)
		len += 2;
	else if (c > 2047 && c <= 65535)
		len += 3;
	else if (c > 65535 && c <= 1114111)
		len += 4;
	return (len);
}

size_t			ft_w_strlen(wchar_t *str)
{
	size_t		i;
	size_t		len;

	i = 0;
	len = 0;
	while (str[i] != 0)
	{
		if (str[i] <= 127)
			len++;
		else if (str[i] > 127 && str[i] <= 2047)
			len += 2;
		else if (str[i] > 2047 && str[i] <= 65535)
			len += 3;
		else if (str[i] > 65535 && str[i] <= 1114111)
			len += 4;
		i++;
	}
	return (len);
}
