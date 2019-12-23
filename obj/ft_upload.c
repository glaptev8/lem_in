/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upload.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 17:00:58 by rmarni            #+#    #+#             */
/*   Updated: 2019/12/23 15:25:36 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
**	1. Rooms can't be equal  ***ft_room_equal****				ok!
** 	2. Coords only digit										ok!
** 	3. Rooms has only three parameters (2-coords and name)		ok!
** 	4. Rooms can't start with 'L' ch or '#'						ok!
**	5. Links similar to one of rooms name						ok!
**	6. Start should has link;   *** start_end ****				ok!
**	7. End should has link;										ok!
**	8. First parameter only number								ok!
*/

void		ft_start_end_norma(char *str, t_str *lem_in, t_room *rooms, int i)
{
	if (!ft_strcmp(str + 2, "end"))
	{
		free(lem_in->buf);
		get_next_line(lem_in->fd, &lem_in->buf);
		ft_printf("%s\n", lem_in->buf);
		while (ft_isprint(lem_in->buf[i]))
			i++;
		if (i == 0)
			ft_exit(lem_in, rooms, 1);
		rooms[lem_in->room_count].arr_room = ft_strdup(lem_in->buf);
		ft_slash_zero(rooms, lem_in->room_count, ' ');
		lem_in->buf_end = ft_strdup(lem_in->buf);
		lem_in->room_count++;
		return ;
	}
}

void		ft_start_end(char *str, t_str *lem_in, t_room *rooms, int i)
{
	if (!ft_isprint(str[3]))
		ft_exit(lem_in, rooms, 1);
	while (ft_isprint(str[i]) && str[i] != ' ')
		i++;
	if (str[i] != 0)
		ft_exit(lem_in, rooms, 1);
	if (!ft_strcmp(str + 2, "start"))
	{
		free(lem_in->buf);
		get_next_line(lem_in->fd, &lem_in->buf);
		ft_printf("%s\n", lem_in->buf);
		if (lem_in->buf[0] == '#')
		{
			free(lem_in->buf);
			get_next_line(lem_in->fd, &lem_in->buf);
		}
		rooms[lem_in->room_count].arr_room = ft_strdup(lem_in->buf);
		ft_slash_zero(rooms, lem_in->room_count, ' ');
		lem_in->buf_start = ft_strdup(lem_in->buf);
		lem_in->room_count++;
		return ;
	}
	ft_start_end_norma(str, lem_in, rooms, 0);
}

void		ft_slash_zero(t_room *rooms, int i, char c)
{
	int		j;

	j = 0;
	while (rooms[i].arr_room[j] != '\0')
	{
		if (rooms[i].arr_room[j] == c)
			rooms[i].arr_room[j] = '\0';
		j++;
	}
}

int			is_room(char *str, t_str *lem_in, t_room *rooms)
{
	if (str[0] == '#')
	{
		if (str[0] == '#' && str[1] == '#')
			ft_start_end(str, lem_in, rooms, 0);
		return (0);
	}
	rooms[lem_in->room_count].arr_room = ft_strdup(str);
	ft_slash_zero(rooms, lem_in->room_count, ' ');
	return (1);
}

void		ft_slash_zero_link(char *str, char c)
{
	int		j;

	j = 0;
	while (str[j])
	{
		if (str[j] == c)
			str[j] = '\0';
		j++;
	}
}
