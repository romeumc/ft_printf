/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 23:03:02 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/10 12:40:10 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#include "include/libftprintf.h"

void	init_list(t_format *format)
{
	format->conversion = "";
}

char *get_convertion(char fmt_char)
{
	if (fmt_char == 's')
		return ("string");
	if (fmt_char == 'd')
		return ("decimal");
	if (fmt_char == 'c')
		return ("char");
	if (fmt_char == '%')
		return ("percentage");
	else
		return (NULL);
}

void	parse_fmt(int *i, const char *fmt, t_format *format)
{
	*i += 1;
	// colocar check para FIELD WITDTH e incrementar se for diferente de null
	// colocar check para PRECISION
	// colocar check para LENGHT MODIFIER
	format->conversion = get_convertion(fmt[*i]);
}

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	t_format	format;
	// int			d;
	// char		c;
	// char		*s;
	int			i;

	if (fmt == NULL)
		return (0);
	init_list(&format);
	i = 0;
	printf("full format: %s\n", fmt);
	va_start(ap, fmt);
	while (fmt[i] != '\0')
	{
		printf (ANSI_F_CYAN "i:%d fmt[%d]:%c - conversion:[%s] !!!!\n" ANSI_RESET, i, i, fmt[i], format.conversion);
		if (fmt[i] == '%')
		{
			printf(ANSI_B_BRED "%% i:%d ==> " ANSI_RESET, i);
			parse_fmt(&i, fmt, &format);
			printf(ANSI_B_BRED "i:%d - conversion:[%s]" ANSI_RESET "\n" , i, format.conversion);
			
			if (format.conversion == NULL)
				return (0);
			printf(" compare:%d (%s) ", ft_strcmp(format.conversion, "decimal"), format.conversion);
			//if (ft_strcmp(format.conversion, "percentage") == 0)
				ft_putchar('%');
		}
		else
		{
			printf("[%c] ", fmt[i]);
			ft_putchar(fmt[i]);
		}
		// if (fmt[i] == 's')
		// {
		// 	s = va_arg(ap, char *);
		// 	printf("i:%d %c - string: %s\n", i, fmt[i], s);
		// }
		// if (fmt[i] == 'd')
		// {
		// 	d = va_arg(ap, int);
		// 	printf("i:%d %c - int: %d\n", i, fmt[i], d);
		// }
		// if (fmt[i] == 'c')
		// {
		// 	c = (char)va_arg(ap, int);
		// 	/* need a cast here since va_arg only takes fully promoted types */
		// 	printf("i:%d %c - char: %c\n", i, fmt[i], c);
		// }
		i++;
	}
	va_end(ap);
	return (0);
}
