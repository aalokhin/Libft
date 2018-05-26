#include "printf.h"

char			*ft_str_wp(char *ival, t_flags *box)
{
	size_t		len;
	char		*pre;
	char		*res;

	len = ft_strlen(ival);
	res = NULL;
	if (box->pre < len && box->pre != 0 && len != 0)
	{
		res = ft_strnew(box->pre);
		ft_strncpy(res, ival, box->pre);
		res[box->pre] = '\0';
	}
	else
		res = ft_strdup(ival);
	if (box->wid > (len = ft_strlen(res)))
	{
		pre = ft_strnew(box->wid - len);
		if (box->zero)
			pre = ft_memset(pre, '0', box->wid - len);
		else
			pre = ft_memset(pre, ' ', box->wid - len);
		res = (box->minus) ? ft_strjoin(res, pre) : ft_strjoin(pre, res);
		ft_strdel(&pre);
	}
	return (res);
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
	//ft_strdel(&res);
	fill_struct(box);
}
