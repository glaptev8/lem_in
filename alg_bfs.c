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
 		if (place[number_room].arr_link[i] == -1)
		{
 			i++;
			continue;
		}
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
		if (room[pos].arr_link[i] == -1)
		{
			i++;
			continue;
		}
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
		if (room[pos].arr_link[i] == -1)
		{
			i++;
			continue;
		}
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
	 if (*stack)
	 	free(*stack);
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
 	if (a)
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		tmp->next = NULL;
		tmp->head = tmp;
	}
 	while (a && a->next)
	{
 		tmp->x = a->x;
 		tmp->next = (t_stack *)malloc(sizeof(t_stack));
 		tmp->head = tmp->head;
 		tmp->next->head = tmp->head;
 		tmp = tmp->next;
 		tmp->next = NULL;
 		a = a->next;
	}
 	if (a)
	{
		tmp->x = a->x;
		return (tmp->head);
	}
 	return (NULL);
}

void	set_levels(t_room *rooms, int	visit, t_str *lem)
{
 	int				q;
 	t_stack 		*stack;
 	t_stack			*tmp;
 	int				lvl;

 	int i = 1;
 	stack = NULL;
 	stack = lst_create(stack, lem->start);
	tmp = copy_stack(stack);
	clear_stack(&(stack)->head);
	stack = NULL;
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
			tmp = tmp->next;
		else
		{
			lvl++;
			if ((q = give_next_room(rooms, tmp->x, visit)) >= 0)
			{
				rooms[q].visit = visit;
				rooms[q].lvl = lvl;
				stack = lst_create(stack, q);
			}
			clear_stack(&(tmp)->head);
			tmp = copy_stack(stack);
			if (stack)
				clear_stack(&(stack)->head);
			stack = NULL;
		}
	}
}

int		get_count_rows(t_room *rooms, int visit, t_str *lem)
{
 	int count;
 	int i;
 	int q;

 	q = lem->end;
 	count = 0;
	if (has_ways_from_start(rooms, lem->start, visit) && has_ways_from_start(rooms, lem->end, visit))
	{
		while (rooms[q].lvl != 0)
		{
			q = give_prev_room_min_level_not_visited(rooms, q, visit);
			if (q < 0)
			{
				if (q == lem->end)
				{
					count--;
					break;
				}
				count--;
				continue;
			}
			count++;
		}
	}
	return (count);
}

int		if_has_road_to_end_from_start(t_room *rooms, t_str *lem, int visit, int **qq)
{
 	int i;
 	int end;
 	int start;
 	int j;

 	j = 0;
 	i = 0;
 	end = lem->end;
 	start = lem->start;
	if (give_prev_room_min_level_not_visited(rooms, end, visit) == start)
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
		lem->len_ways[i] = 1;
		i++;
	}
	return (i);
}

int		if_has_way(t_room *rooms, int visit, t_str *lem, int **qq, int i)
{
 	int j;

	if (has_ways_from_start(rooms, lem->start, visit) && has_ways_from_start(rooms, lem->end, visit))
	{
		j = get_count_rows(rooms, visit, lem);
		if (!qq[i])
		{
			qq[i] = (int *)malloc(sizeof(int) * (j + 1));
			qq[i][j + 1] = -1;
			qq[i][j] = lem->end;
		}
		j--;
		return (j);
	}
	return (-1);
}

int		one_step_back_is_end(int qq, int end, int *i)
{
 	if (qq == end)
	{
		(*i)--;
		return (1);
	}
	return (0);
}

int		push_row(int **qq, t_room *rooms, t_str *lem, int *i, int *q)
{
	int		j;
//
	if ((j = if_has_way(rooms, 2, lem, qq, *i)) > -1)
	{
		lem->len_ways[*i] = j + 1;
		while (rooms[*q].lvl != 0)
		{
			*q = give_prev_room_min_level_not_visited(rooms, *q, 2);
			if (q < 0)
			{
				rooms[qq[*i][++j]].visit = 2;
				if (one_step_back_is_end(qq[*i][j], lem->end, i))
					break;
				*q = qq[*i][j];
				continue;
			}
			qq[*i][j] = *q;
			if (qq[*i][j] != lem->end && qq[*i][j] != lem->start)
				rooms[qq[*i][j]].visit = 2;
			j--;
		}
		*q = lem->end;
		(*i)++;
		return (1);
	}
	else
	{
		lem->count_ways = (*i);
		return (0);
	}
}

int		**set_ways(t_room *rooms, int visit, t_str *lem)
{
 	int i;
 	int q;
// 	int j;
 	int **qq;
//
 	i = 0;
 	q = 0;
	qq = (int **)malloc(sizeof(int *) * (rooms[lem->end].size_link_arr));
	while (q <= rooms[lem->end].size_link_arr)
		qq[q++] = NULL;
	q = lem->end;
	if (if_has_way(rooms, visit, lem, qq, lem->end) > -1)
	{
		if (if_has_road_to_end_from_start(rooms, lem, visit, qq))
			i++;
		if (push_row(qq, rooms, lem, &i, &q));
	}
 	else
	{
 		free(qq[lem->end]);
		free(qq);
		qq = NULL;
		lem->count_ways = i;
	}
	return (qq);
}

int 	**get_ways(t_str *lem, t_room *rooms)
{
	int		start;
	int		q;
	int		visit;
	int		**qq;
	int		j;

	visit = 1;
	start = lem->start;
	rooms[start].lvl = 0;
	rooms[start].visit = 1;
	set_levels(rooms, visit++, lem);
	rooms[lem->end].visit = visit;
	qq = set_ways(rooms, visit, lem);
	q = 0;
	if (qq)
	{
		while(q < lem->count_ways)
		{
			free(qq[q]);
			q++;
		}
		free(qq);
		qq = NULL;
	}
	q = 0;
//	printf("\nвсего путей --  %d\n", lem->count_ways);
//	while (q < lem->count_ways)
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