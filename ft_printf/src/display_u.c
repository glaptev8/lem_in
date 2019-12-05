/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:00:44 by tmelia            #+#    #+#             */
/*   Updated: 2019/10/21 12:00:59 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	display_u(t_printf *list)
{
	uintmax_t	n;
	int			len;
	int			len_num;

	len = initialze_display_u(list, &n, &len_num);
	if (list->space == 1 && list->plus != 1 && list->number >= 0)
		display_space_u(list, &len);
	if (list->zero == 1)
		display_zero_u(list, &len);
	else if (list->width == 1)
		display_width_u(list, len);
	if (list->plus == 1 && list->zero == 0)
		display_plus_u(list);
	if (list->precision == 1)
		display_precision_u(list, len_num);
	if (list->minus == 1)
		display_minus_u(list, n, len);
	else if (!(list->precision_space <= 0 && n == 0 && list->precision == 1))
		ft_putnbrmax_o(n, list);
}
