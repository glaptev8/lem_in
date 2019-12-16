/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_bfs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:15:02 by rmarni            #+#    #+#             */
/*   Updated: 2019/12/16 16:25:50 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char *find_rm(t_str *lem_in, t_room *room, char *str)
{
	int i;

	i = 0;
/*	while (i < lem_in->link_count)
	{
//		printf ("i = %d. %s\n", i, room[i].arr_link[0]);
		if (!ft_strcmp(str, lem_in->arr_links[i][0]))
		{
			return (lem_in->arr_links[i][1]);
		}
		i++;
	}
*/	return ("NULL");
}

void 	ft_bfs_alg(t_str *lem_in, t_room *rooms)
{
	t_way ways[10];
	lem_in->start = ft_binary_search(rooms, 0, lem_in->room_count, lem_in->buf_start);
/*	char *stack[INT8_MAX * 100];

	int l;
	l = -1;
	stack[++l] = lem_in->start;

	stack[++l] = find_rm(lem_in, rooms, stack[0]);
	printf ("bfs.start = %s\n", stack[l]);
*/
}