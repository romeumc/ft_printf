/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:06:29 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/26 12:21:52 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	conversion_pointer(t_format *format, va_list ap)
{
	unsigned long	address;
	char			*str;

	address = (unsigned long)va_arg(ap, void *);
	str = ft_ulong_tobase(address, HEX);
	if (format->flag_minus == 1 || format->negative_width == 1)
	{
		output_putstr(format, PREFIXHEX);
		output_putstr(format, str);
		treat_width(format, ft_strlen(str) + ft_strlen(PREFIXHEX));
		free(str);
	}
	else
	{
		treat_width(format, ft_strlen(str) + ft_strlen(PREFIXHEX));
		output_putstr(format, PREFIXHEX);
		output_putstr(format, str);
		free(str);
	}
}

void	conversion_char(t_format *format, va_list ap)
{
	char c;

	c = (char)va_arg(ap, int);
	if (format->flag_minus == 1 || format->negative_width == 1)
	{
		output_putchar(format, c);
		treat_width(format, 1);
	}
	else
	{
		treat_width(format, 1);
		output_putchar(format, c);
	}
}

void	conversion_percentage(t_format *format)
{
	if (format->flag_minus == 1 || format->negative_width == 1)
	{
		output_putchar(format, '%');
		treat_width(format, 1);
	}
	else
	{
		treat_width(format, 1);
		output_putchar(format, '%');
	}
}

void	make_conversion(t_format *format, va_list ap)
{
	if (ft_strequ(format->conversion, "percentage"))
		conversion_percentage(format);
	if (ft_strequ(format->conversion, "string"))
		conversion_string(format, ap);
	if (ft_strequ(format->conversion, "decimal"))
		conversion_int(format, ap);
	if (ft_strequ(format->conversion, "char"))
		conversion_char(format, ap);
	if (ft_strequ(format->conversion, "pointer"))
		conversion_pointer(format, ap);
	if (ft_strequ(format->conversion, "unsigned_int"))
		conversion_unsigned_int(format, ap);
	if (ft_strequ(format->conversion, "hex"))
		conversion_hex(format, ap, "lower");
	if (ft_strequ(format->conversion, "heX"))
		conversion_hex(format, ap, "upper");
}
