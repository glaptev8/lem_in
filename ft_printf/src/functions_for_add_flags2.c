/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_for_add_flags2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:35:20 by tmelia            #+#    #+#             */
/*   Updated: 2019/11/02 14:43:55 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	add_l(t_printf *list)
{
	if (list->ll == 0)
		list->l = 1;
}

void	add_h(t_printf *list)
{
	if (list->hh == 0)
		list->h = 1;
}

void	add_ll(t_printf *list)
{
	list->ll = 1;
	list->fl = 1;
	list->l = 0;
}

void	add_hh(t_printf *list)
{
	list->hh = 1;
	list->h = 0;
}
