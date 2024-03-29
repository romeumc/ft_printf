/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_conversion_string_decimal.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:02:34 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/09 12:33:33 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	print_string_precision_minus(t_format *f, char *str,
	int len_diff, int output_len)
{
	if (ft_strequ(f->conversion, "decimal"))
	{
		precheck_flags(f, str);
		treat_flags(f, str);
		treat_precision_decimal(f, (f->precision_size - len_diff));
		output_putnstr(f, str, output_len);
		treat_width_dec(f, (f->width - f->precision_size - f->negative_nb));
	}
	else
	{
		output_putnstr(f, str, output_len);
		treat_width(f, (f->precision_size - len_diff));
	}
}

static void	print_string_precision_no_minus(t_format *f, char *str,
	int len_diff, int output_len)
{
	if (ft_strequ(f->conversion, "decimal"))
	{
		precheck_flags(f, str);
		if (f->negative_nb == 1 && f->neg_precision == 1 && f->flag_zero == 1)
			output_putchar(f, '-');
		treat_width_dec(f, (f->width - f->precision_size - f->negative_nb));
		treat_flags(f, str);
		treat_precision_decimal(f, (f->precision_size - len_diff));
		output_putnstr(f, str, output_len);
	}
	else
	{
		treat_width(f, (f->precision_size - len_diff));
		output_putnstr(f, str, output_len);
	}
}

static void	print_string_with_precision(t_format *format, char *str)
{
	int	len_diff;
	int	output_len;

	len_diff = 0;
	output_len = 0;
	if ((int)ft_strlen(str) < format->precision_size)
		len_diff = (format->precision_size - (int)ft_strlen(str));
	else if (ft_strequ(format->conversion, "decimal"))
		format->precision_size = (int)ft_strlen(str);
	if (format->neg_precision == 1)
	{
		format->precision_size = ft_strlen(str);
		output_len = ft_strlen(str);
	}
	else
	{
		output_len = format->precision_size - len_diff;
	}
	if (format->flag_minus == 1 || format->neg_width == 1)
		print_string_precision_minus(format, str, len_diff, output_len);
	else
		print_string_precision_no_minus(format, str, len_diff, output_len);
}

static void	print_string_without_precision(t_format *format, char *str)
{
	if (format->flag_zero == 0)
	{
		precheck_flags(format, str);
		treat_width(format, ft_strlen(str) + format->negative_nb +
			format->precision_size);
		treat_flags(format, str);
		output_putstr(format, str);
	}
	else
	{
		precheck_flags(format, str);
		treat_flags(format, str);
		treat_width(format, ft_strlen(str) + format->negative_nb +
			format->precision_size);
		output_putstr(format, str);
	}
}

void		print_string(t_format *format, char *str)
{
	if (format->precision == 0)
	{
		if (format->flag_minus == 1 || format->neg_width == 1)
		{
			precheck_flags(format, str);
			treat_flags(format, str);
			output_putstr(format, str);
			treat_width(format, ft_strlen(str) + format->negative_nb +
				format->precision_size);
		}
		else
		{
			print_string_without_precision(format, str);
		}
	}
	else if (ft_strequ(str, "0") && ft_strequ(format->conversion, "decimal")
		&& format->precision_size == 0)
	{
		print_string_zero(format, str);
	}
	else
	{
		print_string_with_precision(format, str);
	}
}
