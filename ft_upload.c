/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upload.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 17:00:58 by rmarni            #+#    #+#             */
/*   Updated: 2019/12/16 17:56:22 by rmarni           ###   ########.fr       */
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

void	check_room(t_str *lem_in)
{
	int i;

	i = 0;
	if (lem_in->buf[i] == 'L')
		ft_exit(lem_in, 1);
	if (count_chr(lem_in->buf, -1, ' ') != 2)
		ft_exit(lem_in, 1);
	while (lem_in->arr_room[lem_in->room_count][1][i])
	{
		if (!ft_isdigit(lem_in->arr_room[lem_in->room_count][1][i]))
			ft_exit(lem_in, 1);
		i++;
	}
	i = 0;
	while (lem_in->arr_room[lem_in->room_count][2][i])
	{
		if (!ft_isdigit(lem_in->arr_room[lem_in->room_count][2][i]))
			ft_exit(lem_in, 1);
		i++;
	}
}


void		ft_start_end_norma(char *str, t_str *lem_in, t_room *rooms, int i)
{
	if (!ft_strcmp(str + 2, "end"))
	{
		free(lem_in->buf);
		get_next_line(lem_in->fd, &lem_in->buf);
		while (ft_isprint(lem_in->buf[i]))
			i++;
		if (i == 0)
			ft_exit(lem_in, rooms, 1);
		rooms[lem_in->room_count].arr_room[0] = ft_strdup(lem_in->buf);
		ft_slash_zero(rooms, lem_in->room_count, ' ');
		lem_in->buf_end = ft_strdup(lem_in->buf);
		lem_in->room_count++;
		return ;
	}
	ft_exit(lem_in, rooms, 1);
}

void		ft_start_end(char *str, t_str *lem_in, t_room *rooms)
{
	int		i;

	i = 0;
	if (!ft_isprint(str[3]))
		ft_exit(lem_in, rooms, 1);
	while (ft_isprint(str[i]) && str[i] != ' ')
		i++;
	if (str[i] != 0)
		ft_exit(lem_in, rooms, 1);
	i = 0;
	if (!ft_strcmp(str + 2, "start"))
	{
		free(lem_in->buf);
		get_next_line(lem_in->fd, &lem_in->buf);
		while (ft_isprint(lem_in->buf[i]))
			i++;
		if (i == 0)
			ft_exit(lem_in, rooms, 1);
		rooms[lem_in->room_count].arr_room[0] = ft_strdup(lem_in->buf);
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
	while (rooms[i].arr_room[0][j] != '\0')
	{
		if (rooms[i].arr_room[0][j] == c)
			rooms[i].arr_room[0][j] = '\0';
		j++;
	}
}
/**
int			is_room(char *str, t_str *lem_in, t_room *rooms)
{
	if (str[0] == '#')
	{
		if (str[0] == '#' && str[1] == '#')
			ft_start_end(str, lem_in, rooms);
		return (0);
	}
	check_room(str)
	rooms[lem_in->room_count].arr_room[0] = ft_strdup(str);
	ft_slash_zero(rooms, lem_in->room_count, ' ');
	return (1);
}
**/

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

void		ft_check_q_lem(t_str *lem_in, t_room *rooms)
{
	int		i;

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
	get_next_line(lem_in->fd, &lem_in->buf);
	ft_check_q_lem(lem_in, rooms);
	while (get_next_line(lem_in->fd, &lem_in->buf))
	{
		if (is_links(lem_in, rooms))
			return ;
		if (is_room(lem_in->buf, lem_in, rooms))
			lem_in->room_count++;
		free(lem_in->buf);
	}
}

int			main(int ac, char **av)
{
	t_str	lem_in;
	t_room	rooms[5000];

	lem_in.room_count = 0;
	lem_in.link_count = 0;
	if (ac == 2)
	{
		lem_in.fd = open(av[1], O_RDONLY);
		ft_read_map(&lem_in, rooms);
		close(lem_in.fd);
/*
		for (int j = 0; j < lem_in.room_count; j++)
			for (int x = 0; x < rooms[j].size_link_arr; x++)
				printf ("room[%d] = \"%s\"; link[%x] = %s\n", j, rooms[j].arr_room[0], x, rooms[rooms[j].arr_link[x]].arr_room[0]);
		ft_printf(GREEN("Ok\n"));
*/		ft_exit(&lem_in, rooms, 0);
	}
	else
		ft_exit(&lem_in, rooms, 1);
}
//	printf ("room[7] = \"%s\", room[7].link[0] = %d, room[7].link[1] = %d;\n", rooms[7].arr_room[0], rooms[7].arr_link[0], rooms[7].arr_link[1]);