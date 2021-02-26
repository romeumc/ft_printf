/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:02:34 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/26 14:47:18 by rmartins         ###   ########.fr       */
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
	printf(ANSI_B_BBLUE "negative_width:[%d]" ANSI_RESET " ", format->negative_width);
	printf(ANSI_B_BBLUE "negative_nb:[%d]" ANSI_RESET " ", format->negative_nb);
}

void	print_string_precision_minus(t_format *f, char *str, int len_diff, int output_len)
{
	if (ft_strequ(f->conversion, "decimal"))
	{
		//debub______________________________________________________________format(f);
		if (f->flag_cardinal != 0 && ft_strequ(str,"0") == 0)
			f->precision_size += 2;
		print_hex_cardinal(f, str);
		if (f->negative_nb == 1)
			output_putchar(f, '-');
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
		if (f->flag_cardinal != 0 && ft_strequ(str,"0") == 0)
			f->precision_size += 2;
		if (f->negative_nb == 1 && f->neg_precision == 1 && f->flag_zero == 1)
			output_putchar(f, '-');
		treat_width_decimal(f, (f->width - f->precision_size - f->negative_nb));
		if (f->negative_nb == 1 && f->flag_zero == 0 && f->neg_precision == 0)
			output_putchar(f, '-');
		if (f->negative_nb == 1 && f->flag_zero == 1 && f->neg_precision == 0)
			output_putchar(f, '-');
		if (f->negative_nb == 1 && f->flag_zero == 0 && f->neg_precision == 1)
			output_putchar(f, '-');
		print_hex_cardinal(f, str);
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
	if (format->flag_minus == 1 || format->negative_width == 1)
		print_string_precision_minus(format, str, len_diff, output_len);
	else
		print_string_precision_no_minus(format, str, len_diff, output_len);
}

void	print_string_without_precision(t_format *format, char *str)
{
	if (format->flag_zero == 0)
	{
		//debub______________________________________________________________format(format);
		if (format->flag_cardinal != 0 && ft_strequ(str,"0") == 0)
			format->precision_size += 2;
		treat_width(format, ft_strlen(str) + format->negative_nb + format->precision_size);
		print_hex_cardinal(format, str);
		print_minus_ifnegative(format);
		output_putstr(format, str);
	}
	else
	{
		//debub______________________________________________________________format(format);
		if (format->flag_cardinal != 0 && ft_strequ(str,"0") == 0)
			format->precision_size += 2;
		print_minus_ifnegative(format);
		print_hex_cardinal(format, str);
		treat_width(format, ft_strlen(str) + format->negative_nb + format->precision_size);
		output_putstr(format, str);
	}
}

void	print_string(t_format *format, char *str)
{
	if (format->precision == 0)
	{
		if (format->flag_minus == 1 || format->negative_width == 1)
		{
			//debub______________________________________________________________format(format);
			if (format->flag_cardinal != 0 && ft_strequ(str,"0") == 0)
				format->precision_size += 2;
			print_hex_cardinal(format, str);
			print_minus_ifnegative(format);
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
		format->flag_minus = 1;
		treat_width(format, ft_strlen(str) - format->flag_minus);
	}
	else
	{
		print_string_with_precision(format, str);
	}
}
