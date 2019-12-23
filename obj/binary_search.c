/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 12:40:20 by rmarni            #+#    #+#             */
/*   Updated: 2019/12/23 12:12:29 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_binary_search(t_room *rooms, int start, int end, char *str)
{
	int	comp;
	int	res;
	int	i;

	i = 0;
	res = (end + start) / 2;
	comp = ft_strcmp(rooms[res].arr_room, str);
	if (!comp)
		return (res);
	while (comp)
	{
		res = (end + start) / 2;
		comp = ft_strcmp(rooms[res].arr_room, str);
		if (i > 20)
		{
			ft_printf(RED("ERROR\n"));
			exit(0);
		}
		if (comp > 0)
			end = res;
		else
			start = res;
		i++;
	}
	return (res);
}
