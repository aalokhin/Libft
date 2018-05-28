#include "printf.h"

size_t			count_check(wchar_t *s, size_t size)
{
	size_t		i;
	size_t		check;
	size_t		len;

	check = 0;
	i = 0;
	len = ft_w_strlen(s);
	while (s[i] != '\0' && i < len)
	{
		if (s[i] <= 127 && (check + 1) <= size)
			check += 1;
		else if (s[i] > 127 && s[i] <= 2047 && (check + 2) <= size)
			check += 2;
		else if (s[i] > 2047 && s[i] <= 65535 && (check + 3) <= size)
			check += 3;
		else if (s[i] > 65535 && s[i] <= 1114111 && (check + 4) <= size)
			check += 4;
		i++;
	}
	return (size - check);
}

void			print_us_1(wchar_t *s, size_t *count, size_t size)
{
	size_t		i;
	size_t		check;
	size_t		len;

	check = 0;
	i = 0;
	len = ft_w_strlen(s);
	while (s[i] != '\0' && i < len)
	{
		if (s[i] <= 127 && (check + 1) <= size)
		{
			write(1, &s[i], 1);
			(*count)++;
			check += 1;
		}
		else if (s[i] > 127 && s[i] <= 2047 && (check + 2) <= size)
		{
			u2(2, s[i], count);
			check += 2;
		}
		else if (s[i] > 2047 && s[i] <= 65535 && (check + 3) <= size)
		{
			u3(3, s[i], count);
			check += 3;
		}
		else if (s[i] > 65535 && s[i] <= 1114111 && (check + 4) <= size)
		{
			u4(4, s[i], count);
			check += 4;
		}
		i++;
	}
}

char			*ft_ls_wp(wchar_t *ival, t_flags *box)
{
	size_t		len;
	size_t		i;
	size_t		dif;
	char		*res;

	dif = 0;
	len = ft_w_strlen(ival);
	i = 0;
	res = NULL;
	if (box->pre < len && box->pre != 0 && len != 0)
		len = box->pre;
	if (box->wid > len)
	{
		res = ft_strnew(box->wid - len);
		dif = count_check(ival, len);
		if (box->zero)
			res = ft_memset(res, '0', box->wid - len + dif);
		else
			res = ft_memset(res, ' ', box->wid - len + dif);
		res[box->wid - len + dif] = '\0';
	}
	return (res);
}

void			stroka_l(va_list ap, t_flags *box, size_t *count)
{
	size_t		len;
	char		*res;
	wchar_t		*ival;

	ival = NULL;
	ival = va_arg(ap, wchar_t *);
	if (ival == NULL)
	{
		ft_putstr2("(null)", count);
		return ;
	}
	if (box->pre == 0 && box->dot == 1)
	{
		ival = ft_memalloc(1);
		ft_bzero(ival, 1);
	}
	len = ft_w_strlen(ival);
	if (box->pre < len && box->pre != 0 && len != 0)
		len = box->pre;
	res = ft_ls_wp(ival, box);
	if (!box->minus)
		ft_putstr2(res, count);
	print_us_1(ival, count, len);
	if (box->minus)
		ft_putstr2(res, count);
	//ft_strdel(&res);
	fill_struct(box);
}
