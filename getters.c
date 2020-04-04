/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:14:07 by tmelia            #+#    #+#             */
/*   Updated: 2019/12/23 17:14:10 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			get_level_not_visited(t_room *room, int visit, int pos)
{
	int i;

	i = 0;
	while (i < room[pos].size_link_arr)
	{
		if (room[pos].arr_link[i] == -1)
		{
			i++;
			continue;
		}
		if (room[room[pos].arr_link[i]].visit < visit)
			return (room[room[pos].arr_link[i]].lvl);
		i++;
	}
	return (-1);
}

t_stack		*lst_create(t_stack *stack, int number)
{
	t_stack *tmp;

	tmp = (t_stack *)malloc(sizeof(t_stack));
	tmp->x = number;
	tmp->head = tmp;
	if (stack)
	{
		tmp->next = stack;
		tmp->next->head = tmp;
	}
	else
	{
		tmp->x = number;
		tmp->next = NULL;
	}
	return (tmp);
}

int			get_min_level(t_room *room,
		int pos, int visit)
{
	int		i;
	int		j;
	int		level;

	level = get_level_not_visited(room, visit, pos);
	j = -1;
	i = 0;
	while (i < room[pos].size_link_arr)
	{
		if (room[pos].arr_link[i] == -1)
		{
			i++;
			continue;
		}
		if (room[room[pos].arr_link[i]].visit <
			visit && (level >= room[room[pos].arr_link[i]].lvl))
		{
			level = room[room[pos].arr_link[i]].lvl;
			j = room[pos].arr_link[i];
		}
		i++;
	}
	return (j);
}

int			get_count_rows(t_room *rooms, int visit, t_str *lem)
{
	int count;

	count = -1;
	if (has_ways_from_start(rooms, lem->start, visit) &&
		has_ways_from_start(rooms, lem->end, visit))
		count = set_count_rows(rooms, visit, lem);
	return (count);
}

int			**get_ways(t_str *lem, t_room *rooms)
{
	int		start;
	int		visit;
	int		**qq;

	visit = 1;
	start = lem->start;
	rooms[start].lvl = 0;
	rooms[start].visit = 1;
	set_levels(rooms, visit++, lem);
	rooms[lem->end].visit = visit;
	qq = set_ways(rooms, visit, lem);
	return (qq);
}
