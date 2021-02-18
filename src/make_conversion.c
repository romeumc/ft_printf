/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:06:29 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/18 14:45:43 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	treat_width(t_format *format, size_t len)
{
	int i;

	i = 0;
	//printf("\t" ANSI_B_BBLUE "width:[%d]" ANSI_RESET "\t", format->field_width);
	if (format->field_width > (int)len)
	{
		while (i < format->field_width - (int)len)
		{
			format->output_lenght++;
			ft_putchar(' ');
			i++;
		}
	}
}

void	conversion_string(t_format *format, va_list ap)
{
	char	*str;
	int		len_output_diff;
	
	len_output_diff = 0;
	str = va_arg(ap, char *);
	if (format->precision == 0)
	{
		format->output_lenght += ft_strlen(str);
		if (format->flag_minus == 1)
		{
			ft_putstr(str);
			treat_width(format, ft_strlen(str));
		}
		else
		{
			treat_width(format, ft_strlen(str));
			ft_putstr(str);
		}
	}
	else
	{
		if ((int)ft_strlen(str) < format->precision_size)
			len_output_diff = (format->precision_size - (int)ft_strlen(str));
		format->output_lenght += format->precision_size - len_output_diff;
		//printf("strlen:%ld | precision:%d | len_diff:%d | output_len:%ld", ft_strlen(str), format->precision_size, len_output_diff, format->output_lenght);
		if (format->flag_minus == 1)
		{
			ft_putnstr(str, format->precision_size);
			treat_width(format, (format->precision_size - len_output_diff));
		}
		else
		{
			treat_width(format, (format->precision_size - len_output_diff));
			ft_putnstr(str, format->precision_size);
		}
	}
}

void	conversion_decimal(t_format *format, va_list ap)
{
	int		d;
	char	*str;

	d = va_arg(ap, int);
	str = ft_itoa(d);
	treat_width(format, ft_strlen(str));
	format->output_lenght += ft_strlen(str);
	ft_putstr(str);
	free(str);
	//printf(ANSI_B_BGREEN "conversion:[%s]" ANSI_RESET "\n", format->conversion);
}

void	conversion_char(t_format *format, va_list ap)
{
	char c;

	c = (char)va_arg(ap, int);
	format->output_lenght++;
	if (format->flag_minus == 1)
	{
		ft_putchar(c);
		treat_width(format, 1);
	}
	else
	{
		treat_width(format, 1);
		ft_putchar(c);
	}
	//printf(ANSI_B_BGREEN "conversion:[%s]" ANSI_RESET "\n", format->conversion);
}




void	make_conversion(t_format *format, va_list ap)
{
	if (ft_strequ(format->conversion, "percentage"))
	{
		format->output_lenght++;
		ft_putchar('%');
	}
	if (ft_strequ(format->conversion, "string"))
		conversion_string(format, ap);
	if (ft_strequ(format->conversion, "decimal"))
		conversion_decimal(format, ap);
	if (ft_strequ(format->conversion, "char"))
		conversion_char(format, ap);
}
