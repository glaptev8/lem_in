NAME =		libftprintf.a
LIBFT_A =	libft.a

COMP =		gcc -Wall -Wextra -Werror $(PRINTF_H) $(LIBFT_H) -c -o

PRINTF_H =	-I includes/
LIBFT_H = 	-I ../libft/

OBJ_DIR =	obj/
SRC_DIR =	src/
LIB_DIR =	../libft/

CFILE = display_procent.c \
		display_c.c \
		display_d.c \
		display_f.c \
		display_i.c \
		display_o.c \
		display_p.c \
		display_s.c \
		display_u.c \
		display_x.c \
		display_xx.c \
		ft_printf.c \
		functions_for_add_flags.c \
		functions_for_add_flags2.c \
		functions_for_add_flags3.c \
		init_struct.c \
		is_conversion.c \
		ft_putnbrmax.c \
		ft_numberlen.c \
		init_displays.c \
		displays_for_d.c \
		converter.c \
		displays_for_u.c \
		displays_for_o.c \
		displays_for_space.c \
		ft_ftoa.c \
		ft_itoa_lu.c \
		ft_l_ftoa.c

CFIND =		$(CFILE:%=$(SRC_DIR)%)

OFILE =		$(CFILE:%.c=%.o)

OBJ =		$(addprefix $(OBJ_DIR), $(OFILE))

all: $(NAME)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJ)
		@make -C $(LIB_DIR)
		@cp $(LIB_DIR)$(LIBFT_A) .
		@mv $(LIBFT_A) $(NAME)
		@ar rc $(NAME) $(addprefix $(OBJ_DIR), $(OFILE))
		@ranlib $(NAME)

$(OBJ): $(CFIND)
		@$(MAKE) $(OFILE)

$(OFILE):
		@echo Create: $(@:obj/%=%)
		@$(COMP) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)

clean:
		@/bin/rm -rf $(OBJ_DIR)
		@make -C $(LIB_DIR) clean

fclean: clean
		@/bin/rm -f $(NAME)
		@make -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean flcean re