/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 23:03:02 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/10 16:58:43 by rmartins         ###   ########.fr       */
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

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	t_format	format;
	char		*output;
	size_t		i;

	if (fmt == NULL)
		return (0);
	init_list(&format);
	output = ft_calloc(1, sizeof(char));
	i = 0;
	//printf(ANSI_F_YELLOW "full format: [%s]\n" ANSI_RESET, fmt);
	va_start(ap, fmt);
	while (fmt[i] != '\0')
	{
		//printf (ANSI_F_CYAN "i:%ld fmt[%ld]:%c - conversion:[%s] !!!!\n" ANSI_RESET, i, i, fmt[i], format.conversion);
		if (fmt[i] == '%')
		{
			parse_fmt(&i, fmt, &format);
			//printf(ANSI_B_BGREEN "i:%ld - conversion:[%s]" ANSI_RESET "\n", i, format.conversion);

			if (format.conversion == NULL)
			{
				free(output);
				return (0);
			}
			make_conversion(&format, &output, ap);
			
		}
		else
		{
			//printf("[%c] ", fmt[i]);
			output = ft_strdup_join(output, fmt[i]);
		}
		i++;
	}
	va_end(ap);
	//printf("OUTPUT\n");
	i = ft_strlen(output);
	ft_putstr(output);
	//printf(ANSI_F_BBLACK"\nmaloc:%ld | outputlen:%ld"ANSI_RESET, malloc_usable_size(output), ft_strlen(output));
	free(output);
	return ((int)i);
}
