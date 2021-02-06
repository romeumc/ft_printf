/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 20:55:17 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/05 22:36:36 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libftprintf.h"
#include "libft/libft.h"
#include <stdio.h>

int	main(void)
{
	char romeu[]="romeu carvalho";
	size_t temp;

	temp = ft_strlen(romeu);
	printf("len:%ld\n", temp);
	ft_printf("sssdsc", "abc", "def", "hij", 12, "   ", 't');
}
