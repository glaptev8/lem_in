/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:35:23 by tmelia            #+#    #+#             */
/*   Updated: 2019/09/17 13:01:58 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int		ft_atoi(const char *str)
{
	long int	num;
	int			sign;
	long int	border;

	num = 0;
	sign = 1;
	border = (long int)(FT_LONG_MAX / 10);
	while (*str && ((*str >= 9 && *str <= 13) || *str == ' '))
		str++;
	(*str == '-') ? sign = -1 : 0;
	if ((*str == '-' || *str == '+') && *(str - 1) != '-' && *(str - 1) != '+')
		++str;
	while (*str == '0')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		if ((num > border || (num == border && (*str))) && sign > 0)
			return (-1);
		else if ((num > border || (num == border && (*str))) && sign == -1)
			return (0);
		num = num * 10 + (long int)(*str - '0');
		str++;
	}
	return (num * sign);
}
