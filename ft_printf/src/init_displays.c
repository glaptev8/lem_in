/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_displays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:36:22 by tmelia            #+#    #+#             */
/*   Updated: 2019/10/21 13:35:38 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		initialze_display_d(t_printf *list, intmax_t *n, int *len_num)
{
	int len;

	*n = get_number_for_d(list);
	list->number = *n;
	len = get_number_len(*n, *list);
	*len_num = len;
	if (list->minus == 1 || (list->precision == 1 && list->precision_space > 0))
	{
		if (list->zero == 1)
			list->width = 1;
		list->zero = 0;
	}
	if (list->minus == 1)
		list->width = 0;
	len += (list->precision_space > len ? list->precision_space - len : 0);
	if ((list->number < 0 || list->plus == 1) &&
			(list->precision_space > *len_num - 1))
		len++;
	if ((list->precision != 1 && list->number == 0))
		len++;
	return (len);
}

int		initialze_display_f(t_printf *list, long double n,
		int *len_num, char **str)
{
	int len;
	int i;

	i = 0;
	(list->precision == 0) ? list->precision_space = 6 : 0;
	(list->precision == 0) ? list->precision = 1 : 0;
	list->precision_space == 10 ? n = (double)n : 0;
	*str = ft_l_ftoa(n, list->precision_space);
	if (list->precision_space <= 0)
		*ft_strchr(*str, '.') = '\0';
	list->number = (*str[0] == '-') ? -1 : 1;
	len = ft_strlen(++(*str));
	*len_num = len;
	if (list->minus == 1)
	{
		list->zero == 1 ? list->width = 1 : 0;
		list->zero = 0;
	}
	(list->sharp == 1 && list->precision_space <= 0) ? len++ : 0;
	if (list->minus == 1)
		list->width = 0;
	(list->plus == 1 || n < 0) ? len++ : 0;
	return (len);
}

int		initialze_display_u(t_printf *list, uintmax_t *n, int *len_num)
{
	int len;

	*n = get_number_for_o(list);
	list->space = 0;
	list->plus = 0;
	list->u = 1;
	list->number_o = *n;
	len = get_number_len_for_uint(*n);
	*len_num = (*n == 0 && list->precision_space > 0) ? 1 : len;
	if (list->precision == 1 || list->minus == 1)
	{
		if (list->zero == 1)
			list->width = 1;
		list->zero = 0;
	}
	if (list->minus == 1)
		list->width = 0;
	len += (list->precision_space > len ?
			list->precision_space - len : 0);
	if ((list->number < 0 || list->plus == 1) &&
			(list->precision_space > *len_num - 1))
		len++;
	if ((list->precision != 1 && list->number_o == 0))
		len++;
	return (len);
}

int		initialze_display_x(t_printf *list, int *len_num)
{
	int		len;
	char	*n;

	list->is_0x = 1;
	list->number_o = get_number_for_o(list);
	n = converter_16(list->number_o, list);
	len = get_number_len_for_16(list->number_o);
	if (n[0] == '0' && len == 0)
		if (!(list->precision == 1 && list->precision_space <= 0))
			len = 1;
	*len_num = len;
	if (list->precision == 1 || list->minus == 1)
	{
		(list->zero == 1) ? list->width = 1 : 0;
		list->zero = 0;
	}
	(list->minus == 1) ? list->width = 0 : 0;
	len += (list->precision_space > len ? list->precision_space - len : 0);
	if (list->sharp == 1)
	{
		(list->is_o == 1) ? len++ : 0;
		(list->is_0x == 1) ? len += 2 : 0;
	}
	free(n);
	return (len);
}
