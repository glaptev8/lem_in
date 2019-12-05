/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:18:23 by tmelia            #+#    #+#             */
/*   Updated: 2019/10/21 12:19:41 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	display_minus_x(t_printf *list, int len, int len_num, char *n)
{
	int i;

	i = list->width_space;
	if (!(list->precision_space <= 0 &&
				list->number_o == 0 &&
				list->precision == 1))
	{
		list->count += len_num;
		ft_putnbrmax_x(n);
	}
	while (i-- > len)
	{
		list->count++;
		ft_putchar(' ');
	}
}

void	display_x(t_printf *list)
{
	char	*n;
	int		len;
	int		len_num;

	len = initialze_display_x(list, &len_num);
	n = converter_16(list->number_o, list);
	if (list->space == 1)
		display_space_o(list, &len);
	if (list->zero == 1)
		display_zero_o(list, &len);
	else if (list->width == 1)
		display_width_o(list, len);
	if (list->sharp == 1)
		display_sharp_o(list, &len);
	if (list->precision == 1)
		display_precision_o(list, len_num);
	if (list->minus == 1)
		display_minus_x(list, len, len_num, n);
	else if (!(list->precision_space <= 0 &&
				list->number_o == 0 && list->precision == 1))
	{
		list->count += len_num;
		ft_putnbrmax_x(n);
	}
	free(n);
}
