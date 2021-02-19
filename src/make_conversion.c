/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:06:29 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/19 18:56:36 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	treat_width(t_format *format, size_t len)
{
	int		i;
	char	c;

	i = 0;
	c = ' ';
	//printf("\t" ANSI_B_BBLUE "width:[%d]" ANSI_RESET "\t", format->field_width);
	//printf("\t" ANSI_B_BBLUE "zero:[%d]" ANSI_RESET "\t", format->flag_zero);
	if (format->flag_zero == 1 && format->flag_minus == 0)
		c = '0';
	if (format->field_width > (int)len)
	{
		while (i < format->field_width - (int)len)
		{
			format->output_lenght++;
			ft_putchar(c);
			i++;
		}
	}
}

// void	treat_zeros(t_format *format, size_t len)
// {
	
// }

void	conversion_string(t_format *format, va_list ap)
{
	char	*str;
	int		len_output_diff;
	
	len_output_diff = 0;
	str = va_arg(ap, char *);
	if (str == NULL)
	{
		str = "(null)";
		if (format->flag_minus == 1)
		{
			format->precision = 0;
			//format->flag_minus = 0;
			//format->field_width = ft_strlen(str);
		}
	}
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

int	get_size_inbase(long number, char *base)
{
	size_t	lenbase;
	int		counter;

	counter = 1;
	lenbase = ft_strlen(base);
	while (number >= (long)lenbase)
	{
		number /= lenbase;
		counter++;
	}
	return(counter);
}

void	conversion_pointer(t_format *format, va_list ap)
{
	unsigned long	address;

	address = (unsigned long)va_arg(ap, void *);
	if (address == 0)
	{
		format->output_lenght += ft_strlen(NULLSTR);
		treat_width(format, ft_strlen(NULLSTR));
		ft_putstr(NULLSTR);
	}
	else
	{
		if (format->flag_minus == 1)
		{
			format->output_lenght += ft_strlen(PREFIXHEX);
			ft_putstr(PREFIXHEX);
			format->output_lenght += get_size_inbase(address, HEX);
			ft_long_base(address, HEX);
			treat_width(format, get_size_inbase(address, HEX) + ft_strlen(PREFIXHEX));
		}
		else
		{
			treat_width(format, get_size_inbase(address, HEX) + ft_strlen(PREFIXHEX));
			format->output_lenght += ft_strlen(PREFIXHEX);
			ft_putstr(PREFIXHEX);
			format->output_lenght += get_size_inbase(address, HEX);
			ft_long_base(address, HEX);
		}
		
		//printf(" size:%d\n", get_size_inbase(address, HEX));
	}
	// ft_long_base(0, HEX);
	// printf(" test:%d\n", get_size_inbase(0, HEX));
	
	//address = (unsigned long)&p; 

	// format->output_lenght++;
	// if (format->flag_minus == 1)
	// {
	// 	ft_putchar(c);
	// 	treat_width(format, 1);
	// }
	// else
	// {
	// 	treat_width(format, 1);
	// 	ft_putchar(c);
	// }
	//printf(ANSI_B_BGREEN "conversion:[%s]" ANSI_RESET "\n", format->conversion);
	//printf("romeu:%ld ", address);
}


void	conversion_percentage(t_format *format)
{
	// format->output_lenght++;
	// ft_putchar('%');
	format->output_lenght++;
	if (format->flag_minus == 1)
	{
		ft_putchar('%');
		treat_width(format, 1);
	}
	else
	{
		treat_width(format, 1);
		ft_putchar('%');
	}
}

void	make_conversion(t_format *format, va_list ap)
{
	if (ft_strequ(format->conversion, "percentage"))
		conversion_percentage(format);
	if (ft_strequ(format->conversion, "string"))
		conversion_string(format, ap);
	if (ft_strequ(format->conversion, "decimal"))
		conversion_decimal(format, ap);
	if (ft_strequ(format->conversion, "char"))
		conversion_char(format, ap);
	if (ft_strequ(format->conversion, "pointer"))
		conversion_pointer(format, ap);
}
