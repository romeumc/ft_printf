/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_conversion_f.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 19:42:42 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/09 02:12:11 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "../include/ft_printf.h"

void	print_float(t_format *format, char *str)
{
	if (format->flag_minus == 1 || format->neg_width == 1)
	{
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
			if (format->flag_plus == 1)
				treat_width(format, ft_strlen(str) + format->flag_plus);
			else if (format->flag_space == 1)
				treat_width(format, ft_strlen(str) + format->flag_space);
			else
				treat_width(format, ft_strlen(str) + format->negative_nb);
			treat_flags(format, str);
			output_putstr(format, str);
		}
	}
}

double	ft_bankersround(t_format *format, double f)
{
	double		round_inc;
	double		decimal;
	long long	integer;

	integer = (long long)f;
	decimal = f - (long long)f;
	if (decimal < 0)
		decimal *= -1;
	round_inc = (5.0 / ft_iterative_power_ll(10, format->precision_size + 1));
	if (decimal != 0)
	{
		if (decimal - round_inc != 0 || integer % 2 != 0)
		{
			if (f < 0)
				f -= round_inc;
			else
				f += round_inc;
		}
	}
	return (f);
}

char	*get_decimalpart(t_format *format, double f)
{
	double	round_inc;
	char	*str_decimal;
	char	*temp;
	int		i;
	double	decimal;

	decimal = f - (long long)f;
	if (decimal < 0)
		decimal *= -1;
	round_inc = (5.0 / ft_iterative_power_ll(10, format->precision_size + 1));
	decimal += round_inc;
	i = 0;
	temp = malloc(sizeof(char) * (format->precision_size + 1));
	if (temp != NULL)
	{
		while (i < format->precision_size)
		{
			if (f == (long long)f)
				decimal = 0;
			else
				decimal = decimal * 10 - ((int)decimal * 10);
			temp[i] = ((int)decimal) + '0';
			i++;
		}
		temp[i] = '\0';
	}
	str_decimal = ft_strdup(temp);
	free(temp);
	return (str_decimal);
}

int		isnan(double num)
{
	int result;

	result = 0;
	if (num == (0.0 / 0.0))
		result = 1;
	else if (num == (-0.0 / 0.0))
		result = -1;
	return (result);
}

void	conversion_float(t_format *format, va_list ap)
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
		if ((format->precision == 0 && format->precision_set == 0) || format->precision_size < 0)
		{
			format->precision_set = 1;
			format->precision_size = 6;
		}
		else if (format->precision == 1 && format->precision_set == 0)
		{
			format->precision_size = 1;
		}
		temp = ft_longlongtoa((long long)ft_bankersround(format, f));
		if (f < 0 || 1 / f <= 0)
		{
			format->negative_nb = 1;
			str_integer = ft_substr(temp, 1, ft_strlen(temp) - 1);
		}
		else
		{
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
		free(temp);
		str_decimal = get_decimalpart(format, f);
		if (format->flag_cardinal == 1 && format->precision_size == 1 && format->precision_set == 0)
			temp = ft_strdup(".");
		else if (format->flag_cardinal == 1 && format->precision_set == 1)
			temp = ft_strjoin(".", str_decimal);
		else if (format->precision_set == 0 || format->precision_size == 0)
			temp = ft_strdup("");
		else
			temp = ft_strjoin(".", str_decimal);
		final = ft_strjoin(str_integer, temp);
		print_float(format, final);
		free(str_integer);
		free(str_decimal);
		free(final);
	}
	free(temp);
}
