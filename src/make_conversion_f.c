/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_conversion_f.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 19:42:42 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/07 01:53:18 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "../include/ft_printf.h"

void	debub__f____________________________________________________________format(t_format *format)
{
	printf(ANSI_B_BBLUE "width:[%d]" ANSI_RESET " ", format->width);
	printf(ANSI_B_BBLUE "zero:[%d]" ANSI_RESET " ", format->flag_zero);
	printf(ANSI_B_BBLUE "precision:[%d]" ANSI_RESET " ", format->precision);
	printf(ANSI_B_BBLUE "precision_size:[%d]" ANSI_RESET " ", format->precision_size);
	printf(ANSI_B_BBLUE "minus:[%d]" ANSI_RESET " ", format->flag_minus);
	// printf(ANSI_B_BBLUE "neg_precision:[%d]" ANSI_RESET " ", format->neg_precision);
	// printf(ANSI_B_BBLUE "neg_width:[%d]" ANSI_RESET " ", format->neg_width);
	printf(ANSI_B_BBLUE "negative_nb:[%d]" ANSI_RESET " ", format->negative_nb);
	// printf(ANSI_B_BBLUE "sharp:[%d]" ANSI_RESET " ", format->flag_cardinal);
	// printf(ANSI_B_BBLUE "space:[%d]" ANSI_RESET " ", format->flag_space);
	// printf(ANSI_B_BBLUE "plus:[%d]" ANSI_RESET " ", format->flag_plus);
	printf(ANSI_B_BBLUE "precision_set:[%d]" ANSI_RESET " ", format->precision_set);
}

void	print_float(t_format *format, char *str)
{
	if (format->flag_minus == 1 || format->neg_width == 1)
	{
		//debub__f____________________________________________________________format(format);
		if (format->negative_nb == 1)
			output_putchar(format, '-');
		output_putstr(format, str);
		treat_width(format, ft_strlen(str) + format->negative_nb);
	}
	else
	{
		if (format->flag_zero == 1)
		{
			//debub__f____________________________________________________________format(format);
			if (format->negative_nb == 1)
				output_putchar(format, '-');
			treat_width(format, ft_strlen(str) + format->negative_nb);
			output_putstr(format, str);
		}
		else
		{
			//debub__f____________________________________________________________format(format);
			treat_width(format, ft_strlen(str) + format->negative_nb);
			if (format->negative_nb == 1)
				output_putchar(format, '-');
			output_putstr(format, str);
		}
	}
}


long double	ft_roundup(t_format *format, long double remainder)
{
	long double temp;

	temp = (5.0 / ft_iterative_power_ll(10, format->precision_size + 1));
	//printf("[TESTE:%.17Lf %d]", temp, format->precision_size);
	//printf("10^17 %llu", ft_iterative_power_ll(10,11));
	remainder += temp;
	return (remainder);
}

char	*get_remainder(t_format *format, long double remainder)
{
	char	*str_remainder;
	char	*temp;
	int		i;
	//long	dr;


	//printf(ANSI_B_GREEN "[resto:%f]" ANSI_RESET, remainder);
	// if (format->precision == 0 && format->precision_set == 0)
	// {
	// 	format->precision_set = 1;
	// 	format->precision_size = 6;
	// }
	// else if (format->precision == 1 && format->precision_set == 0)
	// {
	// 	format->precision_size = 1;
	// }

	// if (remainder < 0)
	// 	remainder *= -1;
	// if (remainder != 0)
	// 	remainder = ft_roundup(format, remainder);
	i = 0;
	temp = malloc(sizeof(char) * (format->precision_size + 1));
	if (temp != NULL)
	{
		while (i < format->precision_size)
		{
			//printf(" 1:%f",remainder);
			remainder = remainder * 10 - ((int)remainder * 10);
			//printf(" 2:%f (%c)",remainder, (int)remainder + '0');
			temp[i] = ((int)remainder) + '0';
			i++;
		}
		temp[i] = '\0';
	}
	//printf(ANSI_B_RED "%s" ANSI_RESET, temp);
	str_remainder = ft_strdup(temp);
	free (temp);
	return (str_remainder);
}

int	ft_isinf(double num)
{
	return (num == (1.0 / 0.0) || num == (-1.0 / 0.0));
}

int	ft_isnan(double num)
{
	return (num == (0.0 / 0.0) || num == (-0.0 / 0.0));
}

void		conversion_float(t_format *format, va_list ap)
{
	char	*str_decimal;
	char	*str_remainder;
	char	*temp;
	char	*final;
	double	f;

	
	f = va_arg(ap, double);
	if (ft_isinf(f))
	{
		if (f < 0)
		{
			format->negative_nb = 1;
		}
		format->flag_zero = 0;
		temp = ft_strdup("inf");
		print_float(format, temp);
	}
	else if (ft_isnan(f))
	{
		if (f < 0)
		{
			format->negative_nb = 1;
		}
		format->flag_zero = 0;
		temp = ft_strdup("nan");
		print_float(format, temp);
	}
	else
	{
		if (format->precision == 0 && format->precision_set == 0)
		{
			format->precision_set = 1;
			format->precision_size = 6;
		}
		else if (format->precision == 1 && format->precision_set == 0)
		{
			format->precision_size = 1;
		}
		f = ft_roundup(format, f);
		temp = ft_longlongtoa((long long int)f);
	
		if (f < 0)
		{
			//printf(ANSI_B_RED "NEG %s" ANSI_RESET, temp);
			format->negative_nb = 1;
			str_decimal = ft_substr(temp, 1, ft_strlen(temp) - 1);
		}
		else
		{
			//printf(ANSI_B_BGREEN "POS %s" ANSI_RESET, temp);
			if ((long long)f < 0)
				str_decimal = ft_substr(temp, 1, ft_strlen(temp) - 1);
			else
				str_decimal = ft_strdup(temp);
		}
		if (ft_strequ(temp, "0"))
		{
			free(str_decimal);
			str_decimal = ft_strdup("0");
		}
		//printf(ANSI_B_BCYAN "%s" ANSI_RESET, str_decimal);
		free(temp);
		str_remainder = get_remainder(format, f - (long)f);
		
		if (format->precision_set == 0 || format->precision_size == 0)
			temp = ft_strdup("");
		else
		{
			format->precision_size = 0;
			temp = ft_strjoin(".", str_remainder);
		}
		final = ft_strjoin(str_decimal, temp);

		//format->conversion = "decimal";
		print_float(format, final);
		//print_string(format, final);
		//printf(ANSI_F_BCYAN "[%s]" ANSI_RESET, final);
		
		free(str_decimal);
		free(str_remainder);
		free(final);
	}
	free(temp);
}
