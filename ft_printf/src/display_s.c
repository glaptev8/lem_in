/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:03:52 by cjosue            #+#    #+#             */
/*   Updated: 2019/10/15 19:03:54 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_putstr_cool(char *str, long int len, t_printf *list)
{
	if (str == NULL)
		ft_putstr_cool("(null)", len, list);
	else
	{
		if (!str[1] && (str[0] == ' ' || str[0] == '0'))
		{
			while (len-- > 0)
			{
				write(1, str, 1);
				list->count++;
			}
		}
		else
		{
			while (len-- > 0 && *str)
			{
				write(1, str++, 1);
				list->count++;
			}
		}
	}
}

void			display_s(t_printf *list)
{
	char		*str;
	long int	len;

	if (!(str = va_arg(list->argc, char*)))
		str = NULL;
	len = 6;
	if (str)
		len = ft_strlen(str);
	if (list->precision > 0 && list->precision_space < len)
		len = (list->precision_space >= 0) ? list->precision_space : len;
	if (list->minus == 1)
	{
		ft_putstr_cool(str, len, list);
		ft_putstr_cool(" ", list->width_space - len, list);
	}
	else if (list->zero == 1)
	{
		ft_putstr_cool("0", list->width_space - len, list);
		ft_putstr_cool(str, len, list);
	}
	else
	{
		ft_putstr_cool(" ", list->width_space - len, list);
		ft_putstr_cool(str, len, list);
	}
}
