/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:20:43 by cjosue            #+#    #+#             */
/*   Updated: 2019/10/19 16:22:22 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char					*ft_strjoin_re(char *s1, char *s2)
{
	char				*tmp;

	tmp = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (tmp);
}

int						ft_rounding(char *div, int i)
{
	if (div[i] >= '5')
	{
		div[--i] += 1;
		if (div[i] > '9')
		{
			while (div[i] > '9' && i > 0)
			{
				div[i] = '0';
				div[--i] += 1;
			}
			if (i == 0 && div[0] > '9')
			{
				div[i] = '0';
				return (1);
			}
		}
	}
	return (0);
}

double					ft_sign(char *num, double d)
{
	long unsigned int	tmp;

	ft_memcpy(&tmp, &d, sizeof(double));
	if (tmp & 1L << 63)
	{
		num[0] = '-';
		return (-1.00);
	}
	else
		num[0] = '+';
	return (1.00);
}
