/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_conversion_f.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 19:42:42 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/09 13:18:45 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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
