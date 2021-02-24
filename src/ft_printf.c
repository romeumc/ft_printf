/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 23:03:02 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/24 00:34:38 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	init_list(t_format *format, int size)
{
	format->conversion = "";
	format->field_width = 0;
	format->negative_width = 0;
	format->output_lenght = size;
	format->flag_minus = 0;
	format->flag_zero = 0;
	format->flag_cardinal = 0;
	format->flag_space = 0;
	format->flag_plus = 0;
	format->precision = 0;
	format->precision_size = 0;
	format->negative = 0;
}

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	t_format	format;
	size_t		i;

	if (fmt == NULL)
		return (0);
	init_list(&format, 0);
	i = 0;
	//printf(ANSI_F_YELLOW "full format: [%s]" ANSI_RESET "\n", fmt);
	va_start(ap, fmt);
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			parse_fmt(&i, fmt, &format, ap);
			make_conversion(&format, ap);
		}
		else
		{
			format.output_lenght++;
			ft_putchar(fmt[i]);
		}
		init_list(&format, format.output_lenght);
		i++;
	}
	va_end(ap);
	return ((int)format.output_lenght);
}
