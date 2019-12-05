/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:04:03 by cjosue            #+#    #+#             */
/*   Updated: 2019/10/15 19:04:06 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char					*ft_str_adres(unsigned long int adres)
{
	int					i;
	char				*str;
	unsigned long int	tmp;

	i = 0;
	tmp = adres;
	while ((tmp /= 16) > 0)
		i++;
	i++;
	str = ft_strnew(i);
	while (--i >= 0)
	{
		tmp = adres % 16;
		str[i] = "0123456789abcdef"[tmp];
		adres /= 16;
	}
	return (str);
}

void					ft_print_p(char *str_a, long int len, t_printf *list)
{
	if (list->minus == 1)
	{
		ft_putstr_cool("0x", 2, list);
		ft_putstr_cool("0", list->precision_space - len, list);
		ft_putstr_cool(str_a, len, list);
		ft_putstr_cool(" ", list->width_space - 2 - list->precision_space, \
		list);
	}
	else if (list->zero == 1)
	{
		ft_putstr_cool("0x", 2, list);
		ft_putstr_cool("0", list->width_space - 2 - len, list);
		ft_putstr_cool(str_a, len, list);
	}
	else
	{
		ft_putstr_cool(" ", list->width_space - 2 - list->precision_space, \
		list);
		ft_putstr_cool("0x", 2, list);
		ft_putstr_cool("0", list->precision_space - len, list);
		ft_putstr_cool(str_a, len, list);
	}
}

void					display_p(t_printf *list)
{
	unsigned long int	adres;
	char				*str_a;
	long int			len;

	adres = va_arg(list->argc, unsigned long int);
	str_a = ft_str_adres(adres);
	len = (list->precision == 1 && adres == 0) ? 0 : ft_strlen(str_a);
	if (list->precision_space > 0)
		list->zero = 0;
	if (list->precision_space < len)
		list->precision_space = len;
	ft_print_p(str_a, len, list);
	free(str_a);
}
