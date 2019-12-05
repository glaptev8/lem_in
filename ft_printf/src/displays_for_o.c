/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays_for_o.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:22:23 by tmelia            #+#    #+#             */
/*   Updated: 2019/10/21 12:22:24 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	display_zero_o(t_printf *list, int *len)
{
	int		i;
	int		len_num;

	len_num = *len;
	if (list->precision == 1 && list->sharp == 1)
		len_num++;
	if ((list->is_0x == 1 || list->is_o == 1) && list->sharp == 1)
	{
		display_sharp_o(list, len);
		list->sharp = 0;
	}
	i = list->width_space;
	if (list->precision == 0 && list->sharp == 0 && list->zero == 1 && \
				list->number_o == 0)
		len_num = 1;
	while (i-- > len_num)
	{
		list->count++;
		ft_putchar('0');
	}
}

void	display_width_o(t_printf *list, int len)
{
	int		i;

	i = list->width_space;
	if (list->sharp == 1 && list->is_o && list->number_o == 0)
		len--;
	else if (list->sharp == 1 && list->is_0x && list->number_o == 0)
		len -= 2;
	while (i-- > len)
	{
		list->count++;
		ft_putchar(' ');
	}
}

void	display_sharp_o(t_printf *list, int *len)
{
	if (list->is_0x)
	{
		if (list->number_o == 0)
			*len -= 2;
		else
		{
			list->count += 2;
			list->xx == 1 ? ft_putstr("0X") : ft_putstr("0x");
		}
	}
}

void	display_precision_o(t_printf *list, int len_num)
{
	int i;

	i = 0;
	if (list->precision == 1 && list->sharp == 1)
		len_num++;
	if (list->sharp == 1 && list->is_0x)
		i = -1;
	while (i++ < list->precision_space - len_num)
	{
		list->count++;
		ft_putchar('0');
	}
}

void	display_minus_o(t_printf *list, int len)
{
	int i;

	i = list->width_space;
	if (!(list->sharp == 1 && list->number_o == 0))
		ft_putnbrmax_o(list->number_o, list);
	while (i-- > len)
	{
		list->count++;
		ft_putchar(' ');
	}
}
