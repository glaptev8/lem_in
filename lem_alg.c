/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_alg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 12:23:33 by rmarni            #+#    #+#             */
/*   Updated: 2019/12/23 12:12:28 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			ft_ant_initial(t_ant *ants, t_str *lem_in, t_pr_way *pr_way)
{
	int			i;

	i = -1;
	while (++i < lem_in->q_lem)
	{
		ants[i].num_ant = i + 1;
		ants[i].position = 1;
		ants[i].finish = 0;
		ants[i].turn = 0;
	}
	i = 0;
	while (i < lem_in->count_ways)
	{
		pr_way[i].num = i;
		pr_way[i].q_elem = lem_in->len_ways[i];
		pr_way[i].turn = 0;
		i++;
	}
}

void			ft_short_way(t_pr_way *way, int q_way, t_ant *ants, int c_ant)
{
	int			i;
	int			max_num;
	int			i_min;

	i = -1;
	max_num = 99999999;
	while (++i < q_way)
	{
		if (way[i].q_elem + way[i].turn < max_num)
		{
			max_num = way[i].q_elem + way[i].turn;
			i_min = i;
		}
	}
	ants[c_ant].turn = way[i_min].turn;
	ants[c_ant].way = i_min;
	way[i_min].turn++;
}

int				ft_check_finish(int q_ants, t_ant *ants)
{
	int			i;

	i = -1;
	while (++i < q_ants)
		if (!ants[i].finish)
			return (0);
	return (1);
}

void			step(t_str *lem_in, t_ant *ants)
{
	int			i;

	i = 0;
	while (i < lem_in->q_lem)
	{
		ants[i].turn--;
		i++;
	}
	i = 0;
	while (i < lem_in->q_lem)
	{
		if (ants[i].turn < 0)
			ants[i].position++;
		i++;
	}
	ft_printf("\n");
}

void			ft_lem_alg(t_str *lem_in, int **way, t_room *rooms)
{
	t_ant		ants[lem_in->q_lem];
	t_pr_way	pr_way[lem_in->count_ways];
	int			i;

	ft_ant_initial(ants, lem_in, pr_way);
	i = -1;
	while (++i < lem_in->q_lem)
		ft_short_way(pr_way, lem_in->count_ways, ants, i);
	i = 0;
	while (!ft_check_finish(lem_in->q_lem, ants))
	{
		while (i < lem_in->q_lem)
		{
			if (ants[i].turn <= 0 && !ants[i].finish)
				ft_printf("L%d-%s ", ants[i].num_ant,
				rooms[way[ants[i].way][ants[i].position]].arr_room);
			if (way[ants[i].way][ants[i].position] == lem_in->end
			&& ants[i].turn <= 0)
				ants[i].finish = 1;
			i++;
		}
		i = 0;
		step(lem_in, ants);
	}
}
