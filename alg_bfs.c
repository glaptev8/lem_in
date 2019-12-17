 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_bfs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:15:02 by rmarni            #+#    #+#             */
/*   Updated: 2019/12/13 17:33:36 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


 int		give_next_room(t_room *place, int number_room, int visited)
 {
 	int i;

 	i = 0;
 	while (i < place[number_room].size_link_arr)
	{
 		if (place[place[number_room].arr_link[i]].visit != visited)
			return (place[number_room].arr_link[i]);
 		i++;
	}
	 return (-1);
 }

int		has_ways_from_start(t_room *rooms, int start, int visited)
{
	if (give_next_room(rooms, start, visited) == -1)
		return (0);
	return (1);
}

t_stack 	*lst_create(t_stack *stack, int number)
{
 	t_stack *tmp;

 	tmp = (t_stack *)malloc(sizeof(t_stack) * 1);
 	tmp->x = number;
	tmp->head = tmp;
	if (stack)
	{
		tmp->next = stack;
		tmp->next->head = tmp->head;
	}
	else
	{
		tmp->next = NULL;
	}
	return (tmp);
}

int		give_prev_room_min_level_not_visited(t_room *room, int pos, int visit)
{
 	int		i;
 	int		min;
 	int		j;
 	
 	j = -1;
 	min = room[room[pos].arr_link[0]].lvl;
 	i = 0;
	while (i < room[pos].size_link_arr)
	{
		if (room[room[pos].arr_link[i]].lvl <= min)
		{
			j = room[pos].arr_link[i];
			min = room[room[pos].arr_link[i]].lvl;
		}
		i++;
	}
	return(j);
}

void	set_ways(t_str *lem, t_room *rooms)
{
	int		start;
	int		end;
	int		i;
	int		q;
	int		lvl;
	int		visit;

	visit = 1;
	t_stack	*stack;
	t_way	**way;
	q = -1;
	stack = NULL;
	lvl = 1;
	start = ft_binary_search(rooms, 0, lem->room_count, "start");
	end = ft_binary_search(rooms, 0, lem->room_count, "end");
	
	way = (t_way **)malloc(sizeof(t_way *) * rooms[end].size_link_arr);
	i = 0;
	while (i < rooms[end].size_link_arr)
		way[i++] = NULL;
		
	i = start;
	rooms[start].lvl = 0;
	rooms[start].visit = 1;
	while ((q = give_next_room(rooms, start, visit)) >= 0)
	{
		rooms[q].lvl = lvl;
		rooms[q].visit = visit;
		stack = lst_create(stack, q);
	}
	lvl++;
	t_stack *tmp;
	tmp = stack;
	stack = NULL;
//	while (has_ways_from_start(rooms, end, visit))
	{
		while (tmp)
		{
			while ((q = give_next_room(rooms, tmp->x, visit)) >= 0)
			{
				rooms[q].visit = visit;
				rooms[q].lvl = lvl;
				stack = lst_create(stack, q);
			}
			if (tmp->next)
				tmp = tmp->next;
			else {
				tmp = stack;
				stack = NULL;
				lvl++;
			}
		}
	}
	q = end;
	i = 0;
	int j = 0;
	while (rooms[q].lvl != 0)
	{
		if (!way[i])
		{
			way[i] = (t_way *) malloc(sizeof(t_way));
			way[i]->next = NULL;
			way[i]->prev = NULL;
		}
		way[i]->head = NULL;
		way[i]->y = q;
		q = give_prev_room_min_level_not_visited(rooms, q, visit);
		rooms[q].visit = visit;
		way[i]->x = q;
		if (rooms[q].lvl != 0)
		{
			way[i]->prev = (t_way *) malloc(sizeof(t_way) * 1);
			way[i]->prev->prev= NULL;
			way[i]->prev->next = way[i];
			way[i] = way[i]->prev;
		}
		while (j < rooms[q].size_link_arr)
		{
			rooms[rooms[q].arr_link[j]]
		}
	}
}