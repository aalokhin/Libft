#include "printf.h"

char			*ft_str_wp(char *ival, t_flags *box)
{
	size_t		len;
	char		*pre;
	char		*r;

	len = ft_strlen(ival);
	r = NULL;
	if (box->pre < len && box->pre != 0 && len != 0)
	{
		r = ft_strnew(box->pre);
		ft_strncpy(r, ival, box->pre);
		r[box->pre] = '\0';
	}
	else
		r = ft_strdup(ival);
	if (box->wid > (len = ft_strlen(r)))
	{
		pre = ft_strnew(box->wid - len);
		if (box->zero)
			pre = ft_memset(pre, '0', box->wid - len);
		else
			pre = ft_memset(pre, ' ', box->wid - len);
		r = (box->minus) ? ft_strjoin(r, pre) : ft_strjoin(pre, r);
	}
	ft_strdel(&pre);
	return (r);
}

void			stroka(va_list ap, t_flags *box, size_t *count)
{
	char		*res;
	char		*ival;

	ival = NULL;
	ival = va_arg(ap, char*);
	if (box->pre == 0 && box->dot == 1)
		ival = ft_strdup("");
	if (ival == NULL)
		res = ft_strdup("(null)");
	else
		res = ft_str_wp(ival, box);
	ft_putstr2(res, count);
	////ft_strdel(&res);
	fill_struct(box);
}
