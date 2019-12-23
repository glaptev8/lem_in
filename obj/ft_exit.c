/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 17:58:56 by rmarni            #+#    #+#             */
/*   Updated: 2019/12/23 15:31:31 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_exit(t_str *lem_in, t_room *rooms, int flag)
{
	int	i;

	i = -1;
	while (++i < lem_in->room_count)
		free(rooms[i].arr_room);
	if (flag)
		ft_printf(RED("Error\n"));
	exit(0);
}
