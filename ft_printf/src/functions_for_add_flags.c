/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_for_add_flags.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:32:52 by tmelia            #+#    #+#             */
/*   Updated: 2019/10/21 12:35:10 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	add_plus(t_printf *list)
{
	list->space = 0;
	list->plus = 1;
	while (list->format[list->i] == '+')
		list->i++;
	list->i--;
}

void	add_space(t_printf *list)
{
	if (list->plus != 1)
		list->space = 1;
	while (list->format[list->i] == ' ')
		list->i++;
	list->i--;
}

void	add_precision(t_printf *list)
{
	char *num;

	list->precision = 1;
	list->precision_space = 0;
	if (list->format[list->i + 1] == '*')
	{
		list->precision_space = va_arg(list->argc, int);
		list->i++;
	}
	else if (ft_isdigit(list->format[list->i + 1]))
	{
		list->i++;
		num = list->format;
		num += list->i;
		list->precision_space = ft_atoi(num);
		while (ft_isdigit(list->format[list->i]))
			list->i++;
		list->i--;
	}
	if (list->precision_space < 0)
		list->precision = 0;
}

void	add_width(t_printf *list)
{
	char *num;

	list->width = 1;
	if (list->format[list->i] == '*')
	{
		list->width_space = va_arg(list->argc, int);
		if (list->width_space < 0)
		{
			list->width = 0;
			list->minus = 1;
			list->width_space = list->width_space * (-1);
		}
	}
	else if (ft_isdigit(list->format[list->i]))
	{
		num = list->format;
		num += list->i;
		list->width_space = ft_atoi(num);
		while (ft_isdigit(list->format[list->i]))
			list->i++;
		list->i--;
	}
}

void	add_zero(t_printf *list)
{
	char *num;

	list->zero = 1;
	if (ft_isdigit(list->format[list->i + 1]) ||
			list->format[list->i + 1] == '+')
	{
		list->i++;
		num = list->format;
		num += list->i;
		if (ft_atoi(num) != 0)
			list->width_space = ft_atoi(num);
		while (ft_isdigit(list->format[list->i]))
			list->i++;
		list->i--;
	}
}
