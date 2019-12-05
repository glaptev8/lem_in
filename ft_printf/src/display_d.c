/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:57:14 by tmelia            #+#    #+#             */
/*   Updated: 2019/10/21 11:57:53 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

intmax_t	get_number_for_d(t_printf *list)
{
	intmax_t n;

	if (list->l == 1)
		n = va_arg(list->argc, long int);
	else if (list->ll == 1)
		n = va_arg(list->argc, long long int);
	else if (list->h == 1)
		n = (short)va_arg(list->argc, int);
	else if (list->hh == 1)
		n = (char)va_arg(list->argc, int);
	else
		n = va_arg(list->argc, int);
	n = (intmax_t)n;
	return (n);
}

void		display_d(t_printf *list)
{
	intmax_t	n;
	int			len;
	int			len_num;

	len = initialze_display_d(list, &n, &len_num);
	if (list->space == 1 && list->plus != 1 && list->number >= 0)
		display_space_d(list, &len);
	if (list->zero == 1 && list->precision != 1)
		display_zero_d(list, &len, &n);
	else if (list->width == 1)
		display_width_d(list, len);
	if (list->plus == 1 && list->zero == 0)
		display_plus_d(list, &n);
	if (list->precision == 1)
		display_precision_d(list, &n, len_num);
	if (list->minus == 1)
		display_minus_d(list, n, len);
	else if (!(list->precision_space <= 0 && n == 0 && list->precision == 1))
		ft_putnbrmax(n, list);
}
