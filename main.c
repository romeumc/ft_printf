/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 20:55:17 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/22 03:37:59 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include <stdio.h>
#include <limits.h>




#define TESTc4 "%10c", '0'
#define TESTc8 "%*c", 2, '0'
#define TESTc11 "%*c", -5, '0'

/* ***** Test s ****************** */
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
#define TESTsRomeu1 "%.*s", -3, NULL

/* ***** Test p ****************** */
#define TESTp1 " %p ", -1
#define TESTp2 " %p ", 1
#define TESTp3 " %p ", 15
#define TESTp4 " %p ", 16
#define TESTp5 " %p ", 17
#define TESTp6 " %10p %10p ", 1, -1
#define TESTp7 " %-10p %10p ", 1, -1
#define TESTp8 " %10p %-10p ", 1, -1
#define TESTp9 " %-10p %-10p ", 1, -1
#define TESTp10 " %10p %-10p ", 1, -1
#define TESTp11 " %p %p ", 1, -1
#define TESTp12 " %10p %-10p ", 0, 0
#define TESTp13 " %p %p ", LONG_MIN, LONG_MAX
#define TESTp14 " %p %p ", INT_MIN, INT_MAX
#define TESTp15 " %p %p ", ULONG_MAX, -ULONG_MAX
#define TESTp16 " %*p %-*p ", -10, 101, -10, 42
#define TESTp17 " .-0*%*p %-*p*0-. ", 11, 101, 11, 42

#define TESTpp7 "%5%"
#define TESTpp9 "%05%"
#define TESTpp10 "%-05%"
#define TESTp173 "%p", NULL
#define TESTp179 "%p%p%p%p%p%p%p%p%p%p%p%p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12
#define TESTp180 "%70p", &a01


/* ***** Test d ****************** */
#define TESTd1 " %d ", 0
#define TESTd2 " %.d ", 0
#define TESTd3 " %-.2d ", 0
#define TESTd4 " %-2.2d ", 0
#define TESTd5 " %-3.2d ", 0
#define TESTd6 " %-3.2d %10.42d ", 0, 0
#define TESTd7 " %-3.2d %10.42d ", 1, -1
#define TESTd8 " %-3.2d %10.42d ", 10, -10
#define TESTd9 " *%-*.*d* *%*.*d* ", 4, 5, 10, 10, 21, -10
#define TESTd10 " *%-*.*d* *%*.*d* ", 6, 2, 102, 10, 21, -101
#define TESTd11 " *%*.*d* *%*.*d* ", -6, 2, 102, 10, 21, 101
#define TESTd12 " 0*%0-*.*d*0 0*%0*.*d*0 ", 6, 2, 102, 10, 21, -101
#define TESTd13 " 0*%0-*.*d*0 0*%0*.*d*0 ", 2, 6, 102, 21, 10, -101
#define TESTd14 " 0*%0-*d*0 0*%0*d*0 ", 21, 1021, 21, -1011
/*
#define TESTd15 " 0*%-0*.10d*0 0*%-0*.0d*0 ", 21, 1021, 21, -1011
#define TESTd16 " --0*%0*.0d*0 0*%0*.10d*0-- ", -2, 0, 21, 1
#define TESTd17 " --0*%0*.0d*0 0*%0*.10d*0-- ", -21, INT_MAX, 21, INT_MIN
#define TESTd18 " --0*%0*.0d*0 0*%0*.10d*0-- ", -21, LONG_MAX, 21, LONG_MIN
#define TESTd19 " --0*%-0*.20d*0 0*%-0*.10d*0-- ", -21, CHAR_MAX, 21, CHAR_MIN
#define TESTd20 " --0*%-0*.2d*0 0*%-0*.2d*0-- ", -21, CHAR_MAX, 21, CHAR_MIN
#define TESTd21 " --0*%-0*.3d*0 0*%-0*.3d*0-- ", -21, CHAR_MAX, 21, CHAR_MIN
#define TESTd22 " --0*%-0*.4d*0 0*%-0*.4d*0-- ", -21, CHAR_MAX, 21, CHAR_MIN
#define TESTd23 "%9.2d", UINT_MAX
#define TESTd24 "%9.10d", UINT_MAX
#define TESTd25 "%10.0d", UINT_MAX
#define TESTd26 "%10.1d", UINT_MAX
#define TESTd27 "%10.2d", UINT_MAX
#define TESTd28 "%10.10d", UINT_MAX
#define TESTd29 "%11.0d", UINT_MAX
#define TESTd30 "%11.1d", UINT_MAX
#define TESTd31 "%11.2d", UINT_MAX
#define TESTd32 "%11.10d", UINT_MAX
#define TESTd33 "%-9.0d", UINT_MAX
#define TESTd34 "%-9.1d", UINT_MAX
#define TESTd35 "%-9.2d", UINT_MAX
#define TESTd36 "%-9.10d", UINT_MAX
#define TESTd37 "%-10.0d", UINT_MAX
#define TESTd38 "%-10.1d", UINT_MAX
#define TESTd39 "%-10.2d", UINT_MAX
#define TESTd40 "%-10.10d", UINT_MAX
#define TESTd41 "%-11.0d", UINT_MAX
#define TESTd42 "%-11.1d", UINT_MAX
#define TESTd43 "%-11.2d", UINT_MAX
#define TESTd44 "%-11.10d", UINT_MAX
#define TESTd45 "%09.0d", UINT_MAX
#define TESTd46 "%09.1d", UINT_MAX
#define TESTd47 "%09.2d", UINT_MAX
#define TESTd48 "%09.10d", UINT_MAX
#define TESTd49 "%010.0d", UINT_MAX
#define TESTd50 "%010.1d", UINT_MAX
#define TESTd51 "%010.2d", UINT_MAX
#define TESTd52 "%010.10d", UINT_MAX
#define TESTd53 "%011.0d", UINT_MAX
#define TESTd54 "%011.1d", UINT_MAX
#define TESTd55 "%011.2d", UINT_MAX
#define TESTd56 "%011.10d", UINT_MAX
#define TESTd57 "%09.0d", UINT_MAX + 1
#define TESTd58 "%09.1d", UINT_MAX + 1
#define TESTd59 "%09.2d", UINT_MAX + 1
#define TESTd60 "%09.10d", UINT_MAX + 1
#define TESTd61 "%010.0d", UINT_MAX + 1
#define TESTd62 "%010.1d", UINT_MAX + 1
#define TESTd63 "%010.2d", UINT_MAX + 1
#define TESTd64 "%010.10d", UINT_MAX + 1
#define TESTd65 "%011.0d", UINT_MAX + 1
#define TESTd66 "%011.1d", UINT_MAX + 1
#define TESTd67 "%011.2d", UINT_MAX + 1
#define TESTd68 "%011.10d", UINT_MAX + 1
#define TESTd69 "%.0d", 0
#define TESTd70 "%.0d", 5
#define TESTd71 "%.0d", 10
#define TESTd72 "%1.d", 0
#define TESTd73 "%2.d", 0
#define TESTd74 "%3.d", 0
#define TESTd75 "%1.1d", 0
#define TESTd76 "%1.2d", 0
#define TESTd77 "%1.3d", 0
#define TESTd78 "%1.1d", 0
#define TESTd79 "%2.2d", 0
#define TESTd80 "%3.3d", 0
*/

void	make_test_p()
{
	int size;
	static char	a01;
	static unsigned char a02;
	static short a03;
	static unsigned short a04;
	static int a05;
	static unsigned int a06;
	static long a07;
	static unsigned long a08;
	static long long a09;
	static unsigned long long a10;
	static char *a11;
	static void *a12;

	// printf(ANSI_F_GREEN);
	// size = printf(TESTp1);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTp1);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTp2);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTp2);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTp3);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTp3);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTp4);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTp4);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTp5);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTp5);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTp6);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTp6);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTp7);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTp7);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTp8);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTp8);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTp9);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTp9);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTp10);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTp10);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTp11);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTp11);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTp12);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTp12);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTp13);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTp13);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTp14);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTp14);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTp15);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTp15);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTp16);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTp16);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTpp7);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTpp7);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTpp9);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTpp9);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTpp10);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTpp10);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTp173);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTp173);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	printf(ANSI_F_GREEN);
	size = printf(TESTp179);
	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	size = ft_printf(TESTp179);
	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	printf(ANSI_F_GREEN);
	size = printf(TESTp180);
	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	size = ft_printf(TESTp180);
	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
}

void	make_test_d()
{
	int	size;

	// printf(ANSI_F_GREEN);
	// size = printf(TESTd1);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTd1);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	printf(ANSI_F_GREEN);
	size = printf(TESTd2);
	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	size = ft_printf(TESTd2);
	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTd3);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTd3);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTd4);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTd4);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTd5);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTd5);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTd6);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTd6);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTd7);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTd7);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTd8);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTd8);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	printf(ANSI_F_GREEN);
	size = printf(TESTd9);
	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	size = ft_printf(TESTd9);
	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	printf(ANSI_F_GREEN);
	size = printf(TESTd10);
	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	size = ft_printf(TESTd10);
	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	printf(ANSI_F_GREEN);
	size = printf(TESTd11);
	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	size = ft_printf(TESTd11);
	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	printf(ANSI_F_GREEN);
	size = printf(TESTd12);
	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	size = ft_printf(TESTd12);
	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	printf(ANSI_F_GREEN);
	size = printf(TESTd13);
	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	size = ft_printf(TESTd13);
	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	printf(ANSI_F_GREEN);
	size = printf(TESTd14);
	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	size = ft_printf(TESTd14);
	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTd15);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTd15);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTd16);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTd16);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTd17);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTd17);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTd18);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTd18);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTd19);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTd19);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTd20);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTd20);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTd21);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTd21);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTd22);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTd22);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTd23);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTd23);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTd24);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTd24);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTd25);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTd25);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTd26);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTd26);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTd27);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTd27);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTd28);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTd28);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTd29);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTd29);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTd30);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTd30);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTd31);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTd31);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTd32);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTd32);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTd33);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTd33);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
}



void	make_test_s()
{
	//int	size;

	// printf(ANSI_F_GREEN);
	// size = printf(TESTsRomeu1);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTsRomeu1);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTs42);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTs42);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTs50);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTs50);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTs73);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// size = ft_printf(TESTs73);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);


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

	// // printf(ANSI_F_GREEN);
	// // size = printf(TESTs26);
	// // printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET "\n", size);
	// // size = ft_printf(TESTs26);
	// // printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

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
}


int	main(void)
{
	make_test_s();
	//make_test_p();
	make_test_d();

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
