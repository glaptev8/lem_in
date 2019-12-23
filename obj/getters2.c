/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:25:47 by tmelia            #+#    #+#             */
/*   Updated: 2019/12/23 17:25:49 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			get_next_room(t_room *room, int number_room, int visited)
{
	int i;

	i = 0;
	while (i < room[number_room].size_link_arr)
	{
		if (room[number_room].arr_link[i] == -1)
		{
			i++;
			continue;
		}
		if (room[room[number_room].arr_link[i]].visit != visited)
			return (room[number_room].arr_link[i]);
		i++;
	}
	return (-1);
}
