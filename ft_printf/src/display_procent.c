/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_procent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:00:10 by tmelia            #+#    #+#             */
/*   Updated: 2019/10/21 12:00:13 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	display_procent(t_printf *list)
{
	if (list->width_space > 0)
		list->count += list->width_space - 1;
	if (list->minus == 1)
	{
		ft_putchar('%');
		while (list->width_space-- > 1)
			ft_putchar(' ');
	}
	else if (list->zero == 1)
	{
		while (list->width_space-- > 1)
			ft_putchar('0');
		ft_putchar('%');
	}
	else
	{
		while (list->width_space-- > 1)
			ft_putchar(' ');
		ft_putchar('%');
	}
	list->count++;
}
