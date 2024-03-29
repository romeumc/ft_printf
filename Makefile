# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/05 12:40:25 by rmartins          #+#    #+#              #
#    Updated: 2021/03/09 18:59:52 by rmartins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = include/ft_printf.h
CFLAGS = -Wall -Wextra -Werror
CFLAGSERROR = -Wall -Wextra
AR = ar rcsv
OBJ_DIR = obj
SRC_DIR = src
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

SRC = ft_printf.c \
		parse_fmt.c \
		make_conversion.c \
		make_conversion_s.c \
		make_conversion_d.c \
		make_conversion_x.c \
		make_conversion_n.c \
		make_conversion_u.c \
		make_conversion_f.c \
		make_conversion_e.c \
		subconversion_hh.c \
		treat_conversion_string_decimal.c \
		treat_conversion_string_zero.c \
		treat_conversion_float.c \
		treat_width_precision.c \
		print_output.c \
		treat_flags.c \
		precheck_flags.c

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(ANSI_B_BGREEN) "compile libft" $(ANSI_RESET)$(ANSI_F_BBLACK)
	$(MAKE) all -C libft
	cp libft/libft.a $(NAME)
	@echo $(ANSI_RESET) ""
	@echo $(ANSI_B_BGREEN) "create library" $(ANSI_RESET)$(ANSI_F_BBLACK)
	$(AR) $(NAME) $^
	@echo $(ANSI_RESET) ""

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo $(ANSI_B_BGREEN) "compile ft_printf objects" $(ANSI_RESET)$(ANSI_F_BBLACK)
	gcc $(CFLAGS) -g -include $(HEADER) -c $< -o $@
	@echo $(ANSI_RESET)

$(OBJ): | $(OBJ_DIR)
$(OBJ_DIR):
	@echo $(ANSI_B_BGREEN) "create obj folder if needed" $(ANSI_RESET)$(ANSI_F_BBLACK)
	mkdir -p $@
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

bonus: all
	
.PHONY: all clean fclean

# colors
ANSI_RESET = "\033[0m"
ANSI_B_RED = "\033[41m"
ANSI_B_BGREEN = "\033[42;1m"
ANSI_F_BRED = "\033[31;1m"
ANSI_F_BBLACK = "\033[30;1m"