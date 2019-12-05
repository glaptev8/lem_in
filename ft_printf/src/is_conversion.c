/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:54:58 by tmelia            #+#    #+#             */
/*   Updated: 2019/10/21 13:55:22 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		is_conversion(t_printf list)
{
	char	*str;
	int		i;

	str = ft_strdup("scpdiouxXf%");
	i = 0;
	while (str[i] != '\0')
	{
		if (list.format[list.i] == str[i])
		{
			free(str);
			return (i);
		}
		i++;
	}
	free(str);
	return (-1);
}

int		is_flag(t_printf list)
{
	char	*flags;
	int		i;

	if (ft_isdigit(list.format[list.i]) && list.format[list.i] != '0')
		return (5);
	flags = ft_strdup("-+# .*0l2h2L");
	i = 0;
	while (flags[i] != '\0')
	{
		if (list.format[list.i] == flags[i])
		{
			if ((flags[i] == 'l' && list.format[list.i + 1] == 'l') ||
			(flags[i] == 'h' && list.format[list.i + 1] == 'h'))
			{
				free(flags);
				return (++i);
			}
			free(flags);
			return (i);
		}
		i++;
	}
	free(flags);
	return (-1);
}

int		get_zero_decimal(char *s)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '.' && s[i + 1] == '0')
		{
			i++;
			while (s[i] == '0')
			{
				i++;
				count++;
			}
			break ;
		}
		i++;
	}
	return (count);
}
