/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:21:18 by tmelia            #+#    #+#             */
/*   Updated: 2019/12/23 17:21:20 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			has_ways_from_start(t_room *rooms, int start, int visited)
{
	if (get_next_room(rooms, start, visited) == -1)
		return (0);
	return (1);
}

int			q_less(int *q, t_room *rooms, t_str *lem, int mas[2])
{
	if (get_min_level(rooms,
			lem->end, mas[1]) == mas[0])
		lem->copy_end_link_count--;
	rooms[mas[0]].visit = 2;
	if (!has_ways_from_start(rooms, lem->end, mas[1]))
		return (0);
	*q = lem->end;
	mas[0] = -1;
	return (-1);
}

int			init_value_count_ways(int mas[2], int *q, int *count, t_str *lem)
{
	mas[0] = -1;
	mas[1] = 2;
	*q = lem->end;
	*count = 0;
	return (1);
}

int			set_count_rows(t_room *rooms, int visit, t_str *lem)
{
	int q;
	int count;
	int i;
	int mas[2];

	i = init_value_count_ways(mas, &q, &count, lem);
	while (rooms[q].lvl != 0)
	{
		if (get_min_level(rooms, q, visit) == mas[0])
		{
			rooms[q].visit = 2;
			count = 0;
			mas[0] = -1;
			q = lem->end;
			continue;
		}
		get_min_level(rooms, q, visit) == mas[0] ? i++ : 0;
		mas[0] = q;
		q = get_min_level(rooms, q, visit);
		q < 0 ? count = q_less(&q, rooms, lem, mas) : 0;
		if (count == -2)
			return (0);
		count++;
	}
	return (count);
}

int			if_has_road_to_end_from_start(t_room *rooms,
		t_str *lem, int visit, int **qq)
{
	int i;
	int end;
	int start;
	int j;

	j = 0;
	i = 0;
	end = lem->end;
	start = lem->start;
	if (get_min_level(rooms, end, visit) == start)
	{
		qq[i] = (int *)malloc(sizeof(int) * 3);
		qq[i][0] = start;
		qq[i][1] = end;
		qq[i][2] = -1;
		while (rooms[start].arr_link[j] != end)
			j++;
		rooms[start].arr_link[j] = -1;
		j = 0;
		while (rooms[end].arr_link[j] != start)
			j++;
		rooms[end].arr_link[j] = -1;
		lem->len_ways[i++] = 1;
	}
	return (i);
}
