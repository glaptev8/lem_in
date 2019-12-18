/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:08:24 by rmarni            #+#    #+#             */
/*   Updated: 2019/12/14 15:29:15 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_zero_struck(t_room *rooms, int arr_size)
{
	int i;

	i = 0;
	while (i < arr_size)
	{
		rooms[i].size_link_arr = 0;
		i++;
	}
}

t_room *ft_sort_struct(t_room *room, int arr_size)
{
	int	i;
	int	j;
	int r;

	t_room	tmp;
	if (room == NULL)
		return (NULL);
	i = -1;
	j = arr_size;
	while (++i < arr_size)
	{
		while (--j)
		{

			r = ft_strcmp(room[j].arr_room, room[j - 1].arr_room);
			if (r < 0)
			{
				tmp.arr_room = room[j].arr_room;
				room[j].arr_room = room[j - 1].arr_room;
				room[j - 1].arr_room = tmp.arr_room;

			}
		}
		j = arr_size;
	}
		return (room);
}


/*
t_room *ft_sort_link(t_room *room, int arr_size)
{
	int	i;
	int	j;
	int r;

	t_room	tmp;
	r = 0;
	if (room == NULL)
		return (NULL);
	i = -1;
	j = arr_size;
	while (++i < arr_size)
	{
		while (--j)
		{

			r = ft_strcmp(room[j].arr_link[0], room[j - 1].arr_link[0]);
			if (r < 0)
			{
				tmp.arr_link[0] = room[j].arr_link[0];
				room[j].arr_link[0] = room[j - 1].arr_link[0];
				room[j - 1].arr_link[0] = tmp.arr_link[0];

			}
		}
		j = arr_size;
	}
	return (room);
}
*/