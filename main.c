/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 20:55:17 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/18 15:02:08 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include <stdio.h>

#define TESTc4 "%10c", '0'
#define TESTc8 "%*c", 2, '0'
#define TESTc11 "%*c", -5, '0'

#define TESTs9 " %-10s %10s ", "123", "4567"
#define TESTs16 " %*.s %.1s ", 10, "123", "4567"
#define TESTs17 " %*.0s %.2s ", 10, "123", "4567"
#define TESTs18 " %*.3s %.3s ", 10, "123", "4567"
#define TESTs19 " %*.4s %.4s ", 10, "123", "4567"
#define TESTs20 " %*.5s %.5s ", 10, "123", "4567"
#define TESTs21 " %*.5s %*.5s ", 10, "123", 10, "4567"
#define TESTs22 " %*.5s %*.5s ", -10, "123", 10, "4567"
#define TESTs23 " %*.5s %*.5s ", 10, "123", -10, "4567"
#define TESTs24 " %*.5s %*.5s ", -10, "123", -10, "4567"
#define TESTs25 " %10.s %1.s ", "123", "4567"
#define TESTs26 " %0.s %0.s ", "123", "4567"
#define TESTs27 " %.s %.s ", "123", "4567"
#define TESTs28 " %3.3s %3.3s ", "123", "4567"
#define TESTs29 " %4.3s %-4.3s ", "123", "4567"
#define TESTs30 "%.s", ""
#define TESTs31 "%.0s", ""
#define TESTs32 "%.1s", ""
#define TESTs33 " %4.2s %-4.2s ", "123", "4567"

#define TESTs42 "%4.2s", "hello"
#define TESTs50 "%7.5s", "yolo"
#define TESTs73 "hello, %s.", NULL


int	main(void)
{
	int		size;

	// printf(ANSI_F_GREEN);
	// size = printf(TESTs42);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTs42);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTs73);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTs73);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	printf(ANSI_F_GREEN);
	size = printf(TESTs50);
	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	size = ft_printf(TESTs50);
	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTs19);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTs19);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTs20);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTs20);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTs21);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTs21);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTs22);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTs22);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTs23);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTs23);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTs24);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTs24);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTs25);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTs25);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTs27);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTs27);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTs28);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTs28);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTs29);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTs29);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTs30);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTs30);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTs31);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTs31);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTs32);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTs32);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTs33);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTs33);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);


	// size = ft_printf("testes%sdddds%s%d%esc" "romeu." "teste", "abc", "def", "hij", 12, "   ", 't');
	// printf(ANSI_B_BMAGENTA "\tsize:%d\n" ANSI_RESET, size);

	// size = ft_printf("%%");
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// size = ft_printf("testes %s rjjdjd", "abc");
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN "[%*c]" ANSI_RESET "\n", 1, '0');
	// size = ft_printf("[%*c]", 1, '0');
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN "[%-10c]" ANSI_RESET "\n", '0');
	// size = ft_printf("[%-10c]", '0');
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	
	// size = ft_printf("testes %s d%% ddds %s %s%d %s c.romeu  %c teste", "abc", "def", "hij", 123, "   ", 't');
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// size = ft_printf("%-5%");
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// size = ft_printf("testes %5s d%% ddds %s %s%d %s c.romeu  %c teste", "abc", "def", "hij", 123, "   ", 't');
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// size = ft_printf("hello, %s.", NULL);
	// printf(ANSI_B_BMAGENTA "size:%d\n" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTs16);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTs16);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTs17);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTs17);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	

	// printf(ANSI_F_GREEN);
	// size = printf(TESTs18);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTs18);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	

	// printf(ANSI_F_GREEN);
	// size = printf(TESTs26);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTs26);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);




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
