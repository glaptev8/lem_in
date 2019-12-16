/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 17:58:56 by rmarni            #+#    #+#             */
/*   Updated: 2019/12/16 15:19:50 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void 	ft_exit(t_str *lem_in, t_room *rooms,  int flag)
{
	int i;

	i = 0;
	while (i < lem_in->room_count)
	{
		free(rooms[i].arr_room[0]);
		i++;
	}
	if (flag)
		ft_printf(RED("Error\n"));
	exit(0);
}