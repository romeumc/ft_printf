/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 23:03:02 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/03 23:52:01 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
//#include "libftprint.h"
#include <stdio.h>

int	ft_printf(const char *fmt, ...)
{
	va_list ap;

	return (0);
}

int	main(void)
{
	char romeu[]="romeu carvalho";
	size_t temp;

	temp = ft_strlen(romeu);
	printf("len:%ld", temp);
}
