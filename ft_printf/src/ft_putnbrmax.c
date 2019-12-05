/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrmax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:30:54 by tmelia            #+#    #+#             */
/*   Updated: 2019/10/21 12:32:33 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbrmax(intmax_t n, t_printf *l)
{
	if (n == -9223372036854775807 - 1)
	{
		l->count += 20;
		write(1, "-9223372036854775808", 20);
	}
	else
	{
		if (n < 0)
		{
			l->count++;
			ft_putchar('-');
			n *= -1;
		}
		if (n > 9)
			ft_putnbrmax(n / 10, l);
		if (!(l->precision == 1 && l->number == 0))
		{
			l->count++;
			ft_putchar((n % 10) + '0');
		}
	}
}

void	ft_putnbrmax_for_f(int i, int d, t_printf *l, int len_num)
{
	int j;

	j = 0;
	ft_putnbrmax(i, l);
	if (l->precision_space > 0)
	{
		if (l->precision == 1 && l->number == 0)
			ft_putchar('0');
		l->count++;
		ft_putchar('.');
		while (j++ < l->precision_space - len_num + 1)
		{
			l->count++;
			ft_putchar('0');
		}
		ft_putnbrmax(d, l);
	}
}

int		ft_str_equally(char *str1, char *str2)
{
	while (*str1 != '\0' || *str2 != '\0')
	{
		if (*str1 == *str2)
		{
			str1++;
			str2++;
		}
		else
			return (-1);
	}
	return (1);
}

void	ft_putnbrmax_o(uintmax_t n, t_printf *l)
{
	if (l->u == 1 && get_number_len_for_uint(n) >= 20)
	{
		l->count += 20;
		write(1, "18446744073709551615", 20);
	}
	else if (l->is_o == 1 && get_number_len_for_uint(n) >= 19)
	{
		l->count += 21;
		write(1, "777777777777777777777", 21);
	}
	else
	{
		if (n > 9)
			ft_putnbrmax_o(n / 10, l);
		if (!(l->u == 1 && get_number_len_for_uint(n) >= 20))
		{
			if (l->precision_space > 0 || l->precision == 0 ||
					(l->precision == 1 && l->precision_space < 0 &&
					l->number_o != 0))
			{
				l->count++;
				ft_putchar((n % 10) + '0');
			}
		}
	}
}

void	ft_putnbrmax_x(char *n)
{
	if (ft_str_equally("9223372036854775807", n) == 1)
		write(1, "7fffffffffffffff", 16);
	ft_putstr(n);
}
