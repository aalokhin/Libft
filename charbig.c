#include "printf.h"

char			*ft_char_wp(wchar_t ival, t_flags *box)
{
	size_t		len;
	size_t		i;
	char		*res;

	len = ft_char_len(ival);
	i = 0;
	res = NULL;
	if (box->wid > len)
	{
		res = ft_strnew(box->wid - len);
		if (box->zero)
			res = ft_memset(res, '0', box->wid - len);
		else
			res = ft_memset(res, ' ', box->wid - len);
	}
	return (res);
}

void			print_char(wchar_t ival, size_t *count)
{
	if (ival <= 127)
	{
		write(1, &ival, 1);
		(*count)++;
	}
	else if (ival > 127 && ival <= 2047)
		u2(2, ival, count);
	else if (ival > 2047 && ival <= 65535)
		u3(3, ival, count);
	else if (ival > 65535 && ival <= 1114111)
		u4(4, ival, count);
}

void			char_b(va_list ap, t_flags *box, size_t *count)
{
	wchar_t		ival;
	char		*res;

	ival = va_arg(ap, wchar_t);
	res = ft_char_wp(ival, box);
	if (!box->minus)
		ft_putstr2(res, count);
	if (MB_CUR_MAX == 1 && ival <= 127)
	{
		write(1, &ival, 1);
		(*count)++;
	}
	else
		print_char(ival, count);
	if (box->minus)
		ft_putstr2(res, count);
	//ft_strdel(&res);
	fill_struct(box);
}