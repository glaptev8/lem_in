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

//	while (i < lem_in->room_count) //lem_in->arr_room[lem_in->room_count][1][i])
//	{
//		if (!ft_strcmp(lem_in->arr_links[lem_in->link_count][0], lem_in->arr_room[i][0]))
//			return ;
//		i++;
//	}

//	ft_exit(lem_in);
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

void    table(t_str *lem_in)
{
	int i;
	int j;
	int a;
	int b;
	
	lem_in->tab = (int **)malloc(sizeof(int *) * lem_in->room_count);
	i = 0;
	j = 0;
	while (i < lem_in->room_count)
	{
		j = 0;
		lem_in->tab[i] = (int *)malloc(sizeof(int) * lem_in->room_count);
		while (j < lem_in->room_count)
		{
			lem_in->tab[i][j] = 0;
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (lem_in->arr_links[i])
	{
		a = *(lem_in->arr_links[i][0]) - '0';
		b = *(lem_in->arr_links[i][1]) - '0';
		lem_in->tab[a][b] = 1;
		lem_in->tab[b][a] = 1;
		i++;
	}
	i = 0;
	while (i < lem_in->room_count)
	{
		j = 0;
		while (j < lem_in->room_count)
			printf("%d ", lem_in->tab[i][j++]);
		printf("\n");
		i++;
	}
}

t_way	*lst_create(void)
{
	t_way *lst;
	
	lst = (t_way *)malloc(sizeof(t_way));
	if (!lst)
		return (NULL);
	lst->next = NULL;
	lst->prev = NULL;
	lst->head = NULL;
	return (lst);
}

t_way *lst_new(int len)
{
	t_way *lst;
	t_way *tmp;
	
	if (len == 0)
	{
		lst = lst_create();
		lst->flag = 0;
		lst->next = lst;
		lst->prev = lst;
		return (lst);
	}
	else
		lst = lst_create();
	tmp = lst;
	while (--len > 0)
	{
		lst->next = lst_create();
		if (lst->next == NULL)
			return (NULL);
		lst->next->prev = lst;
		lst = lst->next;
	}
	tmp->prev = lst;
	lst->next = tmp;
	return (lst);
}

void	set_way(t_str *lem_in, t_way **way, int p, int z, int q)
{
	int sas;
	if (!(way)[q])
	{
		(way)[q] = lst_create();
//		(way)[q]->head = (*way)[q];
	}
	t_way *l;
	l = (way)[q];
	while (p != *lem_in->end - '0' && p < lem_in->room_count)
	{
		while (z < lem_in->room_count && lem_in->tab[p][z] != 1)
			z++;
		if (lem_in->tab[p][z] == 1)
		{
			if (z != *lem_in->end - '0')
			{
				sas = q;
				while ((way)[sas])
					sas++;
				set_way(lem_in, way, p, z + 1, sas);
			}
			if (z == lem_in->room_count)
			{
				z = 0;
				continue;
			}
//			(*way)[q] = lst_create();
			(way)[q]->x = p;
			(way)[q]->y = z;
			(way)[q]->next = lst_create();
			(way)[q] = (way)[q]->next;
			lem_in->tab[p][z] = 2;
			lem_in->tab[z][p] = 2;
			p = z;
			z = 0;
		}
		else
			break;
	}
	int i;
	
//	i = 0;
//	while (i < 2)
//	{
//		printf("%d  ->  %d\n", l->x, l->y);
//		l = l->next;
//		i++;
//	}
}

int		main(int ac, char **av)
{
	t_str lem_in;
	t_way	*way;
	t_way	*l;
	lem_in.fd = open(av[1], O_RDONLY);
	ft_read_map(&lem_in);
	table(&lem_in);
//	way = (t_way *)malloc(sizeof(t_way) * 2);
	set_way(&lem_in, &way, (*lem_in.start - '0'), 0, 0);
//	l = &way[0];
//	close(lem_in.fd);
	int i = 0;
	int j;
	while (i < 3)
	{
//		printf("%d  ->  %d    ", way[0]->x, way[0]->y);
//		printf("%d  ->  %d\n", way[1]->x, way[1]->y);
//		way[0] = way[0]->next;
//		way[1] = way[1]->next;
		i++;
	}
	i = 0;
	while (i < lem_in.room_count)
	{
		j = 0;
		while (j < lem_in.room_count)
			printf("%d ", lem_in.tab[i][j++]);
		printf("\n");
		i++;
	}


//	printf("lem.start = %s lem.end = %s\n", lem_in.arr_links[0][0], lem_in.arr_links[0][1]);
//	printf("lem.start = %s lem.end = %s\n", lem_in.arr_links[1][0], lem_in.arr_links[1][1]);
//	printf("lem.start = %s lem.end = %s\n", lem_in.arr_links[2][0], lem_in.arr_links[2][1]);
//	printf("lem.start = %s lem.end = %s\n", lem_in.arr_links[3][0], lem_in.arr_links[3][1]);
//	printf("lem.start = %s lem.end = %s\n", lem_in.arr_links[4][0], lem_in.arr_links[4][1]);
}

