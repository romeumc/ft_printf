/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_conversion_f.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 19:42:42 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/07 22:54:02 by rmartins         ###   ########.fr       */
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
		// if (format->negative_nb == 1)
		// 	output_putchar(format, '-');
		treat_flags(format, str);
		output_putstr(format, str);
		if (format->flag_plus == 1)
			treat_width(format, ft_strlen(str) + format->flag_plus);
		else if (format->flag_space == 1)
			treat_width(format, ft_strlen(str) + format->flag_space);
		else
			treat_width(format, ft_strlen(str) + format->negative_nb);
	}
	else
	{
		if (format->flag_zero == 1)
		{
			//debub__f____________________________________________________________format(format);
			// if (format->negative_nb == 1)
			// 	output_putchar(format, '-');
			treat_flags(format, str);
			if (format->flag_plus == 1)
				treat_width(format, ft_strlen(str) + format->flag_plus);
			else if (format->flag_space == 1)
				treat_width(format, ft_strlen(str) + format->flag_space);
			else
				treat_width(format, ft_strlen(str) + format->negative_nb);
			output_putstr(format, str);
		}
		else
		{
			//debub__f____________________________________________________________format(format);
			if (format->flag_plus == 1)
				treat_width(format, ft_strlen(str) + format->flag_plus);
			else if (format->flag_space == 1)
				treat_width(format, ft_strlen(str) + format->flag_space);
			else
				treat_width(format, ft_strlen(str) + format->negative_nb);
			// if (format->negative_nb == 1)
			// 	output_putchar(format, '-');
			treat_flags(format, str);
			output_putstr(format, str);
		}
	}
}


long double	ft_bankersround(t_format *format, double f)
{
	double	roundincrement;
	double	decimal;
	long long	integer;

	integer = (long long)f;
	decimal = f - (long long)f;
	if (decimal < 0)
		decimal *= -1;
	roundincrement = (5.0 / ft_iterative_power_ll(10, format->precision_size + 1));
	if (decimal != 0)
	{
		if (decimal - roundincrement != 0 || integer % 2 != 0)
		{
			if (f < 0)
				f -= roundincrement;
			else
				f += roundincrement;
		}
	}
	return (f);
	
}

char	*get_decimalpart(t_format *format, double f)
{
	double	roundincrement;
	char	*str_decimal;
	char	*temp;
	int		i;
	double	decimal;

	decimal = f - (long long)f;
	//printf(ANSI_B_GREEN "[resto:%f]" ANSI_RESET, decimal);
	// if (format->precision == 0 && format->precision_set == 0)
	// {
	// 	format->precision_set = 1;
	// 	format->precision_size = 6;
	// }
	// else if (format->precision == 1 && format->precision_set == 0)
	// {
	// 	format->precision_size = 1;
	// }

	if (decimal < 0)
		decimal *= -1;
	roundincrement = (5.0 / ft_iterative_power_ll(10, format->precision_size + 1));
	decimal += roundincrement;
	i = 0;
	temp = malloc(sizeof(char) * (format->precision_size + 1));
	if (temp != NULL)
	{
		while (i < format->precision_size)
		{
			//printf(" 1:%f",decimal);
			decimal = decimal * 10 - ((int)decimal * 10);
			//printf(" 2:%f (%c)",decimal, (int)decimal + '0');
			temp[i] = ((int)decimal) + '0';
			i++;
		}
		temp[i] = '\0';
	}
	//printf(ANSI_B_RED "%s" ANSI_RESET, temp);
	str_decimal = ft_strdup(temp);
	free (temp);
	return (str_decimal);
}

int	isnan(double num)
{
	int result;

	result = 0;
	if (num == (0.0 / 0.0))
		result = 1;
	else if (num == (-0.0 / 0.0))
		result = -1;
	return (result);
	//return (num == (0.0 / 0.0) || num == (-0.0 / 0.0));
	//printf("ROMEU %f", num);
	//return(1);
}

void		conversion_float(t_format *format, va_list ap)
{
	char	*str_integer;
	char	*str_decimal;
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
	else if (isnan(f))
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
		// if (format->precision_size < 0)
		// 	format->precision_size *= -1;
		if ((format->precision == 0 && format->precision_set == 0) || format->precision_size < 0)
		{
			format->precision_set = 1;
			format->precision_size = 6;
		}
		else if (format->precision == 1 && format->precision_set == 0)
		{
			format->precision_size = 1;
		}
		//f = ft_bankersround(format, f);

		temp = ft_longlongtoa((long long)ft_bankersround(format, f));
	
		if (f < 0 || 1 / f <= 0)
		{
			//printf(ANSI_B_RED "NEG %s" ANSI_RESET, temp);
			format->negative_nb = 1;
			str_integer = ft_substr(temp, 1, ft_strlen(temp) - 1);
		}
		else
		{
			//printf(ANSI_B_BGREEN "POS %s" ANSI_RESET, temp);
			if ((long long)f < 0)
				str_integer = ft_substr(temp, 1, ft_strlen(temp) - 1);
			else
				str_integer = ft_strdup(temp);
		}
		if (ft_strequ(temp, "0"))
		{
			free(str_integer);
			str_integer = ft_strdup("0");
		}
		//printf(ANSI_B_BCYAN "%s" ANSI_RESET, str_integer);
		free(temp);
		str_decimal = get_decimalpart(format, f);
		
		if (format->flag_cardinal == 1 && format->precision_size == 1 && format->precision_set == 0)
			temp = ft_strdup(".");
		else if (format->flag_cardinal == 1 && format->precision_set == 1)
			temp = ft_strjoin(".", str_decimal);
		else if (format->precision_set == 0 || format->precision_size == 0)
			temp = ft_strdup("");
		else
		{
			temp = ft_strjoin(".", str_decimal);
		}
		final = ft_strjoin(str_integer, temp);

		print_float(format, final);
		// format->conversion = "decimal";
		// print_string(format, final);
		
		free(str_integer);
		free(str_decimal);
		free(final);
	}
	free(temp);
}
