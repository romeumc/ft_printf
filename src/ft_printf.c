/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 23:03:02 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/17 19:29:01 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	init_list(t_format *format)
{
	format->conversion = "";
	format->field_width = 0;
}

int	change_width(t_format *format, char **output)
{
	int		i;
	char	*temp;

	i = 0;
	if ((int)ft_strlen(*output) < format->field_width && !ft_strequ(format->conversion, "percentage"))
	{
		temp = ft_strdup(*output);
		//printf("\n ==>romeuoutput:[%s] malloc:%ld %p\n", *output, malloc_usable_size(*output), *output);
		//printf("\n ==>temp:[%s] malloc:%ld %p len:%ld\n", temp, malloc_usable_size(temp), temp, ft_strlen(temp));
		*output = ft_realloc(*output, format->field_width + 1);
		//printf("\n ==>romeuoutput:[%s] malloc:%ld %p\n", *output, malloc_usable_size(*output), *output);
		if (*output == NULL)
			return (0);
		while (i < format->field_width - (int)ft_strlen(temp))
		{
			//printf("* i:%d < %d | [%s]\n", i, format->field_width - (int)ft_strlen(temp), *output);
			output[0][i] = ' ';
			i++;
		}
		output[0][i] = '\0';
		//printf("\n ==>AQUIromeuoutput:[%s] malloc:%ld %p\n", *output, malloc_usable_size(*output), *output);
		*output = ft_strcat(*output, temp);
		free(temp);
		//printf(" ==>output:[%s] malloc:%ld %p", *output, malloc_usable_size(*output), *output);
	}
	return (1);
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
	if (output == NULL)
		return (0);
	//printf(ANSI_F_YELLOW "malloc:%ld %p " ANSI_RESET, malloc_usable_size(output), output);
	i = 0;
	//printf(ANSI_F_YELLOW "\nfull format: [%s]\n" ANSI_RESET, fmt);
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
			if (make_conversion(&format, &output, ap) == 0)
			{
				free(output);
				return (0);	
			};
			
		}
		else
		{
			//printf("[%c] ", fmt[i]);
			output = ft_strdup_join(output, fmt[i]);
			//printf(ANSI_F_YELLOW "malloc:%ld %p (%s) " ANSI_RESET, malloc_usable_size(output), output, output);
		}
		i++;
	}
	va_end(ap);
	change_width(&format, &output);
	//printf("OUTPUT\n");
	ft_putstr(output);
	i = ft_strlen(output);
	//printf(ANSI_F_BBLACK"\nmaloc:%ld | outputlen:%ld"ANSI_RESET, malloc_usable_size(output), ft_strlen(output));
	free(output);
	return ((int)i);
}
