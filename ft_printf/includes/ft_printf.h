/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 18:10:09 by tmelia            #+#    #+#             */
/*   Updated: 2019/10/24 18:10:11 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

typedef struct			s_printf
{
	va_list				argc;
	intmax_t			number;
	uintmax_t			number_x;
	int					is_number;
	char				*format;
	void				(*add_functions[12])(struct s_printf *);
	void				(*display[11])(struct s_printf *);
	short				zero;
	int					zero_space;
	short				sharp;
	long long int		integer;
	int					decimal;
	int					zero_decimal;
	int					count;
	int					minus;
	int					width;
	int					floatminus;
	int					width_space;
	int					plus;
	int					space;
	int					precision;
	int					precision_space;
	int					minus_space;
	int					l;
	int					ll;
	int					h;
	int					hh;
	int					i;
	int					is_o;
	int					is_0x;
	int					xx;
	int					u;
	int					fl;
	uintmax_t			number_o;
}						t_printf;

int						ft_printf(const char *format, ...);
int						is_conversion(t_printf list);
int						is_flag(t_printf list);
void					add_flags(t_printf list);
void					add_width(t_printf *list);
void					add_precision(t_printf *list);
void					add_space(t_printf *list);
void					add_plus(t_printf *list);
void					add_minus(t_printf *list);
void					add_sharp(t_printf *list);
void					init_struct_functions(t_printf *l);
void					init_struct(t_printf *l);
void					display_u(t_printf *list);
void					display_s(t_printf *list);
void					display_p(t_printf *list);
void					display_o(t_printf *list);
void					display_i(t_printf *list);
void					display_d(t_printf *list);
void					display_c(t_printf *list);
void					init_display_functions(t_printf *l);
void					add_zero(t_printf *list);
void					display_xx(t_printf *list);
void					display_x(t_printf *list);
void					display_f(t_printf *list);
void					display_procent(t_printf *list);
void					add_l(t_printf *list);
void					add_ll(t_printf *list);
void					add_h(t_printf *list);
void					add_hh(t_printf *list);
intmax_t				get_number_for_d(t_printf *list);
void					ft_putnbrmax(intmax_t n, t_printf *l);
int						get_number_len(intmax_t n, t_printf list);
int						initialze_display_d(t_printf *l, intmax_t *n,
		int *len_num);
void					display_space_d(t_printf *list, int *len);
void					display_zero_d(t_printf *list, int *len, intmax_t *n);
void					display_width_d(t_printf *list, int len);
void					display_plus_d(t_printf *list, intmax_t *n);
void					display_precision_d(t_printf *list, intmax_t *n,
		int len_num);
void					display_minus_d(t_printf *list, intmax_t n, int len);
void					display_space_o(t_printf *list, int *len);
void					display_zero_o(t_printf *list, int *len);
void					display_width_o(t_printf *list, int len);
void					display_precision_o(t_printf *list, int len_num);
void					display_minus_o(t_printf *list, int len);
void					ft_putnbrmax_o(uintmax_t n, t_printf *l);
uintmax_t				converter(uintmax_t n, int base);
char					*converter_16(uintmax_t n, t_printf *list);
uintmax_t				get_number_for_o(t_printf *list);
int						initialze_display_x(t_printf *list, int *len_num);
int						get_number_len_for_16(uintmax_t n);
void					display_sharp_o(t_printf *list, int *len);
void					display_minus_x(t_printf *list, int len,
		int len_num, char *n);
void					ft_putnbrmax_x(char *n);
void					display_minus_u(t_printf *list, uintmax_t n, int len);
void					display_precision_u(t_printf *list, int len_num);
void					display_plus_u(t_printf *list);
void					display_width_u(t_printf *list, int len);
void					display_zero_u(t_printf *list, int *len);
void					display_space_u(t_printf *list, int *len);
int						get_number_len_for_uint(uintmax_t n);
void					ft_putstr_cool(char *str, long int len, t_printf *list);
int						initialze_display_u(t_printf *list, uintmax_t *n,
		int *len_num);
int						ft_pow(int n, int p);
void					display_precision_f(t_printf *list);
void					display_minus_f(t_printf *list, int len, char *str);
int						ft_pow(int n, int p);
void					ft_putnbrmax_for_f(int i, int d,
		t_printf *l, int len_num);
int						initialze_display_f(t_printf *list, long double n,
		int *len_num, char **str);
void					display_space_d(t_printf *list, int *len);
void					init_strcut2(t_printf *l);
int						ft_add_flags(t_printf *list, int *flag);
int						get_zero_decimal(char *s);
char					*ft_ftoa(double d, int pr);
char					*ft_l_ftoa(long double d,
		int pr);
char					*ft_strjoin_re(char *s1, char *s2);
char					*ft_itoa_lu(unsigned long int n, unsigned int base,
		char s);
double					ft_sign(char *num, double d);
int						ft_rounding(char *div, int i);
void					display_f2(t_printf *list, int len, char *str);
#endif
