/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 23:03:02 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/09 18:19:51 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	init_list(t_format *format, int size, int flag)
{
	format->conversion = "";
	format->width = 0;
	format->neg_width = 0;
	format->output_length = size;
	format->flag_minus = 0;
	format->flag_zero = 0;
	format->flag_cardinal = 0;
	format->flag_space = 0;
	format->flag_plus = 0;
	format->precision = 0;
	format->precision_set = 0;
	format->precision_size = 0;
	format->neg_precision = 0;
	format->negative_nb = 0;
	format->modifier_h = 0;
	format->modifier_l = 0;
	format->exp_counter = 0;
	if (flag == 0)
		format->output = "";
}

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	t_format	format;
	size_t		i;

	if (fmt == NULL)
		return (0);
	init_list(&format, 0, 0);
	i = 0;
	va_start(ap, fmt);
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			parse_fmt(&i, fmt, &format, ap);
			make_conversion(&format, ap);
		}
		else
			output_putchar(&format, fmt[i]);
		init_list(&format, format.output_length, 1);
		i++;
	}
	va_end(ap);
	return ((int)format.output_length);
}
