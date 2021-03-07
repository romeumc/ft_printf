/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 20:55:17 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/07 21:39:01 by rmartins         ###   ########.fr       */
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
#define TESTsRomeu2 "%.*s", -20, NULL

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
#define TESTd13a "[%0*.*d]", 21, 10, -101
#define TESTd14 " 0*%0-*d*0 0*%0*d*0 ", 21, 1021, 21, -1011
#define TESTd14a "%0*d", 21, -1011
#define TESTd15 " 0*%-0*.10d*0 0*%-0*.0d*0 ", 21, 1021, 21, -1011
#define TESTd16 " --0*%0*.0d*0 0*%0*.10d*0-- ", -2, 0, 21, 1
#define TESTd16a "%0*.0d", -2, 0
#define TESTd17 " --0*%0*.0d*0 0*%0*.10d*0-- ", -21, INT_MAX, 21, INT_MIN
#define TESTd17a "%0*.10d", 21, INT_MIN
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
#define TESTd276 "%7d", -14


/* ***** Test u ****************** */
#define TESTu1 "%u", 0
#define TESTu2 " %.u ", 0
#define TESTu3 " %-.2u ", 0
#define TESTu4 " %-2.2u ", 0
#define TESTu5 " %-3.2u ", 0
#define TESTu6 " %-3.2u %10.42u ", 0, 0
#define TESTu7 " %-3.2u %10.42u ", 1, -1
#define TESTu8 " %-3.2u %10.42u ", 10, -10
#define TESTu9 " *%-*.*u* *%*.*u* ", 4, 5, 10, 10, 21, -10
#define TESTu10 " *%-*.*u* *%*.*u* ", 6, 2, 102, 10, 21, -101
#define TESTu11 " *%*.*u* *%*.*u* ", -6, 2, 102, 10, 21, 101
#define TESTu12 " 0*%0-*.*u*0 0*%0*.*u*0 ", 6, 2, 102, 10, 21, -101
#define TESTu13 " 0*%0-*.*u*0 0*%0*.*u*0 ", 2, 6, 102, 21, 10, -101
#define TESTu14 " 0*%0-*u*0 0*%0*u*0 ", 21, 1021, 21, -1011
#define TESTu15 " 0*%-0*.10u*0 0*%-0*.0u*0 ", 21, 1021, 21, -1011
#define TESTu16 " --0*%0*.0u*0 0*%0*.10u*0-- ", -2, 0, 21, 1
#define TESTu17 " --0*%0*.0u*0 0*%0*.10u*0-- ", -21, INT_MAX, 21, INT_MIN
#define TESTu18 " --0*%0*.0u*0 0*%0*.10u*0-- ", -21, LONG_MAX, 21, LONG_MIN
#define TESTu19 " --0*%-0*.20u*0 0*%-0*.10u*0-- ", -21, CHAR_MAX, 21, CHAR_MIN
#define TESTu20 " --0*%-0*.2u*0 0*%-0*.2u*0-- ", -21, UINT_MAX, 21, UINT_MAX + 1
#define TESTu21 "%9.0u", UINT_MAX
#define TESTu22 "%9.1u", UINT_MAX
#define TESTu23 "%9.2u", UINT_MAX
#define TESTu24 "%9.10u", UINT_MAX
#define TESTu25 "%10.0u", UINT_MAX
#define TESTu26 "%10.1u", UINT_MAX
#define TESTu27 "%10.2u", UINT_MAX
#define TESTu28 "%10.10u", UINT_MAX
#define TESTu29 "%11.0u", UINT_MAX
#define TESTu30 "%11.1u", UINT_MAX
#define TESTu31 "%11.2u", UINT_MAX
#define TESTu32 "%11.10u", UINT_MAX
#define TESTu33 "%-9.0u", UINT_MAX
#define TESTu34 "%-9.1u", UINT_MAX
#define TESTu35 "%-9.2u", UINT_MAX
#define TESTu36 "%-9.10u", UINT_MAX
#define TESTu37 "%-10.0u", UINT_MAX
#define TESTu38 "%-10.1u", UINT_MAX
#define TESTu39 "%-10.2u", UINT_MAX
#define TESTu40 "%-10.10u", UINT_MAX
#define TESTu41 "%-11.0u", UINT_MAX
#define TESTu42 "%-11.1u", UINT_MAX
#define TESTu43 "%-11.2u", UINT_MAX
#define TESTu44 "%-11.10u", UINT_MAX
#define TESTu45 "%09.0u", UINT_MAX
#define TESTu46 "%09.1u", UINT_MAX
#define TESTu47 "%09.2u", UINT_MAX
#define TESTu48 "%09.10u", UINT_MAX
#define TESTu49 "%010.0u", UINT_MAX
#define TESTu50 "%010.1u", UINT_MAX
#define TESTu51 "%010.2u", UINT_MAX
#define TESTu52 "%010.10u", UINT_MAX
#define TESTu53 "%011.0u", UINT_MAX
#define TESTu54 "%011.1u", UINT_MAX
#define TESTu55 "%011.2u", UINT_MAX
#define TESTu56 "%011.10u", UINT_MAX
#define TESTu57 "%09.0u", UINT_MAX + 1
#define TESTu58 "%09.1u", UINT_MAX + 1
#define TESTu59 "%09.2u", UINT_MAX + 1
#define TESTu60 "%09.10u", UINT_MAX + 1
#define TESTu61 "%010.0u", UINT_MAX + 1
#define TESTu62 "%010.1u", UINT_MAX + 1
#define TESTu63 "%010.2u", UINT_MAX + 1
#define TESTu64 "%010.10u", UINT_MAX + 1
#define TESTu65 "%011.0u", UINT_MAX + 1
#define TESTu66 "%011.1u", UINT_MAX + 1
#define TESTu67 "%011.2u", UINT_MAX + 1
#define TESTu68 "%011.10u", UINT_MAX + 1
#define TESTu69 "%.0u", 0
#define TESTu70 "%.0u", 5
#define TESTu71 "%.0u", 10
#define TESTu72 "%1.u", 0
#define TESTu73 "%2.u", 0
#define TESTu74 "%3.u", 0
#define TESTu75 "%1.1u", 0
#define TESTu76 "%1.2u", 0
#define TESTu77 "%1.3u", 0
#define TESTu78 "%1.1u", 0
#define TESTu79 "%2.2u", 0
#define TESTu80 "%3.3u", 0

/* ************** Testes x ****************** */
#define TESTx1 " %x ", 0 
#define TESTx2 " %.x ", 0 
#define TESTx3 " %-.2x ", 0 
#define TESTx4 " %-2.2x ", 0 
#define TESTx5 " %-3.2x ", 0 
#define TESTx6 " %-3.2x %10.42x ", 0, 0 
#define TESTx7 " %-3.2x %10.42x ", 1, -1 
#define TESTx8 " %-3.2x %10.42x ", 10, -10 
#define TESTx9 " *%-*.*x* *%*.*x* ", 4, 5, 10, 10, 21, -10 
#define TESTx10 " *%-*.*x* *%*.*x* ", 6, 2, 102, 10, 21, -101 
#define TESTx11 " *%*.*x* *%*.*x* ", -6, 2, 102, 10, 21, 101 
#define TESTx12 " 0*%0-*.*x*0 0*%0*.*x*0 ", 6, 2, 102, 10, 21, -101 
#define TESTx13 " 0*%0-*.*x*0 0*%0*.*x*0 ", 2, 6, 102, 21, 10, -101 
#define TESTx14 " 0*%0-*x*0 0*%0*x*0 ", 21, 1021, 21, -1011 
#define TESTx15 " 0*%-0*.10x*0 0*%-0*.0x*0 ", 21, 1021, 21, -1011 
#define TESTx16 " --0*%0*.0x*0 0*%0*.10x*0-- ", -2, 0, 21, 1 
#define TESTx17 " --0*%0*.0x*0 0*%0*.10x*0-- ", -21, INT_MAX, 21, INT_MIN 
#define TESTx18 " --0*%0*.0x*0 0*%0*.10x*0-- ", -21, LONG_MAX, 21, LONG_MIN 
#define TESTx19 " --0*%-0*.20x*0 0*%-0*.10x*0-- ", -21, CHAR_MAX, 21, CHAR_MIN 
#define TESTx20 " --0*%-0*.2x*0 0*%-0*.2x*0-- ", -21, UINT_MAX, 21, UINT_MAX + 1 
#define TESTx21 "%9.0x", UINT_MAX 
#define TESTx22 "%9.1x", UINT_MAX 
#define TESTx23 "%9.2x", UINT_MAX 
#define TESTx24 "%9.10x", UINT_MAX 
#define TESTx25 "%10.0x", UINT_MAX 
#define TESTx26 "%10.1x", UINT_MAX 
#define TESTx27 "%10.2x", UINT_MAX 
#define TESTx28 "%10.10x", UINT_MAX 
#define TESTx29 "%11.0x", UINT_MAX 
#define TESTx30 "%11.1x", UINT_MAX 
#define TESTx31 "%11.2x", UINT_MAX 
#define TESTx32 "%11.10x", UINT_MAX 
#define TESTx33 "%-9.0x", UINT_MAX 
#define TESTx34 "%-9.1x", UINT_MAX 
#define TESTx35 "%-9.2x", UINT_MAX 
#define TESTx36 "%-9.10x", UINT_MAX 
#define TESTx37 "%-10.0x", UINT_MAX 
#define TESTx38 "%-10.1x", UINT_MAX 
#define TESTx39 "%-10.2x", UINT_MAX 
#define TESTx40 "%-10.10x", UINT_MAX 
#define TESTx41 "%-11.0x", UINT_MAX 
#define TESTx42 "%-11.1x", UINT_MAX 
#define TESTx43 "%-11.2x", UINT_MAX 
#define TESTx44 "%-11.10x", UINT_MAX 
#define TESTx45 "%09.0x", UINT_MAX 
#define TESTx46 "%09.1x", UINT_MAX 
#define TESTx47 "%09.2x", UINT_MAX 
#define TESTx48 "%09.10x", UINT_MAX 
#define TESTx49 "%010.0x", UINT_MAX 
#define TESTx50 "%010.1x", UINT_MAX 
#define TESTx51 "%010.2x", UINT_MAX 
#define TESTx52 "%010.10x", UINT_MAX 
#define TESTx53 "%011.0x", UINT_MAX 
#define TESTx54 "%011.1x", UINT_MAX 
#define TESTx55 "%011.2x", UINT_MAX 
#define TESTx56 "%011.10x", UINT_MAX 
#define TESTx57 "%09.0x", UINT_MAX + 1 
#define TESTx58 "%09.1x", UINT_MAX + 1 
#define TESTx59 "%09.2x", UINT_MAX + 1 
#define TESTx60 "%09.10x", UINT_MAX + 1 
#define TESTx61 "%010.0x", UINT_MAX + 1 
#define TESTx62 "%010.1x", UINT_MAX + 1 
#define TESTx63 "%010.2x", UINT_MAX + 1 
#define TESTx64 "%010.10x", UINT_MAX + 1 
#define TESTx65 "%011.0x", UINT_MAX + 1 
#define TESTx66 "%011.1x", UINT_MAX + 1 
#define TESTx67 "%011.2x", UINT_MAX + 1 
#define TESTx68 "%011.10x", UINT_MAX + 1 
#define TESTx69 "%.0x", 0 
#define TESTx70 "%.0x", 5 
#define TESTx71 "%.0x", 10 

#define TESTx72 "%1.x", 0 
#define TESTx73 "%2.x", 0 
#define TESTx74 "%3.x", 0 
#define TESTx75 "%1.1x", 0 
#define TESTx76 "%1.2x", 0 
#define TESTx77 "%1.3x", 0 
#define TESTx78 "%1.1x", 0 
#define TESTx79 "%2.2x", 0 
#define TESTx80 "%3.3x", 0

/* ************** Testes MIX ********** */
#define TESTmix1 ""
#define TESTmix2 "ccccc"
#define TESTmix3 "ddddd"
#define TESTmix4 "ppppp"
#define TESTmix5 " %%c%%s%%p%%d%%i%%u%%x%%X%% "
#define TESTmix6 " a%c%%c%%s%%p%%d%%i%%u%%x%%X%% ", 0
#define TESTmix7 " Tripouille "
#define TESTmix8 " a%c%%c%%s%%p%%d%%i%%u%%x%%X%%p%p", 0, (void *)42
#define TESTmix9 " a%c%%c%%s%%p%%d%%i%%u%%x%%X%%p%s", 0, ""
#define TESTmix10 "%%%%%%%%%%%%%%%%%s%%%s%%%s", "", "", ""
#define TESTmix11 "%s+", ""
#define TESTmix12 "%sChinimala%s", "xXx ", " xXx"
#define TESTmix13 "%s = <3 %s", "", ""
#define TESTmix14 "%s", NULL
#define TESTmix15 " 10%s ", "42"
#define TESTmix16 "%.4s%.s", "12345", "12345"
#define TESTmix17 "%10.4s%.5s", "12345", "12345"
#define TESTmix18 "%10.4s%s", "12345", "12345"
#define TESTmix19 "s%10.4s%ss", "12345", "54321"
#define TESTmix20 "0%10.4s0%ss", "12345", "54321"
#define TESTmix21 "*%10.4s*%ss", "1", "5"
#define TESTmix22 "%%*.s%10.4s*%ss", "1", "5"
#define TESTmix23 "%%*.s%10.4s%%*.s*%ss%%*.s", "1", "5"
#define TESTmix24 "%%*.s%c%%*.s*%ss%%*.s", 0, "5"
#define TESTmix25 "%%*.s%c%%*.s*%ss%%*.s", '2', ""
#define TESTmix26 "%%*.s%c%%*.s*%ss%%*.s", '0', "  "
#define TESTmix27 "%.5s%.s", "12345", "12345"
#define TESTmix28 "%%*.c%c%%*.s*%ps%%*.X", '0', NULL
#define TESTmix29 "%%%s%c%%c", "", 0
#define TESTmix30 "%10.*i%*.10i", 7, 42, 8, -42
#define TESTmix31 " %% %% %% %% %c %%cc%%cc%%%c ", -1, 0
#define TESTmix32 " %%* *%%. %%* *%%. .-%c -%%*cc*%%c*c%%%c %s%%%c", -1, 1, "Tripouille", 0
#define TESTmix33 "xXx%x%XxXx%%xXx%x%X", 15, 15, 16, 16

/* Testes do T5 */
#define TESTcinco34 "%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d
#define TESTcinco35 "%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d
#define TESTcinco36 "%-*i, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d
#define TESTcinco37 "%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d

#define TESTcinco37a "%.*i", a, i
#define TESTcinco70 "%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d
#define TESTcinco71 "%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d
#define TESTcinco72 "%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d


#define TESTcinco199 "%*.*i", -7, -4, -12
#define TESTcinco200 "%-*.*i", -7, -4, -12
#define TESTcinco201 "%0*.*i", -7, -4, -12

#define TESTcinco199a "%*.*i", -7, 0, -12
#define TESTcinco200a "%-*.*i", -7, 0, -12
#define TESTcinco201a "%0*.*i", -7, 0, -12

#define TESTcinco199b "%*.*i", -7, 4, -12
#define TESTcinco200b "%-*.*i", -7, 4, -12
#define TESTcinco201b "%0*.*i", -7, 4, -12
#define TESTsRomeu3 "%% *.5i 42 == |% *.5i|", 4, 42


/* Testes SHARP */
#define TESTsharpA "%#*.*x|%#*.*x|%#*.*x|%#*.*x", a, b, l, a, b, i, a, b, j, a, b, k
#define TESTsharpB "%#-*.*x|%#-*.*x|%#-*.*x|%#-*.*x", a, b, l, a, b, i, a, b, j, a, b, k
#define TESTsharpC "%#0*.*x|%#0*.*x|%#0*.*x|%#0*.*x", a, b, l, a, b, i, a, b, j, a, b, k

#define TESTsharp1 " %#x ", 0
#define TESTsharp2 " %#2x ", 0
#define TESTsharp3 " %#02x ", 0
#define TESTsharp4 " %#-03x ", 0
#define TESTsharp5 " %#-03.x ", 0
#define TESTsharp6 " %#-03.1x ", 0
#define TESTsharp7 " %#-03.2x ", 0
#define TESTsharp8 " %#-03.*x ", 2, 0
#define TESTsharp9 " %#x ", 1
#define TESTsharp10 " %#2x ", 1
#define TESTsharp11 " %#02x ", 1
#define TESTsharp12 " %#-03x ", 1
#define TESTsharp13 " %#-03.x ", 1
#define TESTsharp14 " %#-03.1x ", 1
#define TESTsharp15 " %#-03.2x ", 1
#define TESTsharp16 " %#-03.*x ", 2, 1
#define TESTsharp17 " %#05x ", 42

/* Testes SPACE */
#define TESTspace1 " % d ", 0
#define TESTspace2 " % 2d ", 0
#define TESTspace3 " % 02d ", 0
#define TESTspace4 " % -03d ", 0
#define TESTspace5 " % -03.d ", 0
#define TESTspace6 " % -03.1d ", 0
#define TESTspace7 " % -03.2d ", 0
#define TESTspace8 " % d ", -1
#define TESTspace9 " % 2d ", -1
#define TESTspace10 " % 02d ", -1
#define TESTspace11 " % 03d ", -1
#define TESTspace12 " % -03d ", -1
#define TESTspace13 " % -03.d ", -1
#define TESTspace14 " % -03.1d ", -1
#define TESTspace15 " % -03.2d ", -1
#define TESTspace16 " % -03.3d ", -1
#define TESTspace17 " % 03.3d ", -1
#define TESTspace18 " % 010.3d ", -1
#define TESTspace19 " % -010.3d ", -1
#define TESTspace20 " % -010.*d ", 42, -1
#define TESTspace21 " % .i ", 0
#define TESTspace22 " % .1i ", 0
#define TESTspace23 " % .2i ", 0

/* Testes PLUS */
#define TESTplus1 "%+5.0i", 0
#define TESTplus2 "%+5.i", 0
#define TESTplus3 "%+-5.0i", 0
#define TESTplus4 "%+-5.i", 0
#define TESTplus5 "%+5.0d", 0
#define TESTplus6 "%+5.d", 0
#define TESTplus7 "%+-5.0d", 0
#define TESTplus8 "%+-5.d", 0
#define TESTplus77 " %+f ", 0.
#define TESTplus78 " %+2f ", 0.
#define TESTplus79 " %+02f ", 0.
#define TESTplus80 " %+-03f ", 0.
#define TESTplus81 " %+-03.f ", 0.
#define TESTplus82 " %+-03.1f ", 0.
#define TESTplus83 " %+-03.2f ", 0.
#define TESTplus84 " %+f ", -1.
#define TESTplus85 " %+2f ", -1.
#define TESTplus86 " %+02f ", -1.
#define TESTplus87 " %+03f ", -1.
#define TESTplus88 " %+-03f ", -1.
#define TESTplus89 " %+-03.f ", -1.
#define TESTplus90 " %+-03.1f ", -1.
#define TESTplus91 " %+-03.2f ", -1.
#define TESTplus92 " %+-03.3f ", -1.
#define TESTplus93 " %+03.3f ", -1.
#define TESTplus94 " %+010.3f ", -1.
#define TESTplus95 " %+-010.3f ", -1.
#define TESTplus96 " %+-010.*f ", 42, -1.
#define TESTplus97 " %+.f ", 0.
#define TESTplus98 " %+.1f ", 0.
#define TESTplus99 " %+.2f ", 0.
#define TESTplus100 " %+.*f ", 0, 0.1234567890
#define TESTplus101 " %+.*f ", 1, 0.1234567890
#define TESTplus102 " %+.*f ", 2, 0.1234567890
#define TESTplus103 " %+.*f ", 3, 0.1234567890
#define TESTplus104 " %+.*f ", 4, 0.1234567890
#define TESTplus105 " %+.*f ", 5, 0.1234567890
#define TESTplus106 " %+.*f ", 6, 0.1234567890





/* Testes FLOAT */
#define TESTf1 " %f %f %f %f %f", 42.0, -42.0, 42.987654321, 42.999888777, -0.0
#define TESTf2 " %8f %9f %10f ", 42.0, -42.0, 42.0
#define TESTf3 " %7f %8f %9f ", 0.0, -1.0, 1.0
#define TESTf4 " %7.f %8.1f %9.2f ", 0.0, -1.0, 1.0
#define TESTf5 " %7.f %8.1f %9.2f ", 0.0, -1.0, 0.0
#define TESTf6 " %-7.f %-8.1f %-9.2f ", 0.0, -1.0, 0.0
#define TESTf7 " %-7.f %-8.1f %-9.2f ", 0.0, -1.0, 42.0
#define TESTf8 " %07.f %08.1f %09.2f ", 0.0, -1.0, 42.0
#define TESTf9 " %01.f %01.1f %01.2f ", 0.0, -1.0, 42.0
#define TESTf10 " %02.f %02.1f %02.2f ", 0.0, -1.0, 42.0
#define TESTf11 " %-02.f %-02.1f %-02.2f ", 0.0, -1.0, 42.0
#define TESTf12 " %-02.1f %-02.1f %-02.1f ", 0.0, -1.0, 42.0
#define TESTf13 " %-02.2f %-02.2f %-02.2f ", 0.0, -1.0, 42.0
#define TESTf14 " %-02.3f %-02.3f %-02.3f ", 0.0, -1.0, 42.0
#define TESTf15 " %-03.3f %-03.3f %-03.3f ", 0.0, -1.0, 42.0
#define TESTf16 " %-04.3f %-04.3f %-04.3f ", 0.0, -1.0, 42.0
#define TESTf17 " %-4.3f %-4.3f %-4.3f ", 0.0, -1.0, 42.0
#define TESTf18 " %-5.3f %-5.3f %-5.3f ", 0.0, -1.0, 42.0
#define TESTf19 " %-6.3f %-6.3f %-6.3f ", 0.0, -1.0, 42.0
#define TESTf20 " %-06.3f %-06.3f %-06.3f ", 0.0, -1.0, 42.0
#define TESTf21 " %06.3f %06.3f %06.3f ", 0.0, -1.0, 42.0
#define TESTf22 " %05.3f %05.3f %05.3f ", 0.0, -1.0, 42.0
#define TESTf23 " %05.3f %05.3f %05.3f ", 42.0, 420.0, -420.0
#define TESTf24 " %f %f ", LONG_MIN * 1.0, LONG_MAX * 1.0
#define TESTf25 " %.16f %.16f ", 0.01234567890123456789012345678901, -0.01234567890123456789012345678901
#define TESTf26 " %32.16f %32.16f ", 0.01234567890123456789012345678901, -0.01234567890123456789012345678901
#define TESTf27 " %33.16f %33.16f ", 0.01234567890123456789012345678901, -0.01234567890123456789012345678901
#define TESTf28 " %.f ", 42.101
#define TESTf29 " %f ", 0.101
#define TESTf30 " %10f ", 1.0 / 0
#define TESTf31 " %10.10f ", 1.0 / 0
#define TESTf32 " %0.20f ", 1.0 / 0
#define TESTf33 " %020.20f ", 1.0 / 0
#define TESTf34 " %-020.20f ", 1.0 / 0
#define TESTf35 " %-20.f ", 1.0 / 0
#define TESTf36 " %10f ", -1.0 / 0
#define TESTf37 " %10.10f ", -1.0 / 0
#define TESTf38 " %0.20f ", -1.0 / 0
#define TESTf39 " %020.20f ", -1.0 / 0
#define TESTf40 " %-020.20f ", -1.0 / 0
#define TESTf41 " %-20.f ", -1.0 / 0
#define TESTf42 " %10f ", 0.0 / 0
#define TESTf43 " %10.10f ", 0.0 / 0
#define TESTf44 " %0.20f ", 0.0 / 0
#define TESTf45 " %020.20f ", 0.0 / 0
#define TESTf46 " %-020.20f ", 0.0 / 0
#define TESTf47 " %-20.f ", 0.0 / 0
#define TESTf48 " %f ", 1.0 / 1000
#define TESTf49 " %.f ", 1.0 / 1000
#define TESTf50 " %.1f ", 1.0 / 1000
#define TESTf51 " %.2f ", 1.0 / 1000
#define TESTf52 " %.16f ", 1.0 / 1000
#define TESTf53 " %-f ", 1.0 / 1000
#define TESTf54 " %-.f ", 1.0 / 1000
#define TESTf55 " %-.1f ", 1.0 / 1000
#define TESTf56 " %-.2f ", 1.0 / 1000
#define TESTf57 " %-.16f ", 1.0 / 1000
#define TESTf58 " %f ", 1.0 / 10000
#define TESTf59 " %.f ", 1.0 / 10000
#define TESTf60 " %.1f ", 1.0 / 10000
#define TESTf61 " %.2f ", 1.0 / 10000
#define TESTf62 " %.16f ", 1.0 / 10000
#define TESTf63 " %-f ", 1.0 / 10000
#define TESTf64 " %-.f ", 1.0 / 10000
#define TESTf65 " %-.1f ", 1.0 / 10000
#define TESTf66 " %-.2f ", 1.0 / 10000
#define TESTf67 " %-.16f ", 1.0 / 10000
#define TESTf68 " %f ", 1.0 / 100000
#define TESTf69 " %.f ", 1.0 / 100000
#define TESTf70 " %.1f ", 1.0 / 100000
#define TESTf71 " %.2f ", 1.0 / 100000
#define TESTf72 " %.16f ", 1.0 / 100000
#define TESTf73 " %-f ", 1.0 / 100000
#define TESTf74 " %-.f ", 1.0 / 100000
#define TESTf75 " %-.1f ", 1.0 / 100000
#define TESTf76 " %-.2f ", 1.0 / 100000
#define TESTf77 " %-.16f ", 1.0 / 100000
#define TESTf78 "%.0f", 2.51
#define TESTf79 "%.0f", 1.5
#define TESTf80 "%.0f", 4.5
#define TESTf81 "%.0f", -2.5
#define TESTf82 "%.0f", -3.5
#define TESTf83 "%.0f", 2.5
#define TESTf84 "%.0f", 3.5
#define TESTf85 "%.0f", 2.45
#define TESTf86 "%.0f", 2.35
#define TESTf87 "%.0f", -2.35
#define TESTf88 "%.0f", 3.451
#define TESTf89 "%.0f", 3.456

static void	make_test_float()
{
	//int	size;

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf1);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.1\n", size);
	// size = ft_printf(TESTf1);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf2);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.2\n", size);
	// size = ft_printf(TESTf2);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTf3);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.3\n", size);
	// size = ft_printf(TESTf3);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTf4);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.4\n", size);
	// size = ft_printf(TESTf4);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTf5);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.5\n", size);
	// size = ft_printf(TESTf5);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTf6);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.6\n", size);
	// size = ft_printf(TESTf6);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTf7);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.7\n", size);
	// size = ft_printf(TESTf7);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTf8);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.8\n", size);
	// size = ft_printf(TESTf8);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTf9);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.9\n", size);
	// size = ft_printf(TESTf9);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTf10);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.10\n", size);
	// size = ft_printf(TESTf10);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf11);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.11\n", size);
	// size = ft_printf(TESTf11);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTf12);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.12\n", size);
	// size = ft_printf(TESTf12);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTf13);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.13\n", size);
	// size = ft_printf(TESTf13);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf14);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.14\n", size);
	// size = ft_printf(TESTf14);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTf15);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.15\n", size);
	// size = ft_printf(TESTf15);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf16);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.16\n", size);
	// size = ft_printf(TESTf16);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf17);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.17\n", size);
	// size = ft_printf(TESTf17);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf18);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.18\n", size);
	// size = ft_printf(TESTf18);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf19);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.19\n", size);
	// size = ft_printf(TESTf19);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf20);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.20\n", size);
	// size = ft_printf(TESTf20);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf21);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.21\n", size);
	// size = ft_printf(TESTf21);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf22);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.22\n", size);
	// size = ft_printf(TESTf22);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf23);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.23\n", size);
	// size = ft_printf(TESTf23);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf24);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.24\n", size);
	// size = ft_printf(TESTf24);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTf25);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.25\n", size);
	// size = ft_printf(TESTf25);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf26);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.26\n", size);
	// size = ft_printf(TESTf26);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf27);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.27\n", size);
	// size = ft_printf(TESTf27);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf28);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.28\n", size);
	// size = ft_printf(TESTf28);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf29);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.29\n", size);
	// size = ft_printf(TESTf29);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf30);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.30\n", size);
	// size = ft_printf(TESTf30);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf31);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.31\n", size);
	// size = ft_printf(TESTf31);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf32);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.32\n", size);
	// size = ft_printf(TESTf32);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf33);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.33\n", size);
	// size = ft_printf(TESTf33);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf34);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.34\n", size);
	// size = ft_printf(TESTf34);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTf35);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.35\n", size);
	// size = ft_printf(TESTf35);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf36);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.36\n", size);
	// size = ft_printf(TESTf36);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf37);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.37\n", size);
	// size = ft_printf(TESTf37);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf38);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.38\n", size);
	// size = ft_printf(TESTf38);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf39);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.39\n", size);
	// size = ft_printf(TESTf39);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf40);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.40\n", size);
	// size = ft_printf(TESTf40);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf41);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.41\n", size);
	// size = ft_printf(TESTf41);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf42);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.42\n", size);
	// size = ft_printf(TESTf42);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf43);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.43\n", size);
	// size = ft_printf(TESTf43);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf44);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.44\n", size);
	// size = ft_printf(TESTf44);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTf45);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.45\n", size);
	// size = ft_printf(TESTf45);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf46);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.46\n", size);
	// size = ft_printf(TESTf46);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf47);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.47\n", size);
	// size = ft_printf(TESTf47);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf48);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.48\n", size);
	// size = ft_printf(TESTf48);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf49);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.49\n", size);
	// size = ft_printf(TESTf49);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);



	// printf(ANSI_F_GREEN);
	// size = printf(TESTf70);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.70\n", size);
	// size = ft_printf(TESTf70);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf71);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.71\n", size);
	// size = ft_printf(TESTf71);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf72);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.72\n", size);
	// size = ft_printf(TESTf72);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf73);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.73\n", size);
	// size = ft_printf(TESTf73);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf74);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.74\n", size);
	// size = ft_printf(TESTf74);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTf75);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.75\n", size);
	// size = ft_printf(TESTf75);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf76);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.76\n", size);
	// size = ft_printf(TESTf76);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf77);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.77\n", size);
	// size = ft_printf(TESTf77);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf78);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.78\n", size);
	// size = ft_printf(TESTf78);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf79);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.79\n", size);
	// size = ft_printf(TESTf79);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);


	// printf(ANSI_F_GREEN);
	// size = printf(TESTf80);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.80\n", size);
	// size = ft_printf(TESTf80);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf81);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.81\n", size);
	// size = ft_printf(TESTf81);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf82);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.82\n", size);
	// size = ft_printf(TESTf82);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf83);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.83\n", size);
	// size = ft_printf(TESTf83);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf84);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.84\n", size);
	// size = ft_printf(TESTf84);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	// printf(ANSI_F_GREEN);
	// size = printf(TESTf85);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.85\n", size);
	// size = ft_printf(TESTf85);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf86);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.86\n", size);
	// size = ft_printf(TESTf86);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf87);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.87\n", size);
	// size = ft_printf(TESTf87);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf88);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.88\n", size);
	// size = ft_printf(TESTf88);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf(ANSI_F_GREEN);
	// size = printf(TESTf89);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.89\n", size);
	// size = ft_printf(TESTf89);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
}



void	make_test_plus()
{
	int	size;

// 	printf(ANSI_F_GREEN);
// 	size = printf(TESTplus1);
// 	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.832\n", size);
// 	size = ft_printf(TESTplus1);
// 	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	printf(ANSI_F_GREEN);
// 	size = printf(TESTplus2);
// 	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.833\n", size);
// 	size = ft_printf(TESTplus2);
// 	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	printf(ANSI_F_GREEN);
// 	size = printf(TESTplus3);
// 	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.834\n", size);
// 	size = ft_printf(TESTplus3);
// 	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	printf(ANSI_F_GREEN);
// 	size = printf(TESTplus4);
// 	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.835\n", size);
// 	size = ft_printf(TESTplus4);
// 	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	printf(ANSI_F_GREEN);
// 	size = printf(TESTplus5);
// 	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.1159\n", size);
// 	size = ft_printf(TESTplus5);
// 	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	printf(ANSI_F_GREEN);
// 	size = printf(TESTplus6);
// 	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.1160\n", size);
// 	size = ft_printf(TESTplus6);
// 	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	printf(ANSI_F_GREEN);
// 	size = printf(TESTplus7);
// 	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.1161\n", size);
// 	size = ft_printf(TESTplus7);
// 	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	printf(ANSI_F_GREEN);
// 	size = printf(TESTplus8);
// 	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.1162\n", size);
// 	size = ft_printf(TESTplus8);
// 	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	printf(ANSI_F_GREEN);
	size = printf(TESTplus77);
	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.77\n", size);
	size = ft_printf(TESTplus77);
	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	printf(ANSI_F_GREEN);
	size = printf(TESTplus78);
	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.78\n", size);
	size = ft_printf(TESTplus78);
	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	printf(ANSI_F_GREEN);
	size = printf(TESTplus79);
	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.79\n", size);
	size = ft_printf(TESTplus79);
	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);


	printf(ANSI_F_GREEN);
	size = printf(TESTplus80);
	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.80\n", size);
	size = ft_printf(TESTplus80);
	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	printf(ANSI_F_GREEN);
	size = printf(TESTplus81);
	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.81\n", size);
	size = ft_printf(TESTplus81);
	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	printf(ANSI_F_GREEN);
	size = printf(TESTplus82);
	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.82\n", size);
	size = ft_printf(TESTplus82);
	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	printf(ANSI_F_GREEN);
	size = printf(TESTplus83);
	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.83\n", size);
	size = ft_printf(TESTplus83);
	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	printf(ANSI_F_GREEN);
	size = printf(TESTplus84);
	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.84\n", size);
	size = ft_printf(TESTplus84);
	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	printf(ANSI_F_GREEN);
	size = printf(TESTplus85);
	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.85\n", size);
	size = ft_printf(TESTplus85);
	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	printf(ANSI_F_GREEN);
	size = printf(TESTplus86);
	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.86\n", size);
	size = ft_printf(TESTplus86);
	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	printf(ANSI_F_GREEN);
	size = printf(TESTplus87);
	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.87\n", size);
	size = ft_printf(TESTplus87);
	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	printf(ANSI_F_GREEN);
	size = printf(TESTplus88);
	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.88\n", size);
	size = ft_printf(TESTplus88);
	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	printf(ANSI_F_GREEN);
	size = printf(TESTplus89);
	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.89\n", size);
	size = ft_printf(TESTplus89);
	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);


	printf(ANSI_F_GREEN);
	size = printf(TESTplus90);
	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.90\n", size);
	size = ft_printf(TESTplus90);
	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	printf(ANSI_F_GREEN);
	size = printf(TESTplus91);
	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.91\n", size);
	size = ft_printf(TESTplus91);
	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	printf(ANSI_F_GREEN);
	size = printf(TESTplus92);
	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.92\n", size);
	size = ft_printf(TESTplus92);
	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	printf(ANSI_F_GREEN);
	size = printf(TESTplus93);
	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.93\n", size);
	size = ft_printf(TESTplus93);
	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	printf(ANSI_F_GREEN);
	size = printf(TESTplus94);
	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.94\n", size);
	size = ft_printf(TESTplus94);
	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
	printf(ANSI_F_GREEN);
	size = printf(TESTplus95);
	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.95\n", size);
	size = ft_printf(TESTplus95);
	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	printf(ANSI_F_GREEN);
	size = printf(TESTplus96);
	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.96\n", size);
	size = ft_printf(TESTplus96);
	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	printf(ANSI_F_GREEN);
	size = printf(TESTplus97);
	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.97\n", size);
	size = ft_printf(TESTplus97);
	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	printf(ANSI_F_GREEN);
	size = printf(TESTplus98);
	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.98\n", size);
	size = ft_printf(TESTplus98);
	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	printf(ANSI_F_GREEN);
	size = printf(TESTplus99);
	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.99\n", size);
	size = ft_printf(TESTplus99);
	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
}




// static void	make_test_space()
// {
// 	// int	size;

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTspace1);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.1\n", size);
// 	// size = ft_printf(TESTspace1);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTspace2);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.2\n", size);
// 	// size = ft_printf(TESTspace2);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTspace3);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.3\n", size);
// 	// size = ft_printf(TESTspace3);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTspace4);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.4\n", size);
// 	// size = ft_printf(TESTspace4);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTspace5);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.5\n", size);
// 	// size = ft_printf(TESTspace5);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTspace6);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.6\n", size);
// 	// size = ft_printf(TESTspace6);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTspace7);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.7\n", size);
// 	// size = ft_printf(TESTspace7);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTspace8);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.8\n", size);
// 	// size = ft_printf(TESTspace8);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTspace9);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.9\n", size);
// 	// size = ft_printf(TESTspace9);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTspace10);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.10\n", size);
// 	// size = ft_printf(TESTspace10);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTspace11);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.11\n", size);
// 	// size = ft_printf(TESTspace11);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTspace12);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.12\n", size);
// 	// size = ft_printf(TESTspace12);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTspace13);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.13\n", size);
// 	// size = ft_printf(TESTspace13);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTspace14);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.14\n", size);
// 	// size = ft_printf(TESTspace14);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTspace15);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.15\n", size);
// 	// size = ft_printf(TESTspace15);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTspace16);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.16\n", size);
// 	// size = ft_printf(TESTspace16);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTspace17);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.17\n", size);
// 	// size = ft_printf(TESTspace17);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTspace18);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.18\n", size);
// 	// size = ft_printf(TESTspace18);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTspace19);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.19\n", size);
// 	// size = ft_printf(TESTspace19);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTspace20);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.20\n", size);
// 	// size = ft_printf(TESTspace20);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTspace21);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.21\n", size);
// 	// size = ft_printf(TESTspace21);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTspace22);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.22\n", size);
// 	// size = ft_printf(TESTspace22);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTspace23);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.23\n", size);
// 	// size = ft_printf(TESTspace23);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
// }

// static void	make_test_sharp()
// {
// 	int	size;

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTsharp1);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.1\n", size);
// 	// size = ft_printf(TESTsharp1);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTsharp2);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.2\n", size);
// 	// size = ft_printf(TESTsharp2);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTsharp3);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.3\n", size);
// 	// size = ft_printf(TESTsharp3);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTsharp4);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.4\n", size);
// 	// size = ft_printf(TESTsharp4);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTsharp5);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.5\n", size);
// 	// size = ft_printf(TESTsharp5);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTsharp6);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.6\n", size);
// 	// size = ft_printf(TESTsharp6);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTsharp7);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.7\n", size);
// 	// size = ft_printf(TESTsharp7);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTsharp8);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.8\n", size);
// 	// size = ft_printf(TESTsharp8);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTsharp9);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.9\n", size);
// 	// size = ft_printf(TESTsharp9);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTsharp10);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.10\n", size);
// 	// size = ft_printf(TESTsharp10);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTsharp11);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.11\n", size);
// 	// size = ft_printf(TESTsharp11);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTsharp12);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.12\n", size);
// 	// size = ft_printf(TESTsharp12);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTsharp13);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.13\n", size);
// 	// size = ft_printf(TESTsharp13);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTsharp14);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.14\n", size);
// 	// size = ft_printf(TESTsharp14);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTsharp15);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.15\n", size);
// 	// size = ft_printf(TESTsharp15);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTsharp16);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.16\n", size);
// 	// size = ft_printf(TESTsharp16);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	printf(ANSI_F_GREEN);
// 	size = printf(TESTsharp17);
// 	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.16\n", size);
// 	size = ft_printf(TESTsharp17);
// 	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);


// 	// int		a;
// 	// int		b;
// 	// int		i = 8;
// 	// int		j = -12;
// 	// int		k = 12389;
// 	// int		l = 0;
// 	// // int		m = -12345678;
// 	// // // char	*n = "abcdefghijklmnop";
// 	// // // char	*o = "-a";
// 	// // // char	*p = "-12";
// 	// // // char	*q = "0";
// 	// // // char	*r = "%%";
// 	// // // char	*s = "-2147483648";
// 	// // // char	*t = "0x12345678";
// 	// // // char	*u = "-0";
// 	// // int	size;
// 	// int counter;
// 	// counter = 1;
	
// 	// a = -8;
// 	// while(a < 8)
// 	// {
// 	// 	b = -8;
// 	// 	while (b < 8)
// 	// 	{
// 	// 		printf(ANSI_F_GREEN);
// 	// 		size = printf(TESTsharpA);
// 	// 		printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test[%d] a:%d | b:%d\n", size, counter++, a, b);
// 	// 		size = ft_printf(TESTsharpA);
// 	// 		printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// 		printf(ANSI_F_GREEN);
// 	// 		size = printf(TESTsharpB);
// 	// 		printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test[%d] a:%d | b:%d\n", size, counter++, a, b);
// 	// 		size = ft_printf(TESTsharpB);
// 	// 		printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// 		printf(ANSI_F_GREEN);
// 	// 		size = printf(TESTsharpC);
// 	// 		printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test[%d] a:%d | b:%d\n", size, counter++, a, b);
// 	// 		size = ft_printf(TESTsharpC);
// 	// 		printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
// 	// 		b++;
// 	// 	}
// 	// 	a++;
// 	// }


// }

// static void	make_test_mazoise()
// {
// 	// int	size;
// 	// int		a = -4;
// 	// int		b = 0;
// 	// char	c = 'a';
// 	// int		d = 2147483647;
// 	// int		e = -2147483648;
// 	// // int		f = 42;
// 	// // int		g = 25;
// 	// // int		h = 4200;
// 	// int		i = 8;
// 	// int		j = -12;
// 	// int		k = 123456789;
// 	// int		l = 0;
// 	// int		m = -12345678;
// 	// // char	*n = "abcdefghijklmnop";
// 	// // char	*o = "-a";
// 	// // char	*p = "-12";
// 	// // char	*q = "0";
// 	// // char	*r = "%%";
// 	// // char	*s = "-2147483648";
// 	// // char	*t = "0x12345678";
// 	// // char	*u = "-0";
// 	// int counter;

// 	// counter = 34;
// 	// while (a < 5) //T34-69
// 	// {
// 	// 	printf(ANSI_F_GREEN);
// 	// 	size = printf(TESTcinco34);
// 	// 	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test[%d] a:%d | b:%d\n", size, counter++, a, b);
// 	// 	size = ft_printf(TESTcinco34);
// 	// 	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// 	printf(ANSI_F_GREEN);
// 	// 	size = printf(TESTcinco35);
// 	// 	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test[%d] a:%d | b:%d\n", size, counter++, a, b);
// 	// 	size = ft_printf(TESTcinco35);
// 	// 	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// 	printf(ANSI_F_GREEN);
// 	// 	size = printf(TESTcinco36);
// 	// 	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test[%d] a:%d | b:%d\n", size, counter++, a, b);
// 	// 	size = ft_printf(TESTcinco36);
// 	// 	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// 	printf(ANSI_F_GREEN);
// 	// 	size = printf(TESTcinco37);
// 	// 	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test[%d] a:%d | b:%d\n", size, counter++, a, b);
// 	// 	size = ft_printf(TESTcinco37);
// 	// 	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
		
// 	// 	a++;
// 	// }


// 	// counter = 70;
// 	// a = -2;
// 	// while(a < 5) //T70-177
// 	// {
// 	// 	b = -2;
// 	// 	while (b < 5)
// 	// 	{
// 	// 		printf(ANSI_F_GREEN);
// 	// 		size = printf(TESTcinco70);
// 	// 		printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test[%d] a:%d | b:%d\n", size, counter++, a, b);
// 	// 		size = ft_printf(TESTcinco70);
// 	// 		printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// 		printf(ANSI_F_GREEN);
// 	// 		size = printf(TESTcinco71);
// 	// 		printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test[%d] a:%d | b:%d\n", size, counter++, a, b);
// 	// 		size = ft_printf(TESTcinco71);
// 	// 		printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// 		printf(ANSI_F_GREEN);
// 	// 		size = printf(TESTcinco72);
// 	// 		printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test[%d] a:%d | b:%d\n", size, counter++, a, b);
// 	// 		size = ft_printf(TESTcinco72);
// 	// 		printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);


// 	// 		b++;
// 	// 	}
// 	// 	a++;
// 	// }


// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTcinco199);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test[%d] a:%d | b:%d\n", size, 199, 4, -4);
// 	// size = ft_printf(TESTcinco199);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTcinco200);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test[%d] a:%d | b:%d\n", size, 200, 4, -4);
// 	// size = ft_printf(TESTcinco200);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTcinco201);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test[%d] a:%d | b:%d\n", size, 201, 4, -4);
// 	// size = ft_printf(TESTcinco201);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);


// 	// /* versao a = precision nula */
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTcinco199a);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test[%d] a:%d | b:%d\n", size, 199, 4, 0);
// 	// size = ft_printf(TESTcinco199a);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTcinco200a);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test[%d] a:%d | b:%d\n", size, 200, 4, 0);
// 	// size = ft_printf(TESTcinco200a);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTcinco201a);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test[%d] a:%d | b:%d\n", size, 201, 4, 0);
// 	// size = ft_printf(TESTcinco201a);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// /* versao b = precision positiva */
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTcinco199b);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test[%d] a:%d | b:%d\n", size, 199, 4, 4);
// 	// size = ft_printf(TESTcinco199b);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTcinco200b);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test[%d] a:%d | b:%d\n", size, 200, 4, 4);
// 	// size = ft_printf(TESTcinco200b);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTcinco201b);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test[%d] a:%d | b:%d\n", size, 201, 4, 4);
// 	// size = ft_printf(TESTcinco201b);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);



// }

// static void	make_test_p()
// {
// 	int size;
// 	static char	a01;
// 	static unsigned char a02;
// 	static short a03;
// 	static unsigned short a04;
// 	static int a05;
// 	static unsigned int a06;
// 	static long a07;
// 	static unsigned long a08;
// 	static long long a09;
// 	static unsigned long long a10;
// 	static char *a11;
// 	static void *a12;

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTp1);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTp1);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTp2);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTp2);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTp3);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTp3);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTp4);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTp4);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTp5);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTp5);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTp6);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTp6);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTp7);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTp7);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTp8);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTp8);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTp9);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTp9);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTp10);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTp10);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTp11);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTp11);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTp12);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTp12);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTp13);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.13\n", size);
// 	// size = ft_printf(TESTp13);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTp14);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.14\n", size);
// 	// size = ft_printf(TESTp14);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTp15);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTp15);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTp16);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTp16);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTpp7);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTpp7);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTpp9);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTpp9);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTpp10);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTpp10);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTp173);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTp173);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	printf(ANSI_F_GREEN);
// 	size = printf(TESTp179);
// 	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.179\n", size);
// 	size = ft_printf(TESTp179);
// 	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTp180);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.180\n", size);
// 	// size = ft_printf(TESTp180);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
// }

// static void	make_test_d()
// {
// 	int	size;

// 	printf(ANSI_F_GREEN);
// 	size = printf(TESTd1);
// 	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	size = ft_printf(TESTd1);
// 	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	printf(ANSI_F_GREEN);
// 	size = printf(TESTd2);
// 	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	size = ft_printf(TESTd2);
// 	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd3);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd3);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd4);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd4);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd5);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd5);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd6);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd6);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd7);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd7);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd8);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd8);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd9);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd9);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd10);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd10);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd11);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd11);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd12);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd12);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd13);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd13);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd13a);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd13a);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd14);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd14);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd14a);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd14a);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd15);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd15);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd16);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd16);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd16a);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd16a);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd17);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd17);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd17a);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd17a);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd18);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd18);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd19);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd19);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd20);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd20);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd21);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd21);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd22);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd22);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd23);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd23);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd24);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd24);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd25);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd25);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd26);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd26);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd27);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd27);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd28);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd28);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd29);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd29);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd30);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd30);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd31);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd31);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd32);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd32);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd33);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd33);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd57);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd57);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd61);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd61);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd65);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd65);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd72);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd72);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd72);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd72);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd73);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd73);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTd276);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTd276);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// }

// static void	make_test_s()
// {
// 	// int	size;

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTsRomeu1);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.Romeu1\n", size);
// 	// size = ft_printf(TESTsRomeu1);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTsRomeu2);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.Romeu2\n", size);
// 	// size = ft_printf(TESTsRomeu2);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTs42);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTs42);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTs50);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTs50);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTs73);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTs73);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);


// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTs16);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.16\n", size);
// 	// size = ft_printf(TESTs16);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTs17);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTs17);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTs18);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTs18);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTs19);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTs19);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTs20);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTs20);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTs21);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTs21);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTs22);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.22\n", size);
// 	// size = ft_printf(TESTs22);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTs23);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTs23);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTs24);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTs24);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTs25);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTs25);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// // printf(ANSI_F_GREEN);
// 	// // size = printf(TESTs26);
// 	// // printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// // size = ft_printf(TESTs26);
// 	// // printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTs27);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTs27);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTs28);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTs28);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTs29);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTs29);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTs30);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTs30);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTs31);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTs31);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTs32);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTs32);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTs33);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.\n", size);
// 	// size = ft_printf(TESTs33);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);	
// }

// static void	make_test_u()
// {
// 	int	size;

// 	printf(ANSI_F_GREEN);
// 	size = printf(TESTu1);
// 	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.1\n", size);
// 	size = ft_printf(TESTu1);
// 	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTu2);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.2\n", size);
// 	// size = ft_printf(TESTu2);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTu3);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.3\n", size);
// 	// size = ft_printf(TESTu3);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTu4);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.4\n", size);
// 	// size = ft_printf(TESTu4);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTu5);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.5\n", size);
// 	// size = ft_printf(TESTu5);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTu6);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.6\n", size);
// 	// size = ft_printf(TESTu6);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTu7);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.7\n", size);
// 	// size = ft_printf(TESTu7);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTu8);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.8\n", size);
// 	// size = ft_printf(TESTu8);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTu9);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.9\n", size);
// 	// size = ft_printf(TESTu9);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTu10);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.10\n", size);
// 	// size = ft_printf(TESTu10);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTu11);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.11\n", size);
// 	// size = ft_printf(TESTu11);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTu12);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.12\n", size);
// 	// size = ft_printf(TESTu12);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTu13);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.13\n", size);
// 	// size = ft_printf(TESTu13);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTu14);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.14\n", size);
// 	// size = ft_printf(TESTu14);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTu15);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.15\n", size);
// 	// size = ft_printf(TESTu15);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTu16);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.16\n", size);
// 	// size = ft_printf(TESTu16);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTu17);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.17\n", size);
// 	// size = ft_printf(TESTu17);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTu18);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.18\n", size);
// 	// size = ft_printf(TESTu18);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTu19);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.19\n", size);
// 	// size = ft_printf(TESTu19);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTu20);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.20\n", size);
// 	// size = ft_printf(TESTu20);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTu21);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.21\n", size);
// 	// size = ft_printf(TESTu21);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTu22);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.22\n", size);
// 	// size = ft_printf(TESTu22);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTu23);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.23\n", size);
// 	// size = ft_printf(TESTu23);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTu24);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.24\n", size);
// 	// size = ft_printf(TESTu24);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTu25);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.25\n", size);
// 	// size = ft_printf(TESTu25);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTu26);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.26\n", size);
// 	// size = ft_printf(TESTu26);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTu27);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.27\n", size);
// 	// size = ft_printf(TESTu27);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTu28);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.28\n", size);
// 	// size = ft_printf(TESTu28);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTu29);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.29\n", size);
// 	// size = ft_printf(TESTu29);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTu30);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.30\n", size);
// 	// size = ft_printf(TESTu30);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTu31);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.31\n", size);
// 	// size = ft_printf(TESTu31);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTu32);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.32\n", size);
// 	// size = ft_printf(TESTu32);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTu33);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.33\n", size);
// 	// size = ft_printf(TESTu33);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
// }

// static void	make_test_mix()
// {
// 	// int	size;

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTmix1);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.1\n", size);
// 	// size = ft_printf(TESTmix1);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTmix2);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.2\n", size);
// 	// size = ft_printf(TESTmix2);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTmix3);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.3\n", size);
// 	// size = ft_printf(TESTmix3);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTmix4);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.4\n", size);
// 	// size = ft_printf(TESTmix4);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTmix5);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.5\n", size);
// 	// size = ft_printf(TESTmix5);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTmix6);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.6\n", size);
// 	// size = ft_printf(TESTmix6);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTmix7);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.7\n", size);
// 	// size = ft_printf(TESTmix7);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTmix8);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.8\n", size);
// 	// size = ft_printf(TESTmix8);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTmix9);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.9\n", size);
// 	// size = ft_printf(TESTmix9);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTmix10);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.10\n", size);
// 	// size = ft_printf(TESTmix10);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTmix11);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.11\n", size);
// 	// size = ft_printf(TESTmix11);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTmix12);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.12\n", size);
// 	// size = ft_printf(TESTmix12);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTmix13);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.13\n", size);
// 	// size = ft_printf(TESTmix13);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTmix14);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.14\n", size);
// 	// size = ft_printf(TESTmix14);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTmix15);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.15\n", size);
// 	// size = ft_printf(TESTmix15);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTmix16);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.16\n", size);
// 	// size = ft_printf(TESTmix16);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTmix17);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.17\n", size);
// 	// size = ft_printf(TESTmix17);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTmix18);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.18\n", size);
// 	// size = ft_printf(TESTmix18);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTmix19);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.19\n", size);
// 	// size = ft_printf(TESTmix19);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTmix20);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.20\n", size);
// 	// size = ft_printf(TESTmix20);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTmix21);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.21\n", size);
// 	// size = ft_printf(TESTmix21);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTmix22);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.22\n", size);
// 	// size = ft_printf(TESTmix22);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTmix23);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.23\n", size);
// 	// size = ft_printf(TESTmix23);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTmix24);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.24\n", size);
// 	// size = ft_printf(TESTmix24);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTmix25);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.25\n", size);
// 	// size = ft_printf(TESTmix25);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTmix26);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.26\n", size);
// 	// size = ft_printf(TESTmix26);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTmix27);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.27\n", size);
// 	// size = ft_printf(TESTmix27);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTmix28);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.28\n", size);
// 	// size = ft_printf(TESTmix28);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTmix29);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.29\n", size);
// 	// size = ft_printf(TESTmix29);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTmix30);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.30\n", size);
// 	// size = ft_printf(TESTmix30);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTmix31);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.31\n", size);
// 	// size = ft_printf(TESTmix31);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTmix32);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.32\n", size);
// 	// size = ft_printf(TESTmix32);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTmix33);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.33\n", size);
// 	// size = ft_printf(TESTmix33);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
// }

// static void	make_test_x()
// {
// 	int	size;

// 	printf(ANSI_F_GREEN);
// 	size = printf(TESTx1);
// 	printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.1\n", size);
// 	size = ft_printf(TESTx1);
// 	printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTx2);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.2\n", size);
// 	// size = ft_printf(TESTx2);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTx3);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.3\n", size);
// 	// size = ft_printf(TESTx3);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTx4);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.4\n", size);
// 	// size = ft_printf(TESTx4);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTx5);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.5\n", size);
// 	// size = ft_printf(TESTx5);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTx6);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.6\n", size);
// 	// size = ft_printf(TESTx6);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTx7);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.7\n", size);
// 	// size = ft_printf(TESTx7);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTx8);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.8\n", size);
// 	// size = ft_printf(TESTx8);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTx9);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.9\n", size);
// 	// size = ft_printf(TESTx9);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTx10);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.10\n", size);
// 	// size = ft_printf(TESTx10);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTx11);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.11\n", size);
// 	// size = ft_printf(TESTx11);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTx12);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.12\n", size);
// 	// size = ft_printf(TESTx12);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTx13);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.13\n", size);
// 	// size = ft_printf(TESTx13);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTx14);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.14\n", size);
// 	// size = ft_printf(TESTx14);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
	
// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTx15);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.15\n", size);
// 	// size = ft_printf(TESTx15);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTx16);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.16\n", size);
// 	// size = ft_printf(TESTx16);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTx17);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.17\n", size);
// 	// size = ft_printf(TESTx17);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTx18);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.18\n", size);
// 	// size = ft_printf(TESTx18);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTx19);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.19\n", size);
// 	// size = ft_printf(TESTx19);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTx20);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.20\n", size);
// 	// size = ft_printf(TESTx20);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTx21);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.21\n", size);
// 	// size = ft_printf(TESTx21);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTx22);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.22\n", size);
// 	// size = ft_printf(TESTx22);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTx23);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.23\n", size);
// 	// size = ft_printf(TESTx23);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTx24);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.24\n", size);
// 	// size = ft_printf(TESTx24);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTx25);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.25\n", size);
// 	// size = ft_printf(TESTx25);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTx26);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.26\n", size);
// 	// size = ft_printf(TESTx26);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTx27);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.27\n", size);
// 	// size = ft_printf(TESTx27);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTx28);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.28\n", size);
// 	// size = ft_printf(TESTx28);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTx29);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.29\n", size);
// 	// size = ft_printf(TESTx29);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTx30);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.30\n", size);
// 	// size = ft_printf(TESTx30);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTx31);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.31\n", size);
// 	// size = ft_printf(TESTx31);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTx32);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.32\n", size);
// 	// size = ft_printf(TESTx32);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

// 	// printf(ANSI_F_GREEN);
// 	// size = printf(TESTx33);
// 	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " Test.33\n", size);
// 	// size = ft_printf(TESTx33);
// 	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);
// }


int	main(void)
{
	//make_test_s();
	//make_test_p();
	//make_test_d();
	//make_test_u();
	//make_test_x();
	//make_test_mix();
	//make_test_mazoise();
	//make_test_sharp();
	//make_test_space();
	make_test_plus();
	make_test_float();

	//ft_printf("%.3f\n", -1.2315);
	//printf("%f %#-03.f %.1f %.1f %.1f %.1f\n", -0.0, 1.0, 3.85, 4.85, -3.85, 4.85);
	//ft_printf("%f %#-03.f %.1f %.1f %.1f %.1f\n", -0.0, 1.0, 3.85, 4.85, -3.85, 4.85);

	// printf("1,5 ==> %.0f     |     2,5 ==> %.0f", 1.5, 2.5);


	// char	*str;
	// str = ft_ulong_tobase(ULONG_MAX, HEX);
	// printf("\ndecimal:%ld | hex:%lx | mine:%s", ULONG_MAX, ULONG_MAX, str);
	// free(str);

	// str = ft_ulong_tobase(2546222222222287, HEX);
	// printf("\ndecimal:%ld | hex:%lx | mine:%s", 2546222222222287, 2546222222222287, str);
	// free(str);

	// char	*str;
	// str = ft_utoa(0u);
	// printf("\ndecimal:%u | mine:%s", 0u, str);
	// free(str);

	// str = ft_ulongtoa(22337203685477ul);
	// printf("\ndecimal:%ld | mine:%s", 22337203685477ul, str);
	// free(str);

	// char *str;
	// str = ft_ulongtoa(LONG_MAX * 1.0);
	// printf("\ndecimal:%f | mine:%s\n", LONG_MAX * 1.0, str);
	// free(str);
	// ft_printf("FT_PRINTF long:%ld float:%f", LONG_MAX, LONG_MAX * 1.0);

	// printf ("MAX: %llu\n", ft_iterative_power_ll(10, 10));
	// printf ("MAX: %llu\n", ft_iterative_power_ll(10, 9));
	// printf ("MAX: %llu", 12345678901234567890);
	// str = ft_ulonglongtoa(522337203685470ull);
	// printf("\ndecimal:%llu | mine:%s", 522337203685470ull, str);
	// free(str);



	// short a;
	// ft_printf("teste n - %hn", &a);
	// printf("\nvalor de a:%d", a);
	// char b;
	// ft_printf("teste n - %hhn", &b);
	// printf("\nvalor de b:%d", b);


	// printf("\n");
	// int size;
	// printf(ANSI_F_GREEN);
	// size = printf(TESTsRomeu3);
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " TestsRomeu3\n", size);
	// size = ft_printf(TESTsRomeu3);
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// printf("\n");
	// printf(ANSI_F_GREEN);
	// size = printf("TESTsRomeu3 - %c %c", 'v', 'r');
	// printf(ANSI_RESET ANSI_B_BGREEN "size:%d" ANSI_RESET " TestsRomeu3\n", size);
	// size = ft_printf("TESTsRomeu3 - %c %c", 'v', 'r');
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
	
	// printf(ANS0I_F_GREEN "[%-10c]" ANSI_RESET "\n", '0');
	// size = ft_printf("[%-10c]", '0');
	// printf(ANSI_B_BMAGENTA "size:%d" ANSI_RESET "\n", size);

	// int size;
	// size = ft_printf("%d%d", 1234,5678);
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
