/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:06:29 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/22 03:39:28 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	treat_width(t_format *format, size_t len)
{
	int		i;
	char	c;

	i = 0;
	c = ' ';
	//printf("\t" ANSI_B_RED "len:[%ld]" ANSI_RESET "\t", len);
	//printf("\t" ANSI_B_BBLUE "width:[%d]" ANSI_RESET "\t", format->field_width);
	// printf("\t" ANSI_B_BBLUE "zero:[%d]" ANSI_RESET "\t", format->flag_zero);
	// printf("\t" ANSI_B_BBLUE "precision:[%d]" ANSI_RESET "\t", format->precision);
	// printf("\t" ANSI_B_BBLUE "precision_size:[%d]" ANSI_RESET "\t", format->precision_size);
	if (format->flag_zero == 1 && format->flag_minus == 0)
		c = '0';
	// if (ft_strequ(format->conversion, "decimal"))
	// {
	// 	c = '0';
	// }
	// printf("\t" ANSI_B_RED "len:[%ld]" ANSI_RESET "\t", len);
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

void	treat_precision_decimal(t_format *format, size_t len)
{
	int		i;
	char	c;

	i = 0;
	c = '0';
	// printf("\t" ANSI_B_RED "len:[%ld]" ANSI_RESET "\t", len);
	// printf("\t" ANSI_B_BBLUE "width:[%d]" ANSI_RESET "\t", format->field_width);
	// printf("\t" ANSI_B_BBLUE "zero:[%d]" ANSI_RESET "\t", format->flag_zero);
	// printf("\t" ANSI_B_BBLUE "precision:[%d]" ANSI_RESET "\t", format->precision);
	// printf("\t" ANSI_B_BBLUE "precision_size:[%d]" ANSI_RESET "\t", format->precision_size);
	// if (format->flag_zero == 1 && format->flag_minus == 0)
	// 	c = '0';
	// if (format->field_width > format->precision_size)
	// {
		while (i < format->precision_size - (int)len)
		{
			format->output_lenght++;
			ft_putchar(c);
			i++;
		}
	//}
}

void	treat_width_decimal(t_format *format, int len)
{
	// printf( ANSI_B_BBLUE "width:[%d] " ANSI_RESET "\\t", format->field_width);
	// printf( ANSI_B_BBLUE "zero:[%d] " ANSI_RESET "\\t", format->flag_zero);
	// printf( ANSI_B_BBLUE "precision:[%d] " ANSI_RESET "\\t", format->precision);
	// printf( ANSI_B_BBLUE "precision_size:[%d]" ANSI_RESET "\\t", format->precision_size);
	// printf( ANSI_B_RED "len:[%d] " ANSI_RESET "\\t", len);
	
	while (len > 0)
	{
		format->output_lenght++;
		ft_putchar(' ');
		len--;
	}
}

void	print_string_with_precision(t_format *format, char *str)
{
	int	len_output_diff;

	len_output_diff = 0;
	if ((int)ft_strlen(str) < format->precision_size)
		len_output_diff = (format->precision_size - (int)ft_strlen(str));
	else if (ft_strequ(format->conversion, "decimal"))
	{
		format->precision_size = (int)ft_strlen(str);
	}

	format->output_lenght += format->precision_size - len_output_diff;
	//printf("strlen:%ld | precision:%d | len_diff:%d | output_len:%ld", ft_strlen(str), format->precision_size, len_output_diff, format->output_lenght);
	if (format->flag_minus == 1)
	{
		if (ft_strequ(format->conversion, "decimal"))
		{
			if (format->negative == 1)
				ft_putchar('-');
			treat_precision_decimal(format, (format->precision_size - len_output_diff));
			ft_putnstr(str, format->precision_size);
			treat_width_decimal(format, (format->field_width - format->precision_size));
		}
		else
		{
			ft_putnstr(str, format->precision_size);
			treat_width(format, (format->precision_size - len_output_diff));
		}
	}
	else
	{
		if (ft_strequ(format->conversion, "decimal"))
		{
			treat_width_decimal(format, (format->field_width - format->precision_size));
			if (format->negative == 1)
				ft_putchar('-');
			treat_precision_decimal(format, (format->precision_size - len_output_diff));
			ft_putnstr(str, format->precision_size);
		}
		else
		{
			treat_width(format, (format->precision_size - len_output_diff));
			ft_putnstr(str, format->precision_size);
		}
	}
}

void	print_string(t_format *format, char *str)
{
	// printf( ANSI_B_BBLUE "precision:[%d] " ANSI_RESET "\t", format->precision);
	// printf( ANSI_B_BBLUE "precision_size:[%d]" ANSI_RESET "\t", format->precision_size);
	if (format->precision == 0)
	{
		format->output_lenght += ft_strlen(str);
		if (format->flag_minus == 1)
		{
			if (format->negative == 1)
					ft_putchar('-');
			ft_putstr(str);
			treat_width(format, ft_strlen(str) + format->negative);
		}
		else
		{
			treat_width(format, ft_strlen(str) + format->negative);
			if (format->negative == 1)
					ft_putchar('-');
			ft_putstr(str);
		}
	}
	else if (!(ft_strequ(str, "0") && ft_strequ(format->conversion, "decimal") && format->precision_size == 0))
	{
		print_string_with_precision(format, str);
	}
}


void	conversion_string(t_format *format, va_list ap)
{
	char	*str;
	
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
	print_string(format, str);
}

void	conversion_decimal(t_format *format, va_list ap)
{
	int		d;
	char	*str;

	d = va_arg(ap, int);
	if (d < 0)
	{
		format->output_lenght++;
		format->negative = 1;
		d = -d;
	}
	str = ft_itoa(d);
	print_string(format, str);
	free(str);
}

// char	*address_toa(long address, t_format *format)
// {
// 	format->output_lenght += ft_strlen(PREFIXHEX);
// 	ft_putstr(PREFIXHEX);
// 	format->output_lenght += get_size_inbase(address, HEX);
// 	ft_long_base(address, HEX);
// }

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
