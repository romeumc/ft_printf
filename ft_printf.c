/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 23:03:02 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/05 22:35:24 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int	ft_printf(const char *fmt, ...)
{
	va_list ap;
	int d;
	char c;
	char *s;

	va_start(ap, fmt);
	while (*fmt)
		switch (*fmt++)
		{
			case 's':              /* string */
				s = va_arg(ap, char *);
				//printf("string %s\n", s);
				printf("%s", s);
				break;
			case 'd':              /* int */
				d = va_arg(ap, int);
				//printf("int %d\n", d);
				printf("%d", d);
				break;
			case 'c':              /* char */
				/* need a cast here since va_arg only takes fully promoted types */
				c = (char) va_arg(ap, int);
				//printf("char %c\n", c);
				printf("%c", c);
				break;
		}
	va_end(ap);
	return (0);
}
