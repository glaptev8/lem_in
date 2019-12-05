#include "header.h"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upload.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 17:00:58 by rmarni            #+#    #+#             */
/*   Updated: 2019/12/03 18:01:54 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void 	ft_start_end(char *str, t_str *lem_in)
{
	int i;

	i = 0;
	if (!ft_isprint(str[3]))					// validation if any chr after "start" && "end";
		ft_exit(lem_in);
	while(ft_isprint(str[i]) && str[i] != ' ')
		i++;
	if (str[i] != 0)
		ft_exit(lem_in);
	i = 0;
	if (!ft_strcmp(str + 2, "start"))
	{
		get_next_line(lem_in->fd, &lem_in->buf);
		while (ft_isprint(lem_in->buf[i]))
			i++;
		if (i == 0)// || str[i] != 0)
			ft_exit(lem_in);
		lem_in->arr_room[lem_in->room_count] = ft_strsplit(lem_in->buf, ' ');
		lem_in->start = lem_in->arr_room[lem_in->room_count][0];
		check_room(lem_in);
		lem_in->room_count++;
		return ;
	}
	if (!ft_strcmp(str + 2, "end"))
	{
		get_next_line(lem_in->fd, &lem_in->buf);
		while (ft_isprint(lem_in->buf[i]))
			i++;
		if (i == 0)// || str[i] != 0)
			ft_exit(lem_in);
		lem_in->arr_room[lem_in->room_count] = ft_strsplit(lem_in->buf, ' ');
		lem_in->end = lem_in->arr_room[lem_in->room_count][0];
		check_room(lem_in);
		lem_in->room_count++;
		return ;
	}
	ft_exit(lem_in);
}

int 	count_chr(char *str, int i, char chr)
{
	int j;

	j = 0;
	while (str[++i])
		if(str[i] == chr)
			j++;
	return (j);
}

void	check_room(t_str *lem_in)
{
	int i;

	i = 0;
	if (lem_in->buf[i] == 'L')
		ft_exit(lem_in);
	if (count_chr(lem_in->buf, -1, ' ') != 2)
		ft_exit(lem_in);
	while (lem_in->arr_room[lem_in->room_count][1][i])
	{
		if (!ft_isdigit(lem_in->arr_room[lem_in->room_count][1][i]))
			ft_exit(lem_in);
		i++;
	}
	i = 0;
	while (lem_in->arr_room[lem_in->room_count][2][i])
	{
		if (!ft_isdigit(lem_in->arr_room[lem_in->room_count][2][i]))
			ft_exit(lem_in);
		i++;
	}
}

void	check_link(t_str *lem_in)
{
	int i;

	i = 0;
	if (lem_in->buf[i] == 'L')
		ft_exit(lem_in);
	if (count_chr(lem_in->buf, -1, ' ') != 0 || count_chr(lem_in->buf, -1, '-') != 1)
		ft_exit(lem_in);

	while (i < lem_in->room_count) //lem_in->arr_room[lem_in->room_count][1][i])
	{
		if (!ft_strcmp(lem_in->arr_links[lem_in->link_count][0], lem_in->arr_room[i][0]))
			return ;
		i++;
	}

	ft_exit(lem_in);
/*	i = 0;
	while (lem_in->arr_room[lem_in->room_count][2][i])
	{
		if (!ft_isdigit(lem_in->arr_room[lem_in->room_count][2][i]))
			ft_exit(lem_in);
		i++;
	}
*/
}

int 	is_room(char *str, t_str *lem_in)
{
	if (str[0] == '#')
	{
		if (str[0] == '#' && str[1] == '#')		// probably start or end instr
			ft_start_end(str, lem_in);
		return (0);
	}
	lem_in->arr_room[lem_in->room_count] = ft_strsplit(str, ' ');//ft_strdup(lem_in->buf);
	check_room(lem_in);
	return (1);
}

int		is_links(t_str *lem_in)
{
	int i;

	i = 0;
	if (lem_in->buf[0] == '#')
		return (0);
	while (lem_in->buf[i])
	{
		if (lem_in->buf[i] == ' ')
			return (0);
		i++;
	}
	lem_in->link_count = 0;
	lem_in->arr_links[lem_in->link_count] = ft_strsplit(lem_in->buf, '-');
	check_link(lem_in);
	while (get_next_line(lem_in->fd, &lem_in->buf))
	{
		if (lem_in->buf[0] != '#')
		{
			lem_in->link_count++;
			check_link(lem_in);
			lem_in->arr_links[lem_in->link_count] = ft_strsplit(lem_in->buf, '-');
		}
	}
		lem_in->link_count++;
	return (1);
}

void	ft_read_map(t_str *lem_in)
{
	get_next_line(lem_in->fd, &lem_in->buf);
	lem_in->q_lem = ft_atoi(lem_in->buf);
	if (lem_in->q_lem <= 0)
		ft_exit(lem_in);
	while (get_next_line(lem_in->fd, &lem_in->buf))
	{
		if (is_links(lem_in))
			return ;
		if (is_room(lem_in->buf, lem_in))
			lem_in->room_count++;
	}
}

int		main(int ac, char **av)
{
	t_str lem_in;
	lem_in.fd = open(av[1], O_RDONLY);
	ft_read_map(&lem_in);
	close(lem_in.fd);

	printf("lem.start = %s lem.end = %s, lem.in = %s\n", lem_in.arr_room[0][0], lem_in.arr_room[0][1], lem_in.arr_room[0][2]);
	printf("lem.start = %s lem.end = %s, lem.in = %s\n", lem_in.arr_room[1][0], lem_in.arr_room[1][2], lem_in.arr_room[1][3]);
	printf("lem.start = %s lem.end = %s, lem.in = %s\n", lem_in.arr_room[2][0], lem_in.arr_room[2][1], lem_in.arr_room[2][2]);
}

