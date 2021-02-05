# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/05 12:40:25 by rmartins          #+#    #+#              #
#    Updated: 2021/02/05 15:44:45 by rmartins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprint.a
HEADER = libftprintf.h
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
OBJ_DIR = obj/
OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)

SRC = teste.c #ft_printf.c

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) bonus -C libft
	cp libft/libft.a .
	$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

$(OBJ): | $(OBJ_DIR)
$(OBJ_DIR):
	mkdir -v $@

clean:
	$(MAKE) clean -C libft
	rm -rfv $(OBJ_DIR)

fclean:
	$(MAKE) fclean -C libft
	rm -fv $(NAME)

.PHONY: all clean fclean