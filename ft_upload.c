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
	lst->this = lst;
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
	while (--len >= 0)
	{
		lst->next = lst_create();
		if (lst->next == NULL)
			return (NULL);
		lst->next->prev = lst;
		lst = lst->next;
	}
	return (tmp);
}

void	ft_print(int **tab, int x)
{
	int i = 0;
	int j = 0;

	while (i < x)
	{
		j = 0;
		while (j < x)
			printf("%d ", tab[i][j++]);
		printf("\n");
		i++;
	}
}

int		visited(t_str *lem_in, t_way **way, int p, int q)
{
	t_way *l;
	l = way[q]->head;

	while (l)
	{
		if (l->x == p)
			return (1);
		if (!l->next)
			return (0);
		l = l->next;
	}
	return (0);
}

int **copy_tab(int **tab, int x)
{
	int **tabb;
	int		i;
	int 	j;

	i = 0;
	tabb = (int **)malloc(sizeof(int *) * x);
	while (i < x)
	{
		j = 0;
		tabb[i] = (int *)malloc(sizeof(int) * x);
		while (j < x)
		{
			tabb[i][j] = tab[i][j];
			j++;
		}
		i++;
	}
	return (tabb);
}

t_way *copy_way(t_way *way)
{
	t_way *head;
	t_way *q;

	q = lst_create();
	head = way->head;
	q->x = head->x;
	q->y = head->y;
	q->head = q;
	q->next = lst_create();
	q->next->prev = q;
	q = q->next;
	q->head = q->prev->head;
	head = head->next;
	while (head->next)
	{
		q->x = head->x;
		q->y = head->y;
		q->next = lst_create();
		q->next->prev = q;
		q = q->next;
		q->head = q->prev->head;
		head = head->next;
	}
	return (q);
}

int 	p_busy(int **tab, t_way *z, int c, t_str *lem, int b, int a)
{
	int i;
	t_way *o;
	
	if (!z)
		return (0);
	o = z->head;
	i = 0;
//	while (lem->tab[a][b] != 1 && b < lem->room_count)
//		b++;
//	if (b >= lem->room_count)
//		return  (1);
	while (i < c && b < lem->room_count)
	{
		if (tab[a][i] == 2 && i != z->x)
			return (1);
		while (o->next)
		{
			if (tab[o->x][b] && tab[o->x][b] == 1)
			{
				tab[o->x][b] = 2;
				tab[b][o->x] = 2;
				return (1);
			}
			o = o->next;
		}
		i++;
	}
	return (0);
}

void	set_way(t_str *lem_in, t_way **way, int p, int z, int q, int **tab)
{
	int sas;
	int **tabb;
	t_way *o;

	tabb = copy_tab(tab, lem_in->room_count);
	if (!way[q])
	{
		way[q] = lst_create();
		way[q]->head = way[q];
	}
	if (way[q]->prev)
		way[q]->head = way[q]->prev->head;
	else
		way[q]->head = way[q];
	ft_printf("\n");
	ft_print(tabb, lem_in->room_count);
	o = way[q]->prev ? way[q]->prev : NULL;
	if (p != *lem_in->end - '0' && p < lem_in->room_count)
	{
		while (z < lem_in->room_count && tab[p][z] != 1)
			z++;
		if (way[q] && tabb[p][z] == 1 && z < lem_in->room_count)
		{
			sas = q;
			while (way[sas])
				sas++;
			way[sas] = lst_create();
			if (way[q]->next || way[q]->prev)
				way[sas] = copy_way(way[q]);
			lem_in->count_ways = sas;
			set_way(lem_in, way, p,  z + 1, sas, tabb);
		}
		if (tabb[p][z] == 1 && z < lem_in->room_count  && !p_busy(tab, o, lem_in->room_count, lem_in, z, p) )
		{
			way[q]->x = p;
			way[q]->y = z;
			way[q]->next = lst_create();
			way[q]->next->prev = way[q];
			way[q] = way[q]->next;
			way[q]->head = way[q]->prev->head;
			tabb[p][z] = 2;
			tabb[z][p] = 2;
			ft_printf("\n");
			ft_print(tabb, lem_in->room_count);
			p = z;
			set_way(lem_in, way, p, 0, q, tabb);
		}
		else if (p != *lem_in->end - '0')
		{
			free(way[q]);
			way[q] = NULL;
		}
	}
	else if (p != *lem_in->end - '0')
	{
		free(way[q]);
		way[q] = NULL;
	}
}

void init_way(t_str *lem, t_way **way)
{
	int *q;
	int i;
	int j;
	while (i <= lem->count_ways)
	{
		j = i + 1;
		if (!way[i])
		{
			while (!way[j] && j < lem->count_ways)
				j++;
			if (way[j])
			{
				way[i] = copy_way(way[j]);
				free(way[j]);
				way[j] = NULL;
				lem->count_ways--;
			}
		}
		i++;
	}
}

int		must_insert(t_way ***disjoint_way, int q, t_way *way, t_str *lem)
{
	int j;
	int p;

	j = 0;
	while (way)
	{
		j = 0;
		while (disjoint_way[q][j])
		{
			disjoint_way[q][j] = disjoint_way[q][j]->head;
			while (disjoint_way[q][j]->y != *lem->end - '0')
			{
				if (disjoint_way[q][j]->y == way->y)
				{
					return (0);
				}
				disjoint_way[q][j] = disjoint_way[q][j]->next;
			}
			j++;
		}
		way = way->next;
	}
	return (1);
}

t_way	***disjoint_ways(t_way **way, t_str *lem)
{
	t_way	***disjoint_ways;
	int		i;
	int		j;
	int		q;
	int		p;
	int		l;
	int		t;
	int		flag;

	flag = 0;
	q = 0;
	i = 0;
	j = 0;
	p = 0;
	disjoint_ways = (t_way ***)malloc(sizeof(t_way **) * 40);
	while (way[i])
	{
		disjoint_ways[q] = (t_way **)malloc(sizeof(t_way) * 40);
		disjoint_ways[q][p] = copy_way(way[i]->head);
		q++;
//		disjoint_ways[q] = (t_way **)malloc(sizeof(t_way) * 40);
		j = i;
//		if (way[j])
		{
			l = q - 1;
			t = 0;
			while (l >= 0)
			{
				if (disjoint_ways[l][t] && must_insert(disjoint_ways, l, way[j]->head, lem))
				{
					disjoint_ways[q] = (t_way **)malloc(sizeof(t_way) * 40);
					while (disjoint_ways[l][t])
					{
						disjoint_ways[q][t] = copy_way(disjoint_ways[l][t]);
						t++;
					}
					disjoint_ways[q][t] = copy_way(way[j]);
					q++;
				}
//				else
//				{
//					j++;
//					continue;
//				}
				l--;
			}
			j++;
		}
		i++;
	}
	return (disjoint_ways);
}

int		main(int ac, char **av)
{
	t_str lem_in;
	t_way	**way;
	t_way	*l;
	int		count;
	t_way ***disjoint_way;

	lem_in.fd = open(av[1], O_RDONLY);
	ft_read_map(&lem_in);
	table(&lem_in);
	way = (t_way **)malloc(sizeof(t_way) * 40);
	l = way[0];
	lem_in.count_ways = 0;
	set_way(&lem_in, way, (*lem_in.start - '0'), 0, 0, lem_in.tab);
	init_way(&lem_in, way);
	disjoint_way = disjoint_ways(way, &lem_in);
	int i;
	int j;
	i = 0;
	while (disjoint_way[i])
	{
		j = 0;
		while (disjoint_way[i][j])
		{
			disjoint_way[i][j] = disjoint_way[i][j]->head;
			while (disjoint_way[i][j]->next)
			{
				ft_printf("%d  ->   %d\n", disjoint_way[i][j]->x, disjoint_way[i][j]->y);
				disjoint_way[i][j] = disjoint_way[i][j]->next;
			}
			j++;
			printf("\n");
		}
		printf("----------------------\n");
		i++;
	}
//	while (i < 41)
//	{
//		if (way[i])
//		{
//			way[i] = way[i]->head;
//			while (way[i]->next)
//			{
//				printf("%d ->  %d\n", way[i]->x, way[i]->y);
//				way[i] = way[i]->next;
//			}
//			printf("\n");
//			count++;
//		}
//		i++;
//	}
	printf("%d\n", count);
//	printf("lem.start = %s lem.end = %s\n", lem_in.arr_links[0][0], lem_in.arr_links[0][1]);
//	printf("lem.start = %s lem.end = %s\n", lem_in.arr_links[1][0], lem_in.arr_links[1][1]);
//	printf("lem.start = %s lem.end = %s\n", lem_in.arr_links[2][0], lem_in.arr_links[2][1]);
//	printf("lem.start = %s lem.end = %s\n", lem_in.arr_links[3][0], lem_in.arr_links[3][1]);
//	printf("lem.start = %s lem.end = %s\n", lem_in.arr_links[4][0], lem_in.arr_links[4][1]);
}

