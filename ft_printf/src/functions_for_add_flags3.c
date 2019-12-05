/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_for_add_flags3.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:35:31 by tmelia            #+#    #+#             */
/*   Updated: 2019/10/21 12:35:57 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	add_sharp(t_printf *list)
{
	list->sharp = 1;
	while (list->format[list->i] == '#')
		list->i++;
	list->i--;
}

void	add_minus(t_printf *list)
{
	char	*num;

	list->minus = 1;
	if (ft_isdigit(list->format[list->i + 1]) ||
			list->format[list->i + 1] == '-' ||
			list->format[list->i + 1] == '+')
	{
		list->i++;
		num = list->format;
		num += list->i;
		list->width_space = ft_atoi(num);
		while (ft_isdigit(list->format[list->i]))
			list->i++;
		list->i--;
	}
}
