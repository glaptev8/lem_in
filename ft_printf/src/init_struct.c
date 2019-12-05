/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:56:45 by tmelia            #+#    #+#             */
/*   Updated: 2019/10/21 13:57:49 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_struct(t_printf *l)
{
	l->decimal = 0;
	l->integer = 0;
	l->minus = 0;
	l->plus = 0;
	l->is_number = 0;
	l->sharp = 0;
	l->space = 0;
	l->precision = 0;
	l->width = 0;
	l->zero = 0;
	l->number = 0;
	l->zero_space = 0;
	l->minus_space = 0;
	l->width_space = 0;
	l->precision_space = 0;
	l->zero_decimal = 0;
	init_strcut2(l);
}

void	init_strcut2(t_printf *l)
{
	l->l = 0;
	l->ll = 0;
	l->h = 0;
	l->hh = 0;
	l->is_o = 0;
	l->is_0x = 0;
	l->number_o = 0;
	l->xx = 0;
	l->u = 0;
	l->floatminus = 0;
	l->fl = 0;
}

void	init_struct_functions(t_printf *l)
{
	l->add_functions[0] = &add_minus;
	l->add_functions[1] = &add_plus;
	l->add_functions[2] = &add_sharp;
	l->add_functions[3] = &add_space;
	l->add_functions[4] = &add_precision;
	l->add_functions[5] = &add_width;
	l->add_functions[6] = &add_zero;
	l->add_functions[7] = &add_l;
	l->add_functions[8] = &add_ll;
	l->add_functions[9] = &add_h;
	l->add_functions[10] = &add_hh;
	l->add_functions[11] = &add_ll;
}

void	init_display_functions(t_printf *l)
{
	l->display[0] = &display_s;
	l->display[1] = &display_c;
	l->display[2] = &display_p;
	l->display[3] = &display_d;
	l->display[4] = &display_i;
	l->display[5] = &display_o;
	l->display[6] = &display_u;
	l->display[7] = &display_x;
	l->display[8] = &display_xx;
	l->display[9] = &display_f;
	l->display[10] = &display_procent;
}
