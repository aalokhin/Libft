#include "printf.h"

void		ft_found(t_find *f, va_list ap, t_flags *box)
{
	fill_struct(box);
	ft_fill_width(f, box);
	fill_precision(f->s, box, &f->va);
	ft_find_flags(f->s, box, &f->va);
	ft_find_mods(f->s, box, &f->va);
	ft_percent_sign(f, ap, box);
}

void		ft_invalid(int ival, t_flags *box, size_t *count)
{
	char	*res;

	res = ft_strnew(1);
	ft_memset(res, ival, 1);
	res[1] = '\0';
	res = ft_str_wp(res, box);
	ft_putstr2(res, count);
	ft_strdel(&res);
}

void		charik(va_list ap, t_flags *box, size_t *count)
{
	char	ival;
	char	*res;

	ival = 0;
	ival = va_arg(ap, int);
	res = ft_strnew(1);
	ft_memset(res, ival, 1);
	res[1] = '\0';
	if (ft_strcmp(res, "") == 0 && box->wid > 0)
		box->wid--;
	res = ft_str_wp(res, box);
	ft_putstr2(res, count);
	ft_strdel(&res);
	if (ival == 0)
		ft_putchar2(ival, count);
}
