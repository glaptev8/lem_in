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
 	int		j;
 	int		min;
	int		level;
	
	i = 0;
	min = visit;
	level = -1;
	while (i < room[pos].size_link_arr)
	{
		if (room[room[pos].arr_link[i]].visit < visit)
		{
			level = room[room[pos].arr_link[i]].lvl;
			break;
		}
		i++;
	}
 	j = -1;
 	i = 0;
 	while (i < room[pos].size_link_arr)
	{
 		if (room[room[pos].arr_link[i]].visit < visit && (level >= room[room[pos].arr_link[i]].lvl))
		{
 			level = room[room[pos].arr_link[i]].lvl;
			j = room[pos].arr_link[i];
			min = room[room[pos].arr_link[i]].visit;
		}
 		i++;
	}
 	return (j);
}

t_way 	**set_ways(t_str *lem, t_room *rooms)
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
	start = lem->start;
	end = lem->end;
	way = (t_way **)malloc(sizeof(t_way) * rooms[end].size_link_arr);
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
	visit++;
	rooms[q].visit = visit;
	way[i] = NULL;
	while (i < rooms[end].size_link_arr)
	{
		way[i] = NULL;
		if (has_ways_from_start(rooms, start, visit) && has_ways_from_start(rooms, end, visit))
		{
			way[i] = (t_way *) malloc(sizeof(t_way));
			way[i]->next = NULL;
			way[i]->prev = NULL;
			way[i]->head = NULL;
			while (rooms[q].lvl != 0)
			{
				way[i]->y = q;
				q = give_prev_room_min_level_not_visited(rooms, q, visit);
				if (q < 0)
				{
					if (!tmp2 || !tmp2->next)
					{
						free(tmp2);
						tmp2 = NULL;
						break;
					}
					tmp2 = tmp2->next;
					free(tmp2->prev);
					tmp2->prev = NULL;
					rooms[way[i]->y].visit = visit;
					q = tmp2->x;
					continue;
				}
				if (way[i]->y != end)
					rooms[way[i]->y].visit = 2;
				way[i]->x = q;
				if (tmp2)
				{
					tmp2->prev = (t_way *) malloc(sizeof(t_way) * 1);
					tmp2->prev->next = NULL;
					tmp2->prev->prev = NULL;
					tmp2->prev->head = NULL;
					tmp2->prev->next = tmp2;
					tmp2 = tmp2->prev;
					tmp2->x = way[i]->x;
					tmp2->y = way[i]->y;
					tmp2->prev = NULL;
				}
				else
				{
					tmp2 = (t_way *) malloc(sizeof(t_way) * 1);
					tmp2->next = NULL;
					tmp2->prev = NULL;
					tmp2->head = NULL;
					tmp2->x = way[i]->x;
					tmp2->y = way[i]->y;
				}
			}
			free(way[i]);
			way[i] = NULL;
			way[i] = tmp2;
//			while (tmp2 && tmp2->next)
//			{
//				tmp2 = tmp2->next;
//				free(tmp2->prev);
//				tmp2->prev = NULL;
//			}
//			free(tmp2);
			tmp2 = NULL;
			q = end;
			i++;
		}
		else
			break;
	}
	i = 0;
//	while (i < rooms[end].size_link_arr)
//	{
//		if (way[i])
//		{
//			while (way[i])
//			{
//				printf("%s  ->   %s\n", rooms[way[i]->x].arr_room, rooms[way[i]->y].arr_room);
//				if (!way[i]->next)
//					break;
//				way[i] = way[i]->next;
//			}
//			printf("\n\n");
//		}
//		i++;
//	}
	return (way);
}