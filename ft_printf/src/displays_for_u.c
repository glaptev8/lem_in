/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays_for_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:23:21 by tmelia            #+#    #+#             */
/*   Updated: 2019/10/21 12:23:23 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	display_zero_u(t_printf *list, int *len)
{
	int		i;

	i = list->width_space;
	while (i-- > *len)
	{
		if (list->plus == 1)
		{
			list->count++;
			list->plus = 0;
		}
		list->count++;
		ft_putchar('0');
	}
}

void	display_width_u(t_printf *list, int len)
{
	int		i;

	i = list->width_space;
	while (i-- > len)
	{
		list->count++;
		ft_putchar(' ');
	}
}

void	display_plus_u(t_printf *list)
{
	list->count++;
}

void	display_precision_u(t_printf *list, int len_num)
{
	int i;

	i = 0;
	while (i++ < list->precision_space - len_num)
	{
		list->count++;
		ft_putchar('0');
	}
}

void	display_minus_u(t_printf *list, uintmax_t n, int len)
{
	int i;

	i = list->width_space;
	if (list->u == 1)
		ft_putnbrmax_o(n, list);
	else
		ft_putnbrmax(n, list);
	while (i-- > len)
	{
		list->count++;
		ft_putchar(' ');
	}
}
