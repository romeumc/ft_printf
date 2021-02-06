# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/05 12:40:25 by rmartins          #+#    #+#              #
#    Updated: 2021/02/06 03:26:27 by rmartins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = include/libftprintf.h
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
OBJ_DIR = obj/
OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)

SRC = ft_printf.c teste.c

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(ANSI_B_BGREEN) "compile libft" $(ANSI_RESET)$(ANSI_F_BBLACK)
	$(MAKE) all -C libft
	cp libft/libft.a $(NAME)
	@echo $(ANSI_RESET) ""
	@echo $(ANSI_B_BGREEN) "create library" $(ANSI_RESET)$(ANSI_F_BBLACK)
	$(AR) $(NAME) $(OBJ)
	@echo $(ANSI_RESET) ""

$(OBJ_DIR)%.o: %.c
	@echo $(ANSI_B_BGREEN) "compile ft_printf objects" $(ANSI_RESET)$(ANSI_F_BBLACK)
	gcc $(CFLAGS) -include $(HEADER) -c $< -o $@
	@echo $(ANSI_RESET)

$(OBJ): | $(OBJ_DIR)
$(OBJ_DIR):
	@echo $(ANSI_B_BGREEN) "create obj folder if needed" $(ANSI_RESET)$(ANSI_F_BBLACK)
	mkdir $@
	@echo $(ANSI_RESET) ""

clean:
	@echo $(ANSI_B_RED) "clean" $(ANSI_RESET)$(ANSI_F_BRED)
	$(MAKE) clean -C libft
	rm -rf $(OBJ_DIR)
	@echo $(ANSI_RESET) ""

fclean: clean
	@echo $(ANSI_B_RED) "fclean" $(ANSI_RESET)$(ANSI_F_BRED)
	$(MAKE) fclean -C libft
	rm -f $(NAME)
	@echo $(ANSI_RESET) ""

re: fclean all
	
.PHONY: all clean fclean




norm:
	@echo $(ANSI_B_RED) "norminette *.c" $(ANSI_RESET)
	norminette -R CheckForbiddenSourceHeader $(SRC)
	@echo $(ANSI_B_RED) "norminette *.h" $(ANSI_RESET)
	norminette $(HEADER)
run: all
	@echo $(ANSI_B_RED) "Running with sanitize" $(ANSI_RESET)
	@gcc $(CFLAGS) -fsanitize=address main.c $(NAME) && ./a.out | cat -e

# colors
ANSI_RESET = "\033[0m"
ANSI_B_RED = "\033[41m"
ANSI_B_BGREEN = "\033[42;1m"
ANSI_F_BRED = "\033[31;1m"
ANSI_F_BBLACK = "\033[30;1m"