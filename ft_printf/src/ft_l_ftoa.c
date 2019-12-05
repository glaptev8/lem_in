/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_l_ftoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:24:51 by cjosue            #+#    #+#             */
/*   Updated: 2019/10/22 12:24:54 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char					ft_l_ftoa_div(long double d, int pr, char *arr)
{
	int					i;

	i = 0;
	while (i < pr)
	{
		d *= 1e1;
		if ((unsigned long int)d == 0)
			arr[i] = '0';
		else
		{
			arr[i] = (unsigned long int)d + '0';
			d -= (unsigned long int)d;
		}
		i++;
	}
	if (ft_rounding(arr, --i) == 1)
	{
		arr[pr - 1] = '\0';
		return (1);
	}
	arr[pr - 1] = '\0';
	return (0);
}

char					*ft_l_ftoa(long double d, int pr)
{
	char				*num;
	long unsigned int	mod;
	char				*div;

	if (!(num = ft_strnew(1)))
		return (NULL);
	d *= ft_sign(num, d);
	mod = (unsigned long int)d;
	if (pr <= 0)
	{
		if ((unsigned long int)((d - (long double)mod) * 1e1) >= 5)
			return (ft_strjoin_re(num, ft_itoa_lu(++mod, 10, 'f')));
	}
	if (!(div = ft_strnew(++pr)))
		return (num);
	if (ft_l_ftoa_div(d - (unsigned long int)d, pr, div) == 1)
		mod++;
	num = ft_strjoin_re(num, ft_itoa_lu(mod, 10, 'f'));
	return (ft_strjoin_re(num, div));
}
