/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:12:07 by tmelia            #+#    #+#             */
/*   Updated: 2019/10/24 16:13:26 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	display_minus_f(t_printf *list, int len, char *str)
{
	int j;

	j = list->width_space;
	if (!(list->precision_space <= 0 && list->number == 0))
	{
		ft_putstr(str);
		if (list->precision_space == 0 && list->sharp == 1)
		{
			list->count++;
			ft_putchar('.');
		}
	}
	while (j-- > len)
	{
		list->count++;
		ft_putchar(' ');
	}
}

void	display_precision_f(t_printf *list)
{
	if (list->number < 0)
	{
		list->count++;
		ft_putchar('-');
	}
}

void	display_plus_f(t_printf *list)
{
	list->count++;
	list->number < 0 ? ft_putchar('-') : ft_putchar('+');
	list->number < 0 ? list->number *= (-1) : 0;
}

void	display_f2(t_printf *list, int len, char *str)
{
	if (list->plus == 1)
		display_plus_f(list);
	if (list->precision == 1)
		display_precision_f(list);
	if (list->minus == 1)
		display_minus_f(list, len, str);
	else
	{
		list->count += ft_strlen(str);
		ft_putstr(str);
		if (list->sharp == 1 && list->precision_space <= 0)
		{
			list->count++;
			ft_putchar('.');
		}
	}
}

void	display_f(t_printf *list)
{
	long double	n;
	int			len_num;
	int			len;
	char		*str;

	if (list->fl)
		n = va_arg(list->argc, long double);
	else
		n = va_arg(list->argc, double);
	len = initialze_display_f(list, n, &len_num, &str);
	if (list->space == 1 && list->plus != 1 && list->number >= 0)
		display_space_d(list, &len);
	if (list->zero == 1)
		display_zero_d(list, &len, (intmax_t *)&(list->number));
	else if (list->width == 1)
		display_width_d(list, len);
	display_f2(list, len, str);
	free(--str);
}
