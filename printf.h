#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include <stdarg.h>
# include <stdio.h>

# define MOD(c) (c == 'h' || c == 'l' || c == 'j' || c == 'z')

# define SPECIFIER(c) (c == 'd' || c == 'D'|| c == 'i' ||\
 c == 'c' || c == 'C' || c == 's' || c == 'S' || c == 'u' ||\
 c == 'U' || c == 'x' || c == 'X' || c == 'o' || c == 'O' || c == 'p')

# define FLAGS(a) (a == '#' || a == '0' || a == ' ' || a == '-' || a == '+')

# define ELSE(c) (FLAGS(c) || c == '.' || c == '%' || MOD(c) || ft_isdigit(c))

# define SKIP(c) (FLAGS(c) || c == '.' || MOD(c) || ft_isdigit(c)) //not a specifier or else

typedef	struct	s_find
{
	char		*s;
	int			va;
	size_t		count;
}				t_find;

typedef struct	s_flags
{
	int			hash;
	int			zero;
	int			space;
	int			minus;
	int			plus;
	char		mod;
	char		sign;
	size_t		wid;
	size_t		pre;
	int			dot;
	char		specifier;
}				t_flags;

void			dec2(int len, char **res, t_flags *box);
void			dec1(intmax_t *ival, t_flags *box);
void			fill_mods(char *str, int i, t_flags *box);
int				collect(char *str, int i);
void			ft_uns(va_list ap, t_flags *box, size_t *count);
void			ft_invalid(int	ival, t_flags *box, size_t *count);
char			*ft_chr_wp(char	*ival, t_flags *box);
void			print_char(wchar_t ival, size_t	*count);
void			ft_mod_u(uintmax_t *n, t_flags *box);
void			ft_uns(va_list ap, t_flags *box, size_t *count);
void			ft_uns_b(va_list ap, t_flags *box, size_t *count);
void			u2(int bytes, wchar_t s, size_t *count);
void			u3(int bytes, wchar_t s, size_t *count);
void			u4(int bytes, wchar_t s, size_t *count);
void			print_us(wchar_t *s, size_t *count);
size_t			ft_w_strlen(wchar_t *str);
char			*ft_ls_wp(wchar_t *ival, t_flags *box);
void			stroka_l(va_list ap, t_flags *box, size_t *count);
size_t			ft_char_len(wchar_t c);
void			char_b(va_list ap, t_flags *box, size_t *count);
void			hex_s(va_list ap, t_flags *box, size_t *count);
void			hex_b(va_list ap, t_flags *box, size_t *count);
char			*ft_itoa_base_small(uintmax_t value, int base);
void			ft_hash_xs(char **str);
void			ft_print_struct(t_flags *box);
void			percent(t_flags *box, size_t *count);
char			*ft_str_wp(char	*ival, t_flags *box);
void			stroka(va_list ap, t_flags *box, size_t *count);
void			ft_hash_x(char **str);
void			octal(va_list ap, t_flags *box, size_t *count);
void			ft_hash_o(char **str);
void			fill_struct(t_flags *box);
void			ft_putchar2(char c, size_t *count);
int				ft_m_putchar(t_find	*p);
void			ft_putstr2(char const *s, size_t *count);
void			ft_m_putnbr1(unsigned long long n, size_t *count);
void			ft_m_putnbr(int n, size_t *count);
char			*ft_strnew(size_t size);
void			charik(va_list ap, t_flags *box, size_t *count);
void			ft_pre(intmax_t n, size_t *count, t_flags *box);
void			ft_dec_wp(char	**res, t_flags *box);
void			ft_mod(intmax_t *n, t_flags *box);
void			decimal(va_list ap, t_flags *box, size_t *count);
void			ft_percent_sign(t_find	*f, va_list ap, t_flags *box);
void			ft_fill_width(t_find *f, t_flags *box);
void			fill_precision(char *str, t_flags *box, int *vasia);
void			ft_find_flags(char *str, t_flags *box, int *vasia);
void			ft_find_mods(char *str, t_flags *box, int *vasia);
void			ft_found(t_find *f, va_list ap, t_flags *box);
void			fill_flags(char *str, int i, t_flags *box);
int				ft_printf(const char *format, ...);
char			*ft_itoa_m(intmax_t value);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
int				ft_strcmp(const char *s11, const char *s22);
int				ft_isdigit(int c);
void			ft_strdel(char **as);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strjoin(char const *s1, char const *s2);
void			*ft_memset(void *str, int c, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_itoa_base(uintmax_t value, int base);
void			*ft_memalloc(size_t size);
void			*ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
int				ft_atoi(const char *str);

#endif
