/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_conversion_f.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 19:42:42 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/09 18:28:14 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		check_float_precision(t_format *format)
{
	if ((format->precision == 0 && format->precision_set == 0) ||
		format->precision_size < 0)
	{
		format->precision_set = 1;
		format->precision_size = 6;
	}
	else if (format->precision == 1 && format->precision_set == 0)
	{
		format->precision_size = 1;
	}
}

static char	*get_round_integer(t_format *format, double f)
{
	char	*temp;
	int		integer;

	temp = ft_longlongtoa((long long)ft_bankersround(format, f));
	if (ft_strequ(format->conversion, "engineer"))
	{
		integer = ft_atoi(temp);
		if (integer <= -10 || integer >= 10)
		{
			integer /= 10;
			format->exp_counter++;
			free(temp);
			temp = ft_itoa(integer);
		}
	}
	return (temp);
}

char		*get_integer_fromfloat(t_format *format, double f)
{
	char	*str_integer;
	char	*temp;

	temp = get_round_integer(format, f);
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
	return (str_integer);
}

char		*get_str_decimal(t_format *format, double f)
{
	char	*str_decimal;
	char	*temp;

	temp = get_decimalpart(format, f);
	if (format->flag_cardinal == 1 && format->precision_size == 1 &&
		format->precision_set == 0)
		str_decimal = ft_strdup(".");
	else if (format->flag_cardinal == 1 && format->precision_set == 1)
		str_decimal = ft_strjoin(".", temp);
	else if (format->precision_set == 0 || format->precision_size == 0)
		str_decimal = ft_strdup("");
	else
		str_decimal = ft_strjoin(".", temp);
	free(temp);
	return (str_decimal);
}

void		conversion_float(t_format *format, va_list ap)
{
	char	*str_integer;
	char	*temp;
	char	*final;
	double	f;

	f = va_arg(ap, double);
	if (ft_isinf(f))
	{
		if (f < 0)
			format->negative_nb = 1;
		format->flag_zero = 0;
		final = ft_strdup("inf");
	}
	else
	{
		check_float_precision(format);
		str_integer = get_integer_fromfloat(format, f);
		temp = get_str_decimal(format, f);
		final = ft_strjoin(str_integer, temp);
		free(str_integer);
		free(temp);
	}
	print_float(format, final);
	free(final);
}
