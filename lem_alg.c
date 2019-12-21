/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_alg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 12:23:33 by rmarni            #+#    #+#             */
/*   Updated: 2019/12/21 16:04:25 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void 	tmp_initial_way(t_str *lem_in)
{
	lem_in->count_ways = 1;
	
}

void	ft_print_lem_in(t_room *rooms, int num_ant, int num_room)
{
	ft_printf("L%d-%s\n", num_ant, rooms[num_room].arr_room);
}

void	ft_ant_initial(t_ant *ants, t_str *lem_in, t_pr_way *pr_way)
{
	int i;
	
	i = -1;
	while(++i < lem_in->q_lem)
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

void	ft_short_way(t_pr_way *way, int q_way, t_ant *ants, int current_ant)
{
	int i;
	i = -1;
	int max_num = 9999;
	int i_min;
	
	
	while (++i < q_way)
	{
//		printf ("way[%d].q_elem = %d, way[%d].turn = %d\n", i, way[i].q_elem, i, way[i].turn);
		if(way[i].q_elem + way[i].turn < max_num)
		{
			max_num = way[i].q_elem + way[i].turn;
			i_min = i;
		}
	}
	ants[current_ant].turn = way[i_min].turn;
	ants[current_ant].way = i_min;
	way[i_min].turn++;
//	printf ("HEARE\n");
}

int 	ft_check_finish(int q_ants, t_ant *ants)
{
	int i;

	i = -1;
	while (++i < q_ants)
		if (!ants[i].finish)
			return (0);
	return (1);
}

void	step(t_str *lem_in, t_ant *ants)
{
	int i;
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

void 	ft_lem_alg(t_str *lem_in, int **way, t_room *rooms)
{
	printf("LEM_ALG\n");
	t_ant ants[lem_in->q_lem];
	t_pr_way pr_way[lem_in->count_ways];
	ft_ant_initial(ants, lem_in, pr_way);
	
	int i;
	i = 0;


	while (i < lem_in->q_lem)
	{
		ft_short_way(pr_way, lem_in->count_ways, ants, i);
		i++;
	}
//	i = -1;
//	for (int x = 0; x < lem_in->q_lem; x++)
//			printf ("ant[%d] %d, turn = %d, finish = %d;\n",i + 1,  ants[x].way, ants[x].turn, ants[x].finish);

	i = 0;

	while (!ft_check_finish(lem_in->q_lem, ants))
	{

		while (i < lem_in->q_lem)
		{
			if (ants[i].turn <= 0 && !ants[i].finish)
				ft_printf("L%d-%s ", ants[i].num_ant, rooms[way[ants[i].way][ants[i].position]].arr_room);
//			printf ("\nway[ants[i] = %d,  lem_in->end = %d, i= %d\n", way[ants[i].way][ants[i].position], lem_in->end, i);
			if (way[ants[i].way][ants[i].position] == lem_in->end && ants[i].turn <= 0)
				ants[i].finish = 1;
			i++;

		}
//		for (int x = 0; x < lem_in->q_lem; x++)
//			printf ("ant[%d] %d, turn = %d, finish = %d;\n",x + 1,  ants[x].way, ants[x].turn, ants[x].finish);
//		exit (0);

		i = 0;
		step(lem_in, ants);
	}
}