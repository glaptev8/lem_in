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

 void	clear_stack(t_stack **stack)
 {
	 t_stack *tmp;
	
	 tmp = *stack;
	 while (tmp && (tmp)->next)
	 {
		 tmp = tmp->next;
		 free(*stack);
		 *stack = NULL;
		 *stack = tmp;
	 }
	 free(*stack);
	 *stack = NULL;
 }

t_stack 	*lst_create(t_stack *stack, int number)
{
 	t_stack *tmp;
 	
 	tmp = (t_stack *)malloc(sizeof(t_stack));
 	tmp->x = number;
 	tmp->head = tmp;
 	tmp->next = NULL;
 	if (stack)
 	{
 		tmp->next = stack;
 		tmp->next->head = tmp;
 	}
 	else
 	{
 		tmp->x = number;
 		tmp->head = tmp;
 		tmp->next = NULL;
 	}
 	return (tmp);
}

t_stack *copy_stack(t_stack *stack)
{
 	t_stack *tmp;
 	t_stack *q;
 	t_stack *a;
 	
 	a = stack;
 	tmp = NULL;
 	while (a && a->next)
	{
 		tmp = lst_create(tmp, a->x);
 		a = a->next;
	}
 	if (a)
		tmp = lst_create(tmp, a->x);
 	return (tmp);
}

void	set_levels(t_room *rooms, int	visit, t_str *lem)
{
 	int				q;
 	t_stack 		*stack;
 	t_stack			*tmp;
 	int				lvl;

 	int i = 1;
 	stack = NULL;
 	tmp = NULL;
 	stack = lst_create(stack, lem->start);
	tmp = copy_stack(stack);
	clear_stack(&stack);
//	stack = NULL;
// 	rooms[lem->start].lvl = 0;
 	lvl = 1;
	while (tmp)
	{
		while ((q = give_next_room(rooms, tmp->x, visit)) >= 0)
		{
			rooms[q].visit = visit;
			rooms[q].lvl = lvl;
			stack = lst_create(stack, q);
		}
		if (tmp->next)
		{
			tmp = tmp->next;
			if (!tmp)
			{
				free(stack);
				free(tmp);
				break;
			}
		}
		else
		{
			if (tmp->head)
				clear_stack(&tmp->head);
			else
				clear_stack(&tmp);
			tmp = copy_stack(stack);
			clear_stack(&stack);
			lvl++;
			if (!tmp)
			{
				free(stack);
				free(tmp);
				break;
			}
		}
	}
	free(stack);
	free(tmp);
}

int 	**set_ways(t_str *lem, t_room *rooms)
{
	int		start;
	int		end;
	int		i;
	int		q;
	int		lvl;
	int		visit;
	int		qq[7][12];
	visit = 1;

	q = -1;
	lvl = 1;
	start = lem->start;
	end = lem->end;
	i = start;
	rooms[start].lvl = 0;
	rooms[start].visit = 1;
	set_levels(rooms, visit, lem);
//	i = 0;
//	q = end;
//	visit++;
//	rooms[q].visit = visit;
//	while (i < rooms[end].size_link_arr)
//	{
//		if (has_ways_from_start(rooms, start, visit) && has_ways_from_start(rooms, end, visit))
//		{
//			int j = rooms[give_prev_room_min_level_not_visited(rooms, q, visit)].lvl + 1;
//			qq[i][j + 1] = -1;
//			qq[i][j] = end;
//			lem->len_ways[i] = j;
//			j--;
//			while (rooms[q].lvl != 0)
//			{
//				q = give_prev_room_min_level_not_visited(rooms, q, visit);
//				if (q < 0)
//				{
//					rooms[qq[i][j + 1]].visit = visit;
//					j++;
//					if (qq[i][j] == end)
//					{
//						i--;
//						break;
//					}
//					q = qq[i][j];
//					continue;
//				}
//				qq[i][j] = q;
//				if (qq[i][j] != end && qq[i][j] != start)
//					rooms[qq[i][j]].visit = 2;
//				j--;
//			}
//			q = end;
//			i++;
//		}
//		else
//			break;
//	}
//	q = 0;
//	int j = 0;
//	lem->count_ways = i;
//	printf("\nвсего путей --  %d\n", lem->count_ways);
//	while (q < i)
//	{
//		if (qq[q])
//		{
//			printf("\nдлина пути -- %d\n", lem->len_ways[q]);
//			j = 0;
//			while (qq[q][j] != -1)
//			{
//				printf("%s  %s", rooms[qq[q][j]].arr_room, qq[q][j + 1] != -1 ?  " ->  " : "");
//				j++;
//			}
//			printf("\n\n");
//		}
//		q++;
//	}
	return (qq);
}