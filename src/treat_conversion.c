/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:02:34 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/27 20:26:24 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	debub______________________________________________________________format(t_format *format)
{
	printf(ANSI_B_BBLUE "width:[%d]" ANSI_RESET " ", format->width);
	printf(ANSI_B_BBLUE "zero:[%d]" ANSI_RESET " ", format->flag_zero);
	printf(ANSI_B_BBLUE "precision:[%d]" ANSI_RESET " ", format->precision);
	printf(ANSI_B_BBLUE "precision_size:[%d]" ANSI_RESET " ", format->precision_size);
	printf(ANSI_B_BBLUE "minus:[%d]" ANSI_RESET " ", format->flag_minus);
	printf(ANSI_B_BBLUE "neg_precision:[%d]" ANSI_RESET " ", format->neg_precision);
	printf(ANSI_B_BBLUE "neg_width:[%d]" ANSI_RESET " ", format->neg_width);
	printf(ANSI_B_BBLUE "negative_nb:[%d]" ANSI_RESET " ", format->negative_nb);
	printf(ANSI_B_BBLUE "sharp:[%d]" ANSI_RESET " ", format->flag_cardinal);
	printf(ANSI_B_BBLUE "space:[%d]" ANSI_RESET " ", format->flag_space);
	printf(ANSI_B_BBLUE "plus:[%d]" ANSI_RESET " ", format->flag_plus);
}

void	print_string_precision_minus(t_format *f, char *str, int len_diff, int output_len)
{
	if (ft_strequ(f->conversion, "decimal"))
	{
		//debub______________________________________________________________format(f);
		precheck_flags(f, str);
		treat_flags(f, str);
		treat_precision_decimal(f, (f->precision_size - len_diff));
		output_putnstr(f, str, output_len);
		treat_width_decimal(f, (f->width - f->precision_size - f->negative_nb));
	}
	else
	{
		output_putnstr(f, str, output_len);
		treat_width(f, (f->precision_size - len_diff));
	}
}

void	print_string_precision_no_minus(t_format *f, char *str,
	int len_diff, int output_len)
{
	if (ft_strequ(f->conversion, "decimal"))
	{
		//debub______________________________________________________________format(f);
		precheck_flags(f, str);
		if (f->negative_nb == 1 && f->neg_precision == 1 && f->flag_zero == 1)
			output_putchar(f, '-');
		treat_width_decimal(f, (f->width - f->precision_size - f->negative_nb));
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

void	print_string_with_precision(t_format *format, char *str)
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

void	print_string_without_precision(t_format *format, char *str)
{
	if (format->flag_zero == 0)
	{
		//debub______________________________________________________________format(format);
		precheck_flags(format, str);
		treat_width(format, ft_strlen(str) + format->negative_nb + format->precision_size);
		treat_flags(format, str);
		output_putstr(format, str);
	}
	else
	{
		//debub______________________________________________________________format(format);
		precheck_flags(format, str);
		treat_flags(format, str);
		treat_width(format, ft_strlen(str) + format->negative_nb + format->precision_size);
		output_putstr(format, str);
	}
}

void	print_string(t_format *format, char *str)
{
	if (format->precision == 0)
	{
		if (format->flag_minus == 1 || format->neg_width == 1)
		{
			//debub______________________________________________________________format(format);
			precheck_flags(format, str);
			treat_flags(format, str);
			output_putstr(format, str);
			treat_width(format, ft_strlen(str) + format->negative_nb + format->precision_size);
		}
		else
		{
			print_string_without_precision(format, str);
		}
	}
	else if (ft_strequ(str, "0") && ft_strequ(format->conversion, "decimal")
		&& format->precision_size == 0)
	{
		if (format->flag_minus == 1)
		{
			//debub______________________________________________________________format(format);
			precheck_flags(format, str);
			treat_flags(format, str);
			format->flag_minus = 1;
			treat_width(format, ft_strlen(str) - format->flag_minus);
		}
		else
		{
			//debub______________________________________________________________format(format);
			precheck_flags(format, str);
			format->flag_minus = 1;
			treat_width(format, ft_strlen(str) - format->flag_minus);
			treat_flags(format, str);
		}
	}
	else
	{
		print_string_with_precision(format, str);
	}
}
