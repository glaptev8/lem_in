/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 15:21:41 by rmarni            #+#    #+#             */
/*   Updated: 2019/12/23 16:17:24 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_check_q_lem(t_str *lem_in, t_room *rooms)
{
	int		i;

	while (lem_in->buf[0] == '#')
	{
		ft_printf("%s\n", lem_in->buf);
		free(lem_in->buf);
		get_next_line(lem_in->fd, &lem_in->buf);
	}
	i = 0;
	while (lem_in->buf[i])
	{
		if (!isdigit(lem_in->buf[i]))
			ft_exit(lem_in, rooms, 1);
		i++;
	}
	lem_in->q_lem = ft_atoi(lem_in->buf);
	if (lem_in->q_lem < 1)
		ft_exit(lem_in, rooms, 1);
	free(lem_in->buf);
}

void		ft_read_map(t_str *lem_in, t_room *rooms)
{
	if (get_next_line(lem_in->fd, &lem_in->buf) < 1)
		ft_exit(lem_in, rooms, 1);
	ft_printf("%s\n", lem_in->buf);
	ft_check_q_lem(lem_in, rooms);
	while (get_next_line(lem_in->fd, &lem_in->buf))
	{
		ft_printf("%s\n", lem_in->buf);
		if (is_links(lem_in, rooms))
			return ;
		if (is_room(lem_in->buf, lem_in, rooms))
			lem_in->room_count++;
		free(lem_in->buf);
	}
}

void		ft_initial_lem(t_str *lem_in, t_room *rooms)
{
	lem_in->room_count = 0;
	lem_in->link_count = 0;
	lem_in->buf_start = NULL;
	lem_in->buf_end = NULL;
	rooms[0].visit = 0;
	rooms[0].lvl = -1;
}

int			main(int ac, char **av)
{
	t_str	lem_in;
	t_room	rooms[NUM_RM];
	int		**way;

	ft_initial_lem(&lem_in, rooms);
	if (ac > 1)
	{
		ft_printf(GREEN("Please upload the valid Lem-in farm\n"));
		ft_exit(&lem_in, rooms, 0);
	}
	else
	{
		lem_in.fd = 0;
		ft_read_map(&lem_in, rooms);
		check_bfr_alg(&lem_in, rooms);
	}
	way = get_ways(&lem_in, rooms);
	if (lem_in.room_count > 4010 || lem_in.count_ways == 0)
		ft_exit(&lem_in, rooms, 1);
	ft_lem_alg(&lem_in, way, rooms);
	ft_exit(&lem_in, rooms, 0);
	exit(0);
}
