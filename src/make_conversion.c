/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:06:29 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/09 19:43:16 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	conversion_pointer(t_format *format, va_list ap)
{
	unsigned long	address;
	char			*str;

	address = (unsigned long)va_arg(ap, void *);
	if (address == 0 && format->precision == 1)
		str = ft_strdup("");
	else
		str = ft_ulong_tobase(address, HEX);
	if (format->flag_minus == 1 || format->neg_width == 1)
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

static void	conversion_char(t_format *format, va_list ap)
{
	char c;

	c = (char)va_arg(ap, int);
	if (format->flag_minus == 1 || format->neg_width == 1)
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

static void	conversion_percentage(t_format *format)
{
	if (format->flag_minus == 1 || format->neg_width == 1)
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

void		make_conversion(t_format *format, va_list ap)
{
	if (format->flag_space == 1 && format->flag_plus == 1)
		format->flag_space = 0;
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
	if (ft_strequ(format->conversion, "n_chars"))
		conversion_nchars(format, ap);
	if (ft_strequ(format->conversion, "float"))
		conversion_float(format, ap);
	if (ft_strequ(format->conversion, "engineer"))
		conversion_engineer(format, ap);
}

char		*get_convertion(char fmt_char)
{
	if (fmt_char == 's')
		return ("string");
	if (fmt_char == 'd' || fmt_char == 'i')
		return ("decimal");
	if (fmt_char == 'c')
		return ("char");
	if (fmt_char == '%')
		return ("percentage");
	if (fmt_char == 'p')
		return ("pointer");
	if (fmt_char == 'u')
		return ("unsigned_int");
	if (fmt_char == 'x')
		return ("hex");
	if (fmt_char == 'X')
		return ("heX");
	if (fmt_char == 'n')
		return ("n_chars");
	if (fmt_char == 'f')
		return ("float");
	if (fmt_char == 'e')
		return ("engineer");
	else
		return (NULL);
}
