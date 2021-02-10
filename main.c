/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 20:55:17 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/10 12:40:19 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libftprintf.h"
#include <stdio.h>

int	main(void)
{
	char romeu[]="romeu carvalho";
	size_t temp;

	temp = ft_strlen(romeu);
	printf("len:%ld\n", temp);
	printf("abc" "def\n");
	
	
	ft_printf("testes%sdddds%s%d%esc" "romeu." "teste", "abc", "def", "hij", 12, "   ", 't');

}
