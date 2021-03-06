/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:12:37 by rmarni            #+#    #+#             */
/*   Updated: 2019/12/19 13:21:35 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HEADER_H
# define _HEADER_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>
# include <stdlib.h>
# include <fcntl.h>

# define BLACK(string)			"\x1b[30m" string "\x1b[0m"
# define RED(string)			"\x1b[31m" string "\x1b[0m"
# define GREEN(string)			"\x1b[32m" string "\x1b[0m"
# define YELLOW(string)			"\x1b[33m" string "\x1b[0m"
# define BLUE(string)			"\x1b[34m" string "\x1b[0m"
# define MAGENTA(string)		"\x1b[35m" string "\x1b[0m"
# define CYAN(string)			"\x1b[36m" string "\x1b[0m"
# define GREY(string)			"\x1b[37m" string "\x1b[0m"
# define RESET(string)			"\x1b[0m" string "\x1b[0m"

typedef struct s_pr_way
{
	int num;
	int q_elem;
	int turn;
} 				t_pr_way;

typedef struct s_ant
{
	int		num_ant;
	int 	turn;
	int 	way;
	int 	position;
	int 	finish;
}			t_ant;

typedef struct s_room
{
	int		lvl;
	int		visit;
	char	*arr_room;
	int		arr_link[40];
	int 	size_link_arr;
}	t_room;

typedef struct s_str
{
	int		q_lem;
	int		room_count;
	char	*buf_start;
	char	*buf_end;
	int 	start;
	int 	end;
	int		count_ways;
	int		len_ways[100];
	int 	link_count;
	char	*buf;
	int 	fd;
	int		j;
	int		q;
	int		copy_end_link_count;
}	t_str;

typedef struct 	s_stack
{
	int		x;
	struct s_stack		*next;
	struct s_stack		*head;
}				t_stack;

typedef struct s_way
{
	int		x;
	int		y;
	struct	s_way *next;
	struct	s_way *prev;
	struct	s_way *head;
}				t_way;

//t_str lem_in;

int				ft_atoi(const char *src);
int				ft_printf(const char *format, ...);
int				get_next_line(const int fd, char **line);
void 			ft_exit(t_str *lem_in, t_room *rooms, int flag);
int				ft_isprint(int c);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strdup(const char *src);
void			ft_start_end(char *str, t_str *lem_in, t_room *rooms);
char			**ft_strsplit(char const *s, char c);
void			check_room(t_str *lem_in);
int				ft_isdigit(int c);
void			ft_tab_comp(t_str *lem_in);
char			*ft_strdup(const char *src);
t_room 			*ft_sort_struct(t_room *room, int arr_size);
void 			ft_slash_zero(t_room *rooms, int i, char c);
t_room 			*ft_sort_link(t_room *room, int arr_size);
void 			ft_bfs_alg(t_str *lem_in, t_room *rooms);
int 			ft_binary_search(t_room *rooms, int start, int end, char *str);
void			ft_zero_struck(t_room *rooms, int arr_size);
int 			**get_ways(t_str *lem, t_room *rooms);
void 			ft_lem_alg(t_str *lem_in, t_way **way, t_room *rooms);
void			set_levels(t_room *rooms, int visit, t_str *lem);
void			*clear_and_fresh(int mas[3], t_stack **tmp,
							 t_stack *stack, t_room *rooms);
t_stack			*set_one_level(t_stack *tmp, t_stack *stack,
							  int mas[3], t_room *rooms);
t_stack			*copy_stack(t_stack *stack);
void			clear_stack(t_stack *stack);
t_stack			*lst_create(t_stack *stack, int number);
int				get_min_level(t_room *room,
							 int pos, int visit);
int				get_level_not_visited(t_room *room, int visit, int pos);
int				has_ways_from_start(t_room *rooms, int start, int visited);
int				get_next_room(t_room *room, int number_room, int visited);
int				q_less(int *q, t_room *rooms, t_str *lem, int mas[2]);
int				init_value_count_ways(int mas[2], int *q, int *count, t_str *lem);
int				set_count_rows(t_room *rooms, int visit, t_str *lem);
int				get_count_rows(t_room *rooms, int visit, t_str *lem);
int				if_has_road_to_end_from_start(t_room *rooms,
											 t_str *lem, int visit, int **qq);
int				if_has_way(t_room *rooms, int visit, t_str *lem, int **qq);
int				one_step_back_is_end(int qq, int end, int *i);
void			else_push_row(int *i, t_str *lem, int **qq);
void			push_row(int **qq, t_room *rooms, t_str *lem, int *i);
int				**set_ways(t_room *rooms, int visit, t_str *lem);
#endif
