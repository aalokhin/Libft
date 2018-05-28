#include "printf.h"

void	fill_struct(t_flags *box)
{
	(*box).hash = 0;
	(*box).zero = 0;
	(*box).space = 0;
	(*box).minus = 0;
	(*box).plus = 0;
	(*box).mod = '\0';
	(*box).sign = 0;
	(*box).wid = 0;
	(*box).pre = 0;
	(*box).dot = 0;
	(*box).specifier = 0;
}

void		ft_print_struct(t_flags *box)
{
	printf("\n");
	printf("hash: %d\n", (*box).hash);
	printf("zero: %d\n", (*box).zero);
	printf("space: %d\n", (*box).space);
	printf("minus: %d\n", (*box).minus);
	printf("plus: %d\n", (*box).plus);
	printf("mod: %c\n", (*box).mod);
	printf("wid: %zu\n", (*box).wid);
	printf("pre: %zu\n", (*box).pre);
	printf("dot: %d\n", (*box).dot);
	printf("sign: %c\n", (*box).sign);
	printf("mod: %c\n", (*box).specifier);
}
