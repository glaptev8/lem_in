# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MakeFile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmelia <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/05 14:32:32 by tmelia            #+#    #+#              #
#    Updated: 2019/09/17 15:11:55 by tmelia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = ft_is_upper.c ft_isdigit.c ft_lstadd.c ft_lstmap.c \
         ft_memchr.c ft_memmove.c ft_putchar_fd.c ft_putnbr_fd.c \
         ft_strchr.c ft_strdel.c ft_striteri.c ft_strmap.c \
         ft_strncpy.c ft_strrchr.c ft_strtrim.c ft_toupper.c \
         ft_isalnum.c ft_isprint.c ft_lstdel.c ft_lstnew.c \
         ft_memcmp.c ft_memset.c ft_putendl.c ft_putstr.c \
         ft_strclr.c ft_strdup.c ft_strjoin.c ft_strmapi.c \
         ft_strnequ.c ft_strsplit.c ft_struct_len.c \
         ft_atoi.c  ft_isalpha.c ft_itoa.c ft_lstdelone.c \
         ft_memalloc.c ft_memcpy.c ft_push_back.c ft_putendl_fd.c \
         ft_putstr_fd.c ft_strcmp.c ft_strequ.c ft_strlcat.c \
         ft_strncat.c ft_strnew.c ft_strstr.c ft_swap.c \
         ft_bzero.c ft_isascii.c ft_list_last.c ft_lstiter.c \
         ft_memccpy.c ft_memdel.c ft_putchar.c ft_putnbr.c \
         ft_strcat.c ft_strcpy.c ft_striter.c ft_strlen.c \
         ft_strncmp.c ft_strnstr.c ft_strsub.c ft_tolower.c \
         ft_strequally.c get_next_line.c

NAME_O =		$(NAME_C:.c=.o)

CFIND =		$(NAME_C:%=%)

NAME = libft.a

OBJ = NAME_O

all: $(NAME)

$(NAME): $(NAME_O)
	@ar rc $(NAME) $(NAME_O)
	@echo ranlib $(NAME)

$(NAME_O): $(NAME_C)
		@gcc -Wall -Wextra -Werror -I libft.h -c $(@:%.o=%.c)

clean:
	@/bin/rm -f $(NAME_O)

fclean: clean
	@rm -f $(NAME)

re: fclean all clean
