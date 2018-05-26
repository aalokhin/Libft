#include "printf.h"

void				ft_hash_x(char **str)
{
	int				i;
	int				j;
	char			*res;

	j = 0;
	i = 2;
	res = ft_strdup(*str);
	(*str) = ft_strnew(ft_strlen(res) + 2);
	(*str)[0] = '0';
	(*str)[1] = 'X';
	while (res[j] != '\0')
		(*str)[i++] = res[j++];
}

void				hexb1(char **res, uintmax_t ival, t_flags *box)
{
	if (box->hash && (box->zero || box->pre > box->wid))
	{
		box->wid -= 2;
		ft_dec_wp(res, box);
		ft_hash_x(res);
	}
	else if ((box->hash && !box->zero &&\
	!(box->pre == 0 && ival == 0 && box->wid == 0)))
	{
		ft_hash_x(res);
		ft_dec_wp(res, box);
	}
	else
		ft_dec_wp(res, box);
}

void				hex_b(va_list ap, t_flags *box, size_t *count)
{
	uintmax_t		ival;
	char			*res;

	ival = 0;
	if (box->dot)
		box->zero = 0;
	ival = va_arg(ap, uintmax_t);
	ft_mod_u(&ival, box);
	box->sign = 0;
	if (box->dot == 1 && box->pre == 0 && ival == 0)
		res = ft_strdup("");
	else
		res = ft_itoa_base(ival, 16);
	hexb1(&res, ival, box);
	ft_putstr2(res, count);
	ft_strdel(&res);
	fill_struct(box);
}
