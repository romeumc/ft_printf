# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/05 12:40:25 by rmartins          #+#    #+#              #
#    Updated: 2021/02/22 22:21:04 by rmartins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = include/ft_printf.h
CFLAGS = -Wall -Wextra -Werror
CFLAGSERROR = -Wall -Wextra
AR = ar rcs
OBJ_DIR = obj
SRC_DIR = src
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

SRC = ft_printf.c \
		parse_fmt.c \
		make_conversion.c

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(ANSI_B_BGREEN) "compile libft" $(ANSI_RESET)$(ANSI_F_BBLACK)
	$(MAKE) all -C libft
	cp libft/libft.a $(NAME)
	@echo $(ANSI_RESET) ""
	@echo $(ANSI_B_BGREEN) "create library" $(ANSI_RESET)$(ANSI_F_BBLACK)
	$(AR) $(NAME) $(OBJ)
	@echo $(ANSI_RESET) ""

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo $(ANSI_B_BGREEN) "compile ft_printf objects" $(ANSI_RESET)$(ANSI_F_BBLACK)
	gcc $(CFLAGS) -include $(HEADER) -c $< -o $@
	@echo $(ANSI_RESET)

$(OBJ): | $(OBJ_DIR)
$(OBJ_DIR):
	@echo $(ANSI_B_BGREEN) "create obj folder if needed" $(ANSI_RESET)$(ANSI_F_BBLACK)
	mkdir -p $@
	#mkdir -p $(OBJ_DIR)/src
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
	@echo $(ANSI_B_RED) "norminette v3" $(ANSI_RESET)
	@norminette $(HEADER) $(addprefix src/,$(SRC))

norm2:
	@echo $(ANSI_B_RED) "norminette v2" $(ANSI_RESET)
	@norminette2 $(HEADER) $(addprefix src/,$(SRC))

libnorm:
	@echo $(ANSI_B_RED) "libft norminette" $(ANSI_RESET)
	$(MAKE) norm -C libft

libnorm2:
	@echo $(ANSI_B_RED) "libft norminette v2" $(ANSI_RESET)
	$(MAKE) norm2 -C libft

run: all
	@echo $(ANSI_B_RED) "Running for debbuger without sanitize" $(ANSI_RESET)
	@gcc $(CFLAGS) -g3 main.c $(NAME) && ./a.out

runv: all runs run
	@echo $(ANSI_B_RED) "Valgrind RESULT" $(ANSI_RESET)
	valgrind -q --leak-check=full --track-origins=yes --show-leak-kinds=all ./a.out

runs: all
	@echo $(ANSI_B_RED) "Running with sanitize" $(ANSI_RESET)
	@gcc $(CFLAGS) -g3 -fsanitize=address main.c $(NAME) && ./a.out && rm a.out

rune: all
	@echo $(ANSI_B_RED) "Running without flag ERROR" $(ANSI_RESET)
	@gcc $(CFLAGSERROR) -g3 -fsanitize=address main.c $(NAME) && ./a.out && rm a.out


# colors
ANSI_RESET = "\033[0m"
ANSI_B_RED = "\033[41m"
ANSI_B_BGREEN = "\033[42;1m"
ANSI_F_BRED = "\033[31;1m"
ANSI_F_BBLACK = "\033[30;1m"