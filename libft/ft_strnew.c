/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:39:54 by tmelia            #+#    #+#             */
/*   Updated: 2019/09/17 11:47:28 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if (++size == 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (size));
	if (!str)
		return (NULL);
	while (size >= i)
		str[i++] = '\0';
	return (str);
}
