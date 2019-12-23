# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/29 09:12:50 by rmarni            #+#    #+#              #
#    Updated: 2019/12/23 16:13:54 by rmarni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	lem-in

#						*****	OBJECT FILES	******
SRC 	=	alg_bfs.o       \
            binary_search.o \
            check_bfr_alg.o \
            ft_exit.o       \
            ft_upload.o     \
            lem_alg.o       \
            main.o          \
            sort_char.o

SRCDIR	= 	$(addprefix ./, $(SRC))
LIBDIR	=	./libft/

#						*****	COLLORS			*****
GREEN 		=	\033[0;32m
RED 		=	\033[0;31m 
YELLOW		=	\033[0;33m 
RESET 		= 	\033[0m


CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
				@echo "$(GREEN)Lem_in:$(RESET) [Compilation:$(YELLOW) $@$(RESET)]"
				@$(CC) -o $@ -c $< #$(CFLAGS)

$(NAME): lib $(SRCDIR)
				@echo "$(NAME): creating Lem_in...$(GREEN) OK!$(RESET)"
				@$(CC) $(CFLAGS) $(SRCDIR) -o $(NAME) -L $(LIBDIR) -lft

lib:
				@echo "$(NAME): creating LIBFT...$(GREEN)OK!$(RESET)"
				@make -C $(LIBDIR)

clean:
				@make -C libft/ clean
				@rm -rf $(SRCDIR)

fclean:
				@echo "$(NAME): delete all files...$(GREEN) OK!$(RESET)"
				@make -C libft/ fclean
				@make clean
				@rm -rf ./lem-in

re: fclean all

.PHONY: re clean fclean all lib
