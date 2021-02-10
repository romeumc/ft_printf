/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 20:55:17 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/10 16:55:33 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libftprintf.h"
#include <stdio.h>

int	main(void)
{
	char	romeu[]="romeu carvalho";
	size_t	temp;
	int		size;

	temp = ft_strlen(romeu);
	printf("len:%ld\n", temp);
	printf("abc" "def\n");
	
	// size = ft_printf("testes%sdddds%s%d%esc" "romeu." "teste", "abc", "def", "hij", 12, "   ", 't');
	// printf(ANSI_B_BMAGENTA "\tsize:%d\n" ANSI_RESET, size);

	// size = ft_printf("%%");
	// printf(ANSI_B_BMAGENTA "\tsize:%d\n" ANSI_RESET, size);
	
	size = ft_printf("testes %s d%% ddds %s %s%d %s c.romeu  %c teste", "abc", "def", "hij", 12, "   ", 't');
	printf(ANSI_B_BMAGENTA "\tsize:%d\n" ANSI_RESET, size);

}
