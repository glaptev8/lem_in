/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 17:58:56 by rmarni            #+#    #+#             */
/*   Updated: 2019/12/10 12:34:57 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void 	ft_exit(t_str *lem_in, int flag)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < lem_in->room_count)
	{
		free(lem_in->arr_room[i][0]);
		free(lem_in->arr_room[i][1]);

		i++;
	}
	while (j < lem_in->link_count)
	{
		free(lem_in->arr_links[j][0]);
		free(lem_in->arr_links[j][1]);
		j++;
	}
/**/
//	free(lem_in->arr_room);
	if (flag)
		ft_printf(RED("Error\n"));
	exit(0);
}