/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 18:52:22 by cjosue            #+#    #+#             */
/*   Updated: 2019/10/15 18:56:23 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		display_c(t_printf *list)
{
	char	sym;

	sym = va_arg(list->argc, int);
	if (list->width_space > 0)
		list->count += list->width_space - 1;
	if (list->minus == 1)
	{
		ft_putchar(sym);
		while (list->width_space-- > 1)
			ft_putchar(' ');
	}
	else if (list->zero == 1)
	{
		while (list->width_space-- > 1)
			ft_putchar('0');
		ft_putchar(sym);
	}
	else
	{
		while (list->width_space-- > 1)
			ft_putchar(' ');
		ft_putchar(sym);
	}
	list->count++;
}
