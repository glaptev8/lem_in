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

int 	ft_check_start_end(t_str *lem_in, char *str)
{
	int i;

	i = 0;
	while (i < lem_in->link_count)
	{
		if (!ft_strcmp(lem_in->arr_links[i][0], str) || !ft_strcmp(lem_in->arr_links[i][1], str))
			return (1);
		i++;
	}
	return (0);
}

void	start_end_link(t_str *lem_in)
{
	int i;

	i = 0;
	if (lem_in->link_count > 1)
	{
		while (i < lem_in->link_count)
		{
			if (!ft_check_start_end(lem_in, lem_in->start))
				ft_exit(lem_in, 1);
			if (!ft_check_start_end(lem_in, lem_in->end))
				ft_exit(lem_in, 1);
			i++;
		}
	}
}

int 	ft_check_link_equal(t_str *lem_in, int i, int k)			//
{
	int j;

	j = 0;
	while (j < lem_in->room_count)
	{
		if (!ft_strcmp(lem_in->arr_links[i][k], *lem_in->arr_room[j]))
			return (1);
		j++;
	}
	return (0);
}

void	ft_link_equal(t_str *lem_in)
{
	int i;

	i = 0;
	if (lem_in->link_count > 1)
	{
		while (i < lem_in->link_count)
		{
			if (!ft_check_link_equal(lem_in, i, 0))
				ft_exit(lem_in, 1);
			if (!ft_check_link_equal(lem_in, i, 1))
				ft_exit(lem_in, 1);
			i++;
		}
	}
}

int 	ft_check_equal(t_str *lem_in, int i)
{
	int j;

	j = 0;
	while (j < lem_in->room_count)
	{
		if (!ft_strcmp(*lem_in->arr_room[i], *lem_in->arr_room[j]) && j != i)
			return (0);
		j++;
	}
	return (1);
}

void	ft_room_equal(t_str *lem_in)
{
	int i;

	i = 0;
	if (lem_in->room_count > 1)
	{
		while (i < lem_in->room_count)
		{
			if (!ft_check_equal(lem_in, i))
				ft_exit(lem_in, 1);
			i++;
		}
	}
}

void 	ft_start_end(char *str, t_str *lem_in)
{
	int i;

	i = 0;
	if (!ft_isprint(str[3]))					// validation if any chr after "start" && "end";
		ft_exit(lem_in, 1);
	while(ft_isprint(str[i]) && str[i] != ' ')
		i++;
	if (str[i] != 0)
		ft_exit(lem_in, 1);
	i = 0;
	if (!ft_strcmp(str + 2, "start"))
	{
		free (lem_in->buf);
		get_next_line(lem_in->fd, &lem_in->buf);
		while (ft_isprint(lem_in->buf[i]))
			i++;
		if (i == 0)// || str[i] != 0)
			ft_exit(lem_in, 1);
		lem_in->arr_room[lem_in->room_count] = ft_strsplit(lem_in->buf, ' ');
		lem_in->start = lem_in->arr_room[lem_in->room_count][0];
		check_room(lem_in);
		lem_in->room_count++;
//		free(lem_in->buf);
		return ;
	}
	if (!ft_strcmp(str + 2, "end"))
	{
		free (lem_in->buf);
		get_next_line(lem_in->fd, &lem_in->buf);
		while (ft_isprint(lem_in->buf[i]))
			i++;
		if (i == 0)// || str[i] != 0)
			ft_exit(lem_in, 1);
		lem_in->arr_room[lem_in->room_count] = ft_strsplit(lem_in->buf, ' ');
		lem_in->end = lem_in->arr_room[lem_in->room_count][0];
		check_room(lem_in);
		lem_in->room_count++;
//		free(lem_in->buf);
		return ;
	}
	ft_exit(lem_in, 1);
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
void	check_link(t_str *lem_in)
{
	int i;

	i = 0;
	if (lem_in->buf[i] == 'L')
		ft_exit(lem_in, 1);
	if (count_chr(lem_in->buf, -1, ' ') != 0 || count_chr(lem_in->buf, -1, '-') != 1)
		ft_exit(lem_in, 1);
}
int 	is_room(char *str, t_str *lem_in)
{
	if (str[0] == '#')
	{
		if (str[0] == '#' && str[1] == '#')		// probably start or end instr
		{
			ft_start_end(str, lem_in);
//			free(lem_in->buf);
		}

		return (0);
	}
	lem_in->arr_room[lem_in->room_count] = ft_strsplit(str, ' ');		//ft_strdup(lem_in->buf);
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
	free(lem_in->buf);
	while (get_next_line(lem_in->fd, &lem_in->buf))
	{
		if (lem_in->buf[0] != '#')
		{
			lem_in->link_count++;
			check_link(lem_in);
			lem_in->arr_links[lem_in->link_count] = ft_strsplit(lem_in->buf, '-');
//			free(lem_in->buf);
		}
		free(lem_in->buf);
	}
//	free(lem_in->buf);
	lem_in->link_count++;
	return (1);
}
void	ft_check_q_lem(t_str *lem_in)			//check the correct num of Lem;
{
	int i;

	i = 0;
	while (lem_in->buf[i])
	{
		if (!isdigit(lem_in->buf[i]))
			ft_exit(lem_in, 1);
		i++;
	}
	lem_in->q_lem = ft_atoi(lem_in->buf);
	if (lem_in->q_lem <= 0)
		ft_exit(lem_in, 1);
	free(lem_in->buf);
}
void	ft_read_map(t_str *lem_in)
{
	get_next_line(lem_in->fd, &lem_in->buf);	//check first line of parameter - это кол-во муравьев;
	ft_check_q_lem(lem_in);
	while (get_next_line(lem_in->fd, &lem_in->buf))
	{
		if (is_links(lem_in))
			return ;
		if (is_room(lem_in->buf, lem_in))
			lem_in->room_count++;
		free(lem_in->buf);
	}
//	free(lem_in->buf);

}

int		get_room_index(t_str *lem_in, char *str)				//return num of index from room arr;
{
	int i;

	i = 0;
	while (i < lem_in->room_count)
	{
		if (!ft_strcmp(lem_in->arr_room[i][0], str))
			return (i);
		i++;
	}

	return (i);
}

void	clone_arr(t_str *lem_in)							//make clone of link in int
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < lem_in->link_count)
	{
		lem_in->clone_arr_links[i][0] = get_room_index(lem_in, lem_in->arr_links[i][0]);
		lem_in->clone_arr_links[i][1] = get_room_index(lem_in, lem_in->arr_links[i][1]);

//		printf("%d \n", lem_in->clone_arr_links[i][0]);
		i++;
	}

	i = 0;
	while (i < lem_in->link_count)
	{
		printf("%d %d\n", lem_in->clone_arr_links[i][0], lem_in->clone_arr_links[i][1]);
		i++;
	}


}


int		main(int ac, char **av)
{
	t_str lem_in;
	lem_in.fd = open(av[1], O_RDONLY);
	ft_read_map(&lem_in);
//	ft_tab_comp(&lem_in);
	close(lem_in.fd);
	ft_room_equal(&lem_in);
	ft_link_equal(&lem_in);
	start_end_link(&lem_in);

	clone_arr(&lem_in);

/*

	printf("lem.start = %s lem.end = %s\n", lem_in.arr_room[0][0], lem_in.arr_room[0][1]);
	printf("lem.start = %s lem.end = %s\n", lem_in.arr_room[1][0], lem_in.arr_room[1][2]);
	printf("lem.start = %s lem.end = %s\n", lem_in.arr_room[2][0], lem_in.arr_room[2][1]);
	*/
	ft_printf(GREEN("Ok\n"));
	ft_exit(&lem_in, 0);
}

