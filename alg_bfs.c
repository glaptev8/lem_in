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


 int		give_next_room(t_room *place, int number_room)
 {
 	int i;
 	
 	i = 0;
 	while (i < place[number_room].size_link_arr)
	{
 		if (place[place[number_room].arr_link[i]].visit != 1)
			return (place[number_room].arr_link[i]);
 		i++;
	}
	 return (-1);
 }
 
int		has_ways_from_start(t_room *rooms, int start)
{
	if (give_next_room(rooms, start) == -1)
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

int		give_prev_room_min_level_not_visited(t_room *room, int pos)
{
 	int		i;
 	int		min;
 	int		q;
 	int		j;
 	
 	min = room[pos].lvl;
 	j = pos;
 	i = 0;
 	while (i < room[pos].size_link_arr)
	{
 		if (room[room[pos].arr_link[i]].visit != 2)
		{
 			if (room[room[pos].arr_link[i]].lvl < min)
			{
				min = room[room[pos].arr_link[i]].lvl;
				j = room[pos].arr_link[i];
			}
		}
 		i++;
	}
	return (j);
}

void	set_ways(t_str *lem, t_room *rooms)
{
	int		start;
	int		end;
	int		i;
	int		q;
	int		lvl;
	t_stack	*stack;
	t_way	**way;

	q = -1;
	stack = NULL;
	lvl = 1;
	way = (t_way **)malloc(sizeof(t_way) * rooms[start].size_link_arr);
	start = ft_binary_search(rooms, 0, lem->room_count, "start");
	end = ft_binary_search(rooms, 0, lem->room_count, "end");
	i = start;
	rooms[start].lvl = 0;
	rooms[start].visit = 1;
	while ((q = give_next_room(rooms, start)) >= 0)
	{
		rooms[q].lvl = lvl;
		rooms[q].visit = 1;
		stack = lst_create(stack, q);
	}
	lvl++;
	t_stack *tmp;
	
	tmp = stack;
	stack = NULL;
	while (tmp)
	{
		while ((q = give_next_room(rooms, tmp->x)) >= 0)
		{
			rooms[q].visit = 1;
			rooms[q].lvl = lvl;
			stack = lst_create(stack, q);
		}
		if (tmp->next)
			tmp = tmp->next;
		else
		{
			tmp = stack;
			stack = NULL;
			lvl++;
		}
	}
	i = 0;
	q = end;
	t_way *tmp2;
	tmp2 = NULL;
	
	while (i < rooms[start].size_link_arr)
	{
		while (rooms[q].lvl != 0)
		{
			way[i] = (t_way *) malloc(sizeof(t_way) * 1);
			way[i]->y = q;
			q = give_prev_room_min_level_not_visited(rooms, q);
			way[i]->x = q;
			if (tmp2)
			{
				tmp2->prev = (t_way *) malloc(sizeof(t_way) * 1);
				tmp2->prev->next = tmp2;
				tmp2 = tmp2->prev;
				tmp2->x = way[i]->x;
				tmp2->y = way[i]->y;
			}
			else
				tmp2 = way[i];
		}
		way[i] = tmp2;
		tmp2 = NULL;
		i++;
	}
}