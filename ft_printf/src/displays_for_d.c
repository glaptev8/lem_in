/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays_for_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:07:58 by tmelia            #+#    #+#             */
/*   Updated: 2019/10/21 12:08:00 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	display_zero_d(t_printf *list, int *len, intmax_t *n)
{
	int		i;

	i = list->width_space;
	if (*n < 0 || list->plus == 1)
	{
		list->count++;
		list->number < 0 ? ft_putchar('-') : ft_putchar('+');
		*n < 0 ? *n *= -1 : 0;
		list->plus = 0;
	}
	while (i-- > *len)
	{
		list->count++;
		ft_putchar('0');
	}
}

void	display_width_d(t_printf *list, int len)
{
	int		i;

	i = list->width_space;
	while (i-- > len)
	{
		list->count++;
		ft_putchar(' ');
	}
}

void	display_plus_d(t_printf *list, intmax_t *n)
{
	list->count++;
	*n < 0 ? ft_putchar('-') : ft_putchar('+');
	*n < 0 ? *n *= (-1) : 0;
}

void	display_precision_d(t_printf *list, intmax_t *n, int len_num)
{
	int i;

	i = 0;
	(list->number < 0 || list->plus == 1) ? i-- : 0;
	if (*n < 0)
	{
		list->count++;
		*n *= -1;
		ft_putchar('-');
	}
	while (i++ < list->precision_space - len_num)
	{
		list->count++;
		ft_putchar('0');
	}
}

void	display_minus_d(t_printf *list, intmax_t n, int len)
{
	int i;

	i = list->width_space;
	if (!(list->precision == 1 && list->number == 0))
	{
		if (list->u == 1)
			ft_putnbrmax_o(n, list);
		else
			ft_putnbrmax(n, list);
	}
	while (i-- > len)
	{
		list->count++;
		ft_putchar(' ');
	}
}
