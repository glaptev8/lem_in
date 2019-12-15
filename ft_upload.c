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
		a = ft_atoi(lem_in->arr_links[i][0]);
		b = ft_atoi(lem_in->arr_links[i][1]);
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
	lst->x = -1;
	return (lst);
}

t_way *lst_new(int len)
{
	t_way *lst;
	t_way *tmp;
	
	if (len == 0)
	{
		lst = lst_create();
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
	while (head)
	{
		q->x = head->x;
		q->y = head->y;
		q->next = lst_create();
		q->next->prev = q;
		q = q->next;
		q->head = q->prev->head;
		if (head->prev)
			head = head->next;
		else
			break;
	}
//	q->head->count = head->head->count;
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
				l--;
			}
			j++;
		}
		i++;
	}
	return (disjoint_ways);
}

int		visited(int y, t_way *way)
{
	if (!way->head)
		return (0);
	way = way->head;
	while (way)
	{
		if (way->x == y)
			return (1);
		if (!way->next)
			return (0);
		if (way->next)
			way = way->next;
		else
			break;
	}
	return (0);
}

int		is_way(int x, int y, t_not_ways	**way)
{
	int i;

	i = 0;
	while (way[i] && way[i]->x >= 0)
	{
		if (way[i]->x == x && way[i]->y == y)
			return (0);
		i++;
	}
	return (1);
}

void	ft_print_no_ways(t_not_ways **ways)
{
	int i;
	i = 0;
	while(ways[i] && ways[i]->x >= 0)
	{
		ft_printf("%d   %d\n", ways[i]->x, ways[i]->y);
		i++;
	}
}

void	init_not_ways(t_not_ways **no_ways)
{
	int i = 0;

	while (i < 999)
	{
		no_ways[i] = (t_not_ways *)malloc(sizeof(t_not_ways) * 1);
		no_ways[i]->x = -2;
		i++;
	}
}

int not_ways(int x, t_not_ways **no_ways, t_str *lem, int prev)
{
	int i;

	i = 0;
	while (i < lem->room_count)
	{
		if (lem->tab[x][i] == 1)
		{
			if (is_way(x, i, no_ways) && prev != i)
				return (0);
			i++;
			continue;
		}
		i++;
	}
	return (1);
}

void	clear_way(int x, t_not_ways **no_ways, int *n)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < 499)
	{
		if (no_ways[i]->x == x)
		{
			j = i;
			while (j < 498)
			{
				no_ways[j]->x = no_ways[j + 1]->x;
				no_ways[j]->y = no_ways[j + 1]->y;
				j++;
			}
			(*n)--;
			continue;
		}
//		if(no_ways[i + 1] && no_ways[i + 1]->x == no_ways[i]->x && no_ways[i + 1]->y == no_ways[i]->y)
//		{
//			no_ways[i] = NULL;
//			no_ways[i] = no_ways[i + 1];
//		}
		i++;
	}
//	no_ways[i]->x = -2;
}

void	set_way(t_str *lem_in, t_way **way)
{
	int x;
	int y;
	t_not_ways **no_ways;
	int q;
	int k = 0;
	q = 0;
	int n = 0;
	t_way *tmp;
	no_ways = (t_not_ways **)malloc(sizeof(t_not_ways *) * 500);
	int i;
	i = 0;
	init_not_ways(no_ways);
	y = 0;
	x = ft_atoi(lem_in->start);
	while (1)
	{
		while (x != ft_atoi(lem_in->end))
		{
			if (!way[q])
			{
				way[q] = lst_create();
				way[q]->this = way[q];
				way[q]->head = way[q];
			}
			if (lem_in->tab[x][ft_atoi(lem_in->end)] == 1)
			{
				y = ft_atoi(lem_in->end);
				if (!is_way(x, y, no_ways))
					y = lem_in->room_count + 1;
			}
			while (lem_in->tab[x][y] != 1 && y < lem_in->room_count)
				y++;
			if ((y == x || visited(y, way[q]) || !is_way(x, y, no_ways)) && y < lem_in->room_count)
			{
				y++;
				continue;
			}
			if (lem_in->tab[x][y] == 1 && y < lem_in->room_count)
			{
				if (!way[q]->next)
				{
					way[q]->next = lst_create();
					way[q]->next->prev = way[q];
					way[q]->next->this = way[q]->next;
					way[q]->next->head = way[q]->head;
					way[q] = way[q]->next;
				}
				if (way[q]->next)
					way[q] = way[q]->next;
				way[q]->x = x;
				way[q]->y = y;
				way[q]->next = lst_create();
				way[q]->next->prev = way[q];
				way[q]->next->this = way[q]->next;
				way[q]->next->head = way[q]->head;
				if (y == ft_atoi(lem_in->end))
				{
					free(way[q]->next);
					way[q]->next = NULL;
				}
				y = 0;
			}
			if (not_ways(ft_atoi(lem_in->start), no_ways, lem_in, -5))
				break;
			if (y >= lem_in->room_count)
			{
//				ft_print_no_ways(no_ways);
//				printf("-------------\n");
				no_ways[n]->x = way[q]->x;
				no_ways[n]->y = way[q]->y;
				n++;
				if (way[q]->prev)
				{
					way[q] = way[q]->prev;
					free(way[q]->next);
					way[q]->next = NULL;
				}
				if (!way[q] || way[q]->x < 0)
				{
					free(way[q]);
					way[q] = NULL;
				}
				y = 0;
				if (way[q])
					x = way[q]->y;
				else
					x = ft_atoi(lem_in->start);
//				ft_print_no_ways(no_ways);
//				printf("-------------\n");
				if (y != ft_atoi(lem_in->start))
				{
					clear_way(no_ways[n - 1]->y, no_ways, &n);
				}
//				ft_print_no_ways(no_ways);
//				printf("-------------\n");
				continue;
			}
			x = way[q]->y;
			if (not_ways(ft_atoi(lem_in->start), no_ways, lem_in, 5))
				break;
		}
		i = 0;
//		while (i < 41)
//		{
//			if (way[i] && way[i]->head)
//			{
//				tmp = copy_way(way[i]);
//				tmp = tmp->prev;
//				free(tmp->next);
//				tmp->next = NULL;
//				tmp = tmp->head;
//				while (tmp)
//				{
//					printf("%d ->  %d\n", tmp->x, tmp->y);
//					tmp = tmp->next;
//				}
//				printf("\n");
//			}
//			i++;
//		}
		if (not_ways(ft_atoi(lem_in->start), no_ways, lem_in, -5))
			break;
		no_ways[n]->x = way[q]->x;
		no_ways[n]->y = way[q]->y;
		n++;
		if (not_ways(ft_atoi(lem_in->start), no_ways, lem_in, -5))
			break;
//		ft_print_no_ways(no_ways);
//		printf("-------------\n");
		if (no_ways[n - 1]->x != ft_atoi(lem_in->start) && not_ways(no_ways[n - 1]->x, no_ways, lem_in, way[q]->prev->x))
		{
			no_ways[n]->x = way[q]->prev->x;
			no_ways[n]->y = way[q]->prev->y;
			n++;
			clear_way(no_ways[n - 1]->x, no_ways, &n);
		}
		else
		{
			no_ways[n]->x = way[q]->prev->x;
			no_ways[n]->y = way[q]->prev->y;
			n++;
			clear_way(no_ways[n - 2]->x, no_ways, &n);
		}
//		ft_print_no_ways(no_ways);
//		printf("-------------\n");
		if (not_ways(ft_atoi(lem_in->start), no_ways, lem_in, -5))
			break;
		x = ft_atoi(lem_in->start);
		q++;
		k++;
	}
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
	way = (t_way **)malloc(sizeof(t_way) * 1000);
	set_way(&lem_in, way);
//	init_way(&lem_in, way);
//	disjoint_way = disjoint_ways(way, &lem_in);
	int i;
	int j;
	i = 0;
//	while (disjoint_way[i])
//	{
//		j = 0;
//		while (disjoint_way[i][j])
//		{
//			disjoint_way[i][j] = disjoint_way[i][j]->head;
//			while (disjoint_way[i][j]->next)
//			{
//				ft_printf("%d  ->   %d   kol: %d\n", disjoint_way[i][j]->x, disjoint_way[i][j]->y, disjoint_way[i][j]->head->count);
//				disjoint_way[i][j] = disjoint_way[i][j]->next;
//			}
//			j++;
//			printf("\n");
//		}
//		printf("----------------------\n");
//		i++;
//	}
//printf("\n\n\n");
//	while (i < 200)
//	{
//		if (way[i])
//		{
//			way[i] = way[i]->head;
//			while (way[i])
//			{
//				printf("%d ->  %d\n", way[i]->x, way[i]->y);
//				if (way[i]->next)
//					way[i] = way[i]->next;
//				else
//					break;
//			}
//			printf("\n");
//			count++;
//		}
//		i++;
//	}
//	printf("%d\n", count);
//	printf("lem.start = %s lem.end = %s\n", lem_in.arr_links[0][0], lem_in.arr_links[0][1]);
//	printf("lem.start = %s lem.end = %s\n", lem_in.arr_links[1][0], lem_in.arr_links[1][1]);
//	printf("lem.start = %s lem.end = %s\n", lem_in.arr_links[2][0], lem_in.arr_links[2][1]);
//	printf("lem.start = %s lem.end = %s\n", lem_in.arr_links[3][0], lem_in.arr_links[3][1]);
//	printf("lem.start = %s lem.end = %s\n", lem_in.arr_links[4][0], lem_in.arr_links[4][1]);
}

