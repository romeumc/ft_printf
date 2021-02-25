/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:06:29 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/25 10:25:37 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void debub______________________________________________________________format (t_format *format)
{
	printf( ANSI_B_BBLUE "width:[%d]" ANSI_RESET " ", format->field_width);
	printf( ANSI_B_BBLUE "zero:[%d]" ANSI_RESET " ", format->flag_zero);
	printf( ANSI_B_BBLUE "precision:[%d]" ANSI_RESET " ", format->precision);
	printf( ANSI_B_BBLUE "precision_size:[%d]" ANSI_RESET " ", format->precision_size);
	printf( ANSI_B_BBLUE "minus:[%d]" ANSI_RESET " ", format->flag_minus);
	printf( ANSI_B_BBLUE "negative_precision:[%d]" ANSI_RESET " ", format->negative_precision);
	printf( ANSI_B_BBLUE "negative_width:[%d]" ANSI_RESET " ", format->negative_width);
	printf( ANSI_B_BBLUE "negative_number:[%d]" ANSI_RESET " ", format->negative);
}

void	treat_width(t_format *format, size_t len)
{
	int		i;
	char	c;

	i = 0;
	c = ' ';
	// printf("\t" ANSI_B_RED "len:[%ld]" ANSI_RESET "\t", len);
	// debub______________________________________________________________format(format);
	
	if (format->flag_zero == 1 && format->flag_minus == 0)
		c = '0';

	if (format->negative_width == 1)
		c = ' ';
	
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
	//printf("\t" ANSI_B_RED "len:[%ld]" ANSI_RESET "\t", len);
	//debub______________________________________________________________format(format);
	int		i;
	char	c;

	i = 0;
	c = '0';
	while (i < format->precision_size - (int)len)
	{
		format->output_lenght++;
		ft_putchar(c);
		i++;
	}
}

void	treat_width_decimal(t_format *format, int len)
{
	//printf( ANSI_B_RED "len:[%d] " ANSI_RESET "\\t", len);
	//sdebub______________________________________________________________format(format);
	char	c;

	c = ' ';
	if (format->negative_precision == 1 && format->flag_minus == 0 && format->flag_zero == 1 && format->negative_width == 0)
		c = '0';	
	while (len > 0)
	{
		format->output_lenght++;
		ft_putchar(c);
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


	if (format->negative_precision == 1)
	{
		format->precision_size = ft_strlen(str);
		format->output_lenght += ft_strlen(str);
	}
	else
		format->output_lenght += format->precision_size - len_output_diff;
	
	
	//printf("strlen:%ld | precision:%d | len_diff:%d | output_len:%ld", ft_strlen(str), format->precision_size, len_output_diff, format->output_lenght);
	if (format->flag_minus == 1 || format->negative_width == 1)
	{
		if (ft_strequ(format->conversion, "decimal"))
		{
			//debub______________________________________________________________format(format);
			if (format->negative == 1)
				ft_putchar('-');
			treat_precision_decimal(format, (format->precision_size - len_output_diff));
			// if (format->negative == 1 && format->negative_precision == 0)
			// 	ft_putchar('-');
			ft_putnstr(str, format->precision_size);
			treat_width_decimal(format, (format->field_width - format->precision_size - format->negative));
		}
		else
		{
			//debub______________________________________________________________format(format);
			ft_putnstr(str, format->precision_size);
			treat_width(format, (format->precision_size - len_output_diff));
		}
	}
	else
	{
		if (ft_strequ(format->conversion, "decimal"))
		{
			//debub______________________________________________________________format(format);
			if (format->negative == 1 && format->negative_precision == 1 && format->flag_zero == 1)
				ft_putchar('-');
			treat_width_decimal(format, (format->field_width - format->precision_size - format->negative));
			if (format->negative == 1 && format->flag_zero == 0 && format->negative_precision == 0)
				ft_putchar('-');
			if (format->negative == 1 && format->flag_zero == 1 && format->negative_precision == 0)
				ft_putchar('-');
			if (format->negative == 1 && format->flag_zero == 0 && format->negative_precision == 1)
				ft_putchar('-');
			treat_precision_decimal(format, (format->precision_size - len_output_diff));
			ft_putnstr(str, format->precision_size);
		}
		else
		{
			
			//debub______________________________________________________________format(format);
			//printf("str:%s | len:%ld", str, ft_strlen(str));
			treat_width(format, (format->precision_size - len_output_diff));
			ft_putnstr(str, format->precision_size);
		}
	}
}

void	print_string(t_format *format, char *str)
{
	if (format->precision == 0)
	{
		//debub______________________________________________________________format(format);
		format->output_lenght += ft_strlen(str);
		if (format->flag_minus == 1 || format->negative_width == 1)
		{
			//debub______________________________________________________________format(format);
			if (format->negative == 1)
					ft_putchar('-');
			ft_putstr(str);
			treat_width(format, ft_strlen(str) + format->negative);
		}
		else
		{
			//debub______________________________________________________________format(format);
			if (format->flag_zero == 0)
			{
				treat_width(format, ft_strlen(str) + format->negative);
				if (format->negative == 1)
					ft_putchar('-');
			}
			else
			{
				if (format->negative == 1)
					ft_putchar('-');
				treat_width(format, ft_strlen(str) + format->negative);
			}
			ft_putstr(str);
		}
	}
	else if (ft_strequ(str, "0") && ft_strequ(format->conversion, "decimal") && format->precision_size == 0)
	{
		format->flag_minus = 1;
		//debub______________________________________________________________format(format);
		//printf( ANSI_B_BBLUE "str:[%s]" ANSI_RESET " ", str);
		treat_width(format, ft_strlen(str) - format->flag_minus);
	}
	else
	{
		//debub______________________________________________________________format(format);
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
	}
	print_string(format, str);
}

void	conversion_decimal(t_format *format, va_list ap)
{
	int		d;
	char	*str;
	char	*temp;

	d = va_arg(ap, int);
	temp = ft_itoa(d);
	if (d < 0)
	{
		format->output_lenght++;
		format->negative = 1;
		//str = ft_strndup(&str[1], ft_strlen(str) - 1);
		//str = ft_strtrim(str, "-");
		str = ft_substr(temp, 1, ft_strlen(temp) - 1);
	}
	else
	{
		str = ft_strdup(temp);
	}
	// printf( ANSI_B_CYAN "d:[%ld]" ANSI_RESET " ", d);
	// printf( ANSI_B_CYAN "str:[%s]" ANSI_RESET " ", str);
	// printf( ANSI_B_CYAN "temp:[%s]" ANSI_RESET " ", temp);
	free(temp);
	print_string(format, str);
	free(str);
}

void	conversion_unsigned_int(t_format *format, va_list ap)
{
	unsigned int	d;
	char			*str;

	d = (unsigned int)va_arg(ap, int);
	str = ft_longtoa(d);

	// printf( ANSI_B_CYAN "d:[%u]" ANSI_RESET " ", d);
	// printf( ANSI_B_CYAN "str:[%s]" ANSI_RESET " ", str);
	// printf( ANSI_B_CYAN "temp:[%s]" ANSI_RESET " ", temp);
	format->conversion = "decimal";
	print_string(format, str);
	free(str);
}

void	conversion_hexadecimal(t_format *format, va_list ap, char *type)
{
	unsigned int	d;
	char			*str;

	d = (unsigned int)va_arg(ap, int);
	if (ft_strequ(type, "lower"))
		str = ft_ulong_tobase(d, HEX);
	else
		str = ft_ulong_tobase(d, HEXCAP);
	
	// printf( ANSI_B_CYAN "d:[%u]" ANSI_RESET " ", d);
	// printf( ANSI_B_CYAN "str:[%s]" ANSI_RESET " ", str);

	format->conversion = "decimal";
	print_string(format, str);
	free(str);
}


void	conversion_pointer(t_format *format, va_list ap)
{
	unsigned long	address;
	char			*str;

	address = (unsigned long)va_arg(ap, void *);
	// if (address == 0)
	// {
	// 	format->output_lenght += ft_strlen(NULLSTR);
	// 	treat_width(format, ft_strlen(NULLSTR));
	// 	ft_putstr(NULLSTR);
	// }
	// else
	// {
		if (format->flag_minus == 1 || format->negative_width == 1)
		{
			format->output_lenght += ft_strlen(PREFIXHEX);
			ft_putstr(PREFIXHEX);
			format->output_lenght += ft_getsize_ulonginbase(address, HEX);
			str = ft_ulong_tobase(address, HEX);
			ft_putstr(str);
			treat_width(format, ft_getsize_ulonginbase(address, HEX) + ft_strlen(PREFIXHEX));
			free(str);
		}
		else
		{
			treat_width(format, ft_getsize_ulonginbase(address, HEX) + ft_strlen(PREFIXHEX));
			format->output_lenght += ft_strlen(PREFIXHEX);
			ft_putstr(PREFIXHEX);
			format->output_lenght += ft_getsize_ulonginbase(address, HEX);
			str = ft_ulong_tobase(address, HEX);
			ft_putstr(str);
			free(str);
		}
		
		//printf(" size:%d\n", get_size_inbase(address, HEX));
	// }
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
	if (format->flag_minus == 1 || format->negative_width == 1)
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
	if (format->flag_minus == 1 || format->negative_width == 1)
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
	if (ft_strequ(format->conversion, "unsigned_int"))
		conversion_unsigned_int(format, ap);
	if (ft_strequ(format->conversion, "hex"))
		conversion_hexadecimal(format, ap, "lower");
	if (ft_strequ(format->conversion, "hexCAP"))
		conversion_hexadecimal(format, ap, "upper");
}
