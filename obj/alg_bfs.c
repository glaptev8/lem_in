/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_bfs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:15:02 by rmarni            #+#    #+#             */
/*   Updated: 2019/12/23 18:24:35 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			if_has_way(t_room *rooms, int visit, t_str *lem, int **qq)
{
	int j;

	if (has_ways_from_start(rooms, lem->start, visit)
		&& has_ways_from_start(rooms, lem->end, visit))
	{
		j = get_count_rows(rooms, visit, lem);
		if (j == 0)
		{
			free(*qq);
			*qq = NULL;
			return (-1);
		}
		*(qq) = (int *)malloc(sizeof(int) * (j + 2));
		(*qq)[j + 1] = -1;
		(*qq)[j] = lem->end;
		j--;
		return (j);
	}
	return (-1);
}

int			one_step_back_is_end(int qq, int end, int *i)
{
	if (qq == end)
	{
		(*i)--;
		return (1);
	}
	return (0);
}

void		else_push_row(int *i, t_str *lem, int **qq)
{
	while (*i < lem->copy_end_link_count)
	{
		qq[*i] = NULL;
		lem->copy_end_link_count--;
	}
	(*i) = lem->copy_end_link_count;
}

void		push_row(int **qq, t_room *rooms, t_str *lem, int *i)
{
	lem->q = lem->end;
	if ((lem->j = if_has_way(rooms, 2, lem, &qq[*i])) > -1)
	{
		lem->len_ways[*i] = lem->j + 1;
		while (rooms[lem->q].lvl != 0)
		{
			lem->q = get_min_level(rooms, lem->q, 2);
			if (lem->q < 0)
			{
				rooms[qq[*i][++lem->j]].visit = 2;
				if (one_step_back_is_end(qq[*i][lem->j], lem->end, i))
					break ;
				lem->q = qq[*i][lem->j];
				continue;
			}
			qq[*i][lem->j] = lem->q;
			if (qq[*i][lem->j] != lem->end && qq[*i][lem->j] != lem->start)
				rooms[qq[*i][lem->j]].visit = 2;
			lem->j--;
		}
		(*i)++;
	}
	else
		else_push_row(i, lem, qq);
}

int			**set_ways(t_room *rooms, int visit, t_str *lem)
{
	int i;
	int **qq;

	i = 0;
	lem->copy_end_link_count = rooms[lem->end].size_link_arr;
	qq = (int **)malloc(sizeof(int *) * (rooms[lem->end].size_link_arr + 1));
	if (if_has_road_to_end_from_start(rooms, lem, visit, qq))
		i++;
	while (i < lem->copy_end_link_count)
		push_row(qq, rooms, lem, &i);
	lem->count_ways = i;
	return (qq);
}
