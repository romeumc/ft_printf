/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 16:29:21 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/28 17:02:39 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	print_minus_ifnegative(t_format *format)
{
	if (format->precision == 1 && format->flag_minus == 0 && format->neg_width == 0 && ft_strequ(format->conversion, "decimal"))
	{
		if (format->negative_nb == 1 && format->flag_zero == 0 && format->neg_precision == 0)
			output_putchar(format, '-');
		if (format->negative_nb == 1 && format->flag_zero == 1 && format->neg_precision == 0)
			output_putchar(format, '-');
		if (format->negative_nb == 1 && format->flag_zero == 0 && format->neg_precision == 1)
			output_putchar(format, '-');
	}
	else if (format->negative_nb == 1)
		output_putchar(format, '-');
}

void	print_space(t_format *format)
{
	if (format->negative_nb == 0 && format->flag_space == 1)
		output_putchar(format, ' ');
}

void	print_plus(t_format *format)
{
	if (format->negative_nb == 0 && format->flag_plus == 1)
		output_putchar(format, '+');
}

void	print_hex_cardinal(t_format *format, char *str)
{
	if (ft_strequ(str,"0") == 0)
	{
		if (format->flag_cardinal == 10)
		{
			output_putstr(format, "0x");
		}
		else if (format->flag_cardinal == 20)
		{
			output_putstr(format, "0X");
		}
	}
}

void	treat_flags(t_format *format, char *str)
{
	print_minus_ifnegative(format);
	print_hex_cardinal(format, str);
	print_space(format);
	print_plus(format);
}

void	precheck_flags(t_format *format, char *str)
{
	if (format->flag_cardinal != 0 && ft_strequ(str,"0") == 0)
		format->precision_size += 2;
	
	if (format->flag_space == 1 && format->negative_nb == 0)
	{
		if (format->precision == 1 && ft_strequ(str, "0") && ft_strequ(format->conversion, "decimal")
		&& format->precision_size == 0 && format->flag_minus == 1 && format->flag_zero == 1)
		{
			format->width -= 1;
		}
		else
		{
			format->precision_size += 1;
		}
	}	
	if (format->flag_plus == 1 && format->negative_nb == 0)
	{
		if (format->precision == 1 && ft_strequ(str, "0") && ft_strequ(format->conversion, "decimal")
		&& format->precision_size == 0)
		{
			//printf("AQUI");
			format->width -= 1;
		}
		else
		{
			//printf("ALI");
			format->precision_size += 1;
		}
	}
}