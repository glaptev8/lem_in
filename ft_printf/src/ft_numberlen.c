/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numberlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:24:24 by tmelia            #+#    #+#             */
/*   Updated: 2019/10/21 12:24:26 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		get_number_len(intmax_t n, t_printf list)
{
	int		i;

	i = 0;
	if (n < 0 || list.plus == 1)
		i++;
	n < 0 ? n *= -1 : 0;
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int		get_number_len_for_uint(uintmax_t n)
{
	int i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int		get_number_len_for_16(uintmax_t n)
{
	int i;

	i = 0;
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int		ft_pow(int n, int p)
{
	int i;
	int nb;

	nb = n;
	i = 0;
	while (i++ < p)
		n = n * nb;
	return (n);
}
