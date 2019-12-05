/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_lu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:16:56 by cjosue            #+#    #+#             */
/*   Updated: 2019/10/22 12:16:59 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int			count_int(unsigned long int n, unsigned int base)
{
	int i;

	i = 1;
	while (n / base != 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

char				*ft_itoa_lu(unsigned long int n, unsigned int base, char s)
{
	char				*str;
	int					size;
	unsigned long int	nb;
	int					index;

	size = count_int(n, base);
	if (!(str = ft_strnew(size + 1)))
		return (NULL);
	nb = n;
	index = size - 1;
	while (nb >= base)
	{
		str[index--] = nb % base + '0';
		nb /= base;
	}
	str[index] = nb + '0';
	str[size] = (s == 'f') ? '.' : '\0';
	str[size + 1] = '\0';
	return (str);
}
