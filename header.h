/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:12:37 by rmarni            #+#    #+#             */
/*   Updated: 2019/12/16 16:20:50 by rmarni           ###   ########.fr       */
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

typedef struct s_way
{
	int		way[400];
	int 	size_way;
}				t_way;

typedef struct s_room
{
	char	lvl;
	char	visit;
	char	*arr_room[1];
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

	int 	link_count;
	char	*buf;
	int 	fd;
}	t_str;

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
int 			ft_binary_search(t_room *rooms, int num, int mid, char *str);
void			ft_zero_struck(t_room *rooms, int arr_size);


#endif
