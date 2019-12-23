/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bfr_alg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 15:26:30 by rmarni            #+#    #+#             */
/*   Updated: 2019/12/23 15:33:44 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			secd_par(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (++i);
}

void		add_link_room_num(t_room *rooms, t_str *lem_in)
{
	int		link_room;
	int		link_room2;

	if (lem_in->room_count == 0)
		ft_exit(lem_in, rooms, 1);
	ft_slash_zero_link(lem_in->buf, '-');
	link_room = ft_binary_search(rooms, 0, lem_in->room_count,
	lem_in->buf);
	link_room2 = ft_binary_search(rooms, 0, lem_in->room_count,
	lem_in->buf + secd_par(lem_in->buf));
	rooms[link_room].arr_link[rooms[link_room].size_link_arr] = link_room2;
	rooms[link_room].size_link_arr++;
	rooms[link_room2].arr_link[rooms[link_room2].size_link_arr] = link_room;
	rooms[link_room2].size_link_arr++;
}

int			is_links(t_str *lem_in, t_room *rooms)
{
	int		i;

	i = -1;
	if (lem_in->buf[0] == '#')
		return (0);
	while (lem_in->buf[++i])
		if (lem_in->buf[i] == ' ')
			return (0);
	ft_sort_struct(rooms, lem_in->room_count);
	ft_zero_struck(rooms, lem_in->room_count);
	add_link_room_num(rooms, lem_in);
	free(lem_in->buf);
	while (get_next_line(lem_in->fd, &lem_in->buf))
	{
		ft_printf("%s\n", lem_in->buf);
		if (lem_in->buf[0] != '#')
		{
			lem_in->link_count++;
			add_link_room_num(rooms, lem_in);
		}
		free(lem_in->buf);
	}
	lem_in->link_count++;
	return (1);
}

void		check_bfr_alg(t_str *lem_in, t_room *rooms)
{
	int i;

	i = -1;
	if (lem_in->buf_start == NULL || lem_in->buf_end == NULL)
		ft_exit(lem_in, rooms, 1);
	while (lem_in->buf_start[++i] != '\0')
		if (lem_in->buf_start[i] == ' ')
			lem_in->buf_start[i] = '\0';
	i = -1;
	while (lem_in->buf_end[++i] != '\0')
		if (lem_in->buf_end[i] == ' ')
			lem_in->buf_end[i] = '\0';
	lem_in->start = ft_binary_search(rooms, 0,
	lem_in->room_count, lem_in->buf_start);
	lem_in->end = ft_binary_search(rooms, 0,
	lem_in->room_count, lem_in->buf_end);
	i = 0;
	while (++i < lem_in->room_count)
		if (!ft_strcmp(rooms[i].arr_room, rooms[i - 1].arr_room))
			ft_exit(lem_in, rooms, 1);
}
