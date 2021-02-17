/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 20:55:17 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/17 19:39:11 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	// char	romeu[]="romeu carvalho";
	// size_t	temp;
	int		size;

	// temp = ft_strlen(romeu);
	// printf("len:%ld\n", temp);
	// printf("abc" "def\n");
	
	// size = ft_printf("testes%sdddds%s%d%esc" "romeu." "teste", "abc", "def", "hij", 12, "   ", 't');
	// printf(ANSI_B_BMAGENTA "\tsize:%d\n" ANSI_RESET, size);

	// size = ft_printf("%%");
	// printf(ANSI_B_BMAGENTA "\tsize:%d\n" ANSI_RESET, size);
	


	// size = ft_printf("testes %s rjjdjd", "abc");
	// printf(ANSI_B_BMAGENTA "|size:%d" ANSI_RESET, size);
	// printf("\n" ANSI_RESET);

	// size = ft_printf("%3c", '0');
	// printf(ANSI_B_BMAGENTA "|size:%d" ANSI_RESET, size);
	// printf("\n" ANSI_RESET);
	
	size = ft_printf("testes %s d%% ddds %s %s%d %s c.romeu  %c teste", "abc", "def", "hij", 123, "   ", 't');
	printf(ANSI_B_BMAGENTA "|size:%d" ANSI_RESET, size);
	printf("\n" ANSI_RESET);

	size = ft_printf("testes %5s d%% ddds %s %s%d %s c.romeu  %c teste", "abc", "def", "hij", 123, "   ", 't');
	printf(ANSI_B_BMAGENTA "|size:%d" ANSI_RESET, size);
	printf("\n" ANSI_RESET);

	// size = ft_printf("hello, %s.", NULL);
	// printf(ANSI_B_BMAGENTA "size:%d\n" ANSI_RESET, size);

}


// int width = 4;
// 	int num = 223;
// 	double simples = 111;
// 	double composto = 123.10; 
// 	double composto1 = 123.1238; 
// 	char romeu[] = "romeu";

// 	printf("decimal with * - %*d\n", width, num);
// 	printf("string and xX with # - %s %-s %x %#x %X %#X\n", romeu, romeu, *romeu, *romeu, *romeu, *romeu);
// 	printf("float - %'.2f\n", 1234567.89);
// 	printf("float - %'2f\n", 1234567.89);
// 	printf("char - %c\n", '7');
// 	printf("simples g - %g %#g | %0g | %-g\n", simples, simples, simples, simples);
// 	printf("composto g - %g %#g | %0g \n", composto, composto, composto);
// 	printf("composto1 g - %g %#g\n", composto1, composto1);
// 	printf("simples e - %e %#e\n", simples, simples);
// 	printf("composto e - %e %#e\n", composto, composto);
// 	printf("composto1 e - %e %#e\n", composto1, composto1);
