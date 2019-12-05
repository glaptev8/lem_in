/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays_for_space.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:55:54 by tmelia            #+#    #+#             */
/*   Updated: 2019/10/21 13:55:56 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	display_space_d(t_printf *list, int *len)
{
	(*len)++;
	list->count++;
	ft_putchar(' ');
}

void	display_space_o(t_printf *list, int *len)
{
	(*len)++;
	list->count++;
	ft_putchar(' ');
}

void	display_space_u(t_printf *list, int *len)
{
	(*len)++;
	list->count++;
	ft_putchar(' ');
}
