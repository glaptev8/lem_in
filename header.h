/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:12:37 by rmarni            #+#    #+#             */
/*   Updated: 2019/12/10 16:31:04 by rmarni           ###   ########.fr       */
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

typedef struct s_str
{
	int		q_lem;

	char	*start;
	char	*end;
	char	**arr_room[INT16_MAX];
	char	**arr_links[INT16_MAX];
	int		room_count;
	int 	link_count;
	char	*buf;
	char 	**tab_comp;
	int 	fd;
//	int 	**clone_arr_room[INT16_MAX];
	int 	clone_arr_links[INT16_MAX][2];
}	t_str;

//t_str lem_in;

int				ft_atoi(const char *src);
int				ft_printf(const char *format, ...);
int				get_next_line(const int fd, char **line);
void 			ft_exit(t_str *lem_in, int flag);
int				ft_isprint(int c);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strdup(const char *src);
void			ft_start_end(char *str, t_str *lem_in);
char			**ft_strsplit(char const *s, char c);
void			check_room(t_str *lem_in);
int				ft_isdigit(int c);
void			ft_tab_comp(t_str *lem_in);

#endif
