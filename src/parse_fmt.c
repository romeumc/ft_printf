/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:48:09 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/09 01:47:44 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	get_flags(char fmt_char, t_format *format)
{
	if (fmt_char == '-')
		format->flag_minus = 1;
	if (fmt_char == '0')
		format->flag_zero = 1;
	if (fmt_char == '#')
		format->flag_cardinal = 1;
	if (fmt_char == ' ')
		format->flag_space = 1;
	if (fmt_char == '+')
		format->flag_plus = 1;
}

static void	get_width(char fmt_char, t_format *format, va_list ap)
{
	if (fmt_char == '*')
		format->width = va_arg(ap, int);
	else
		format->width = format->width * 10 + (fmt_char - '0');
	if (format->width < 0)
	{
		format->neg_width = 1;
		format->width = -format->width;
	}
}

static void	get_precision(char fmt_char, t_format *format, va_list ap)
{
	if (format->precision == 1)
	{
		format->precision_set = 1;
		if (fmt_char == '*')
			format->precision_size = va_arg(ap, int);
		else
			format->precision_size =
				format->precision_size * 10 + (fmt_char - '0');
		if (format->precision_size < 0)
		{
			format->neg_precision = 1;
		}
	}
	if (fmt_char == '.')
		format->precision = 1;
}

static void	get_length(char fmt_char, t_format *format)
{
	if (fmt_char == 'l')
		format->modifier_l++;
	if (fmt_char == 'h')
		format->modifier_h++;
}

void		parse_fmt(size_t *i, const char *fmt, t_format *format, va_list ap)
{
	*i += 1;
	while (ft_strchr(FLAGS, fmt[*i]))
	{
		get_flags(fmt[*i], format);
		*i += 1;
	}
	while (ft_strchr(WIDTH, fmt[*i]))
	{
		get_width(fmt[*i], format, ap);
		*i += 1;
	}
	while (ft_strchr(PRECISION, fmt[*i]))
	{
		get_precision(fmt[*i], format, ap);
		*i += 1;
	}
	while (ft_strchr(LENGTHMODIFIER, fmt[*i]))
	{
		if (format->modifier_h == 2 || format->modifier_l == 2)
			break ;
		else
			get_length(fmt[*i], format);
		*i += 1;
	}
	format->conversion = get_convertion(fmt[*i]);
}
