/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_alg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 12:23:33 by rmarni            #+#    #+#             */
/*   Updated: 2019/12/19 16:06:01 by rmarni           ###   ########.fr       */
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
		ants[i].position = 0;
		ants[i].finish = 0;
		ants[i].turn = 0;
	}
	i = 0;
	while (i < 2)
	{
		pr_way[i].num = i;
		pr_way[i].q_elem = 2;
		pr_way[i].turn = 0;
		i++;
	}
}

void	ft_short_way(t_pr_way *way, int q_way, t_ant *ants, int current_ant)
{
	int i;
	i = -1;
	
	
	while (++i < q_way)
	{
		printf ("way[%d].q_elem = %d, way[%d].turn = %d\n", i, way[i].q_elem, i, way[i].turn);
		if(i + 1 < q_way && way[i].q_elem + way[i].turn <= way[i + 1].turn + way[i + 1].q_elem)
		{
			ants[current_ant].turn = way[i].turn;
			ants[current_ant].way = i;
			way[i].turn++;
			
			return ;
		}
//		i++;
	}
	i--;
//	return ;
	ants[current_ant].turn = way[i].turn;
	ants[current_ant].way = i;
	way[i].turn++;
	printf ("HEARE\n");
}

void 	ft_lem_alg(t_str *lem_in, t_way **way, t_room *rooms)
{
	t_ant ants[lem_in->q_lem];
	int q_ways = 2;
	t_pr_way pr_way[q_ways];
	int	way11[3] = {4, 0, 3};
	int way22[3] = {4, 0, 3};
	ft_ant_initial(ants, lem_in, pr_way);
	
	int i;
	i = 0;
	
	while (i < lem_in->q_lem)
	{
		ft_short_way(pr_way, q_ways, ants, i);
		i++;
	}
	i = -1;
	while (++i < lem_in->q_lem)
		printf ("ant[%d] %d\n",i,  ants[i].turn);





//	int	way1[3] = {4, 0, 3};
//
//	int i = 1;
//	int j = 0;
//
//	while (i <= lem_in->q_lem)
//	{
//		while (j < 3)
//		{
//			ft_print_lem_in(rooms, i, way1[j]);
//			j++;
//		}
//
//		if (j == 3)
//			j = 0;
//		i++;
//	}

}