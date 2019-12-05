/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:58:28 by tmelia            #+#    #+#             */
/*   Updated: 2019/10/21 11:59:30 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

uintmax_t	get_number_for_o(t_printf *list)
{
	uintmax_t n;

	if (list->l == 1)
		n = va_arg(list->argc, unsigned long int);
	else if (list->ll == 1)
		n = va_arg(list->argc, unsigned long long int);
	else if (list->h == 1)
		n = (unsigned short)va_arg(list->argc, unsigned int);
	else if (list->hh == 1)
		n = (unsigned char)va_arg(list->argc, unsigned int);
	else
		n = (unsigned int)va_arg(list->argc, unsigned int);
	n = (uintmax_t)n;
	return (n);
}

char		*ft_number_o(t_printf *list, size_t *lenght)
{
	char		*num;
	char		*zero;
	size_t		len;
	size_t		len_zero;

	len_zero = 0;
	if (!(num = ft_itoa_lu(get_number_for_o(list), 8, 'n')))
		return (NULL);
	if (num[0] == '0' && list->precision == 1 && list->precision_space <= 0)
		num[0] = '\0';
	len = ft_strlen(num);
	(list->sharp == 1 && num[0] != '0') ? len_zero++ : 0;
	if (list->precision == 1 && (unsigned int)list->precision_space >
	(len + len_zero) && list->precision_space > 0)
		len_zero += list->precision_space - len - len_zero;
	if (len_zero > 0)
	{
		if (!(zero = ft_strnew(len_zero)))
			return (NULL);
		ft_memset(zero, '0', len_zero);
		if (!(num = ft_strjoin_re(zero, num)))
			return (NULL);
	}
	*lenght = len + len_zero;
	return (num);
}

void		display_o(t_printf *list)
{
	char		*num;
	size_t		len;

	if (!(num = ft_number_o(list, &len)))
		return ;
	if (list->minus == 1)
	{
		ft_putstr_cool(num, len, list);
		ft_putstr_cool(" ", list->width_space - len, list);
	}
	else if (list->zero == 1 && list->precision != 1)
	{
		ft_putstr_cool("0", list->width_space - len, list);
		ft_putstr_cool(num, len, list);
	}
	else
	{
		ft_putstr_cool(" ", list->width_space - len, list);
		ft_putstr_cool(num, len, list);
	}
	ft_strdel(&num);
}
