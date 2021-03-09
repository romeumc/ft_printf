/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_conversion_e.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 19:42:42 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/09 13:08:56 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	isnan(double num)
{
	int result;

	result = 0;
	if (num == (0.0 / 0.0))
		result = 1;
	else if (num == (-0.0 / 0.0))
		result = -1;
	return (result);
}

char	*get_exponent(int i)
{
	char	*exp;
	char	*e_sign;
	char	*counter;

	if (i < 0)
	{
		i *= -1;
		if (i < 10)
			e_sign = "e-0";
		else
			e_sign = "e-";
	}
	else
	{
		if (i < 10)
			e_sign = "e+0";
		else
			e_sign = "e+";
	}
	counter = ft_itoa(i);
	exp = ft_strjoin(e_sign, counter);
	free(counter);
	return (exp);
}

int		reduce_tounit(double *f, int i)
{
	if (*f != 0)
	{
		while (*f > -1 || *f < 1)
		{
			*f *= 10;
			i--;
			if (*f <= -10.0 || *f >= 10.0)
			{
				*f /= 10;
				i++;
				break ;
			}
		}
		while (*f <= -10.0 || *f >= 10.0)
		{
			*f /= 10;
			i++;
		}
	}
	return (i);
}

void		conversion_engenier(t_format *format, va_list ap)
{
	char	*str_integer;
	char	*str_decimal;
	char	*temp;
	char	*temp1;
	char	*temp2;
	char	*final;
	double	f;
	int		i;
	int		integer;

	f = (double)va_arg(ap, double);
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
		i = reduce_tounit(&f, 0);
		if ((format->precision == 0 && format->precision_set == 0) || format->precision_size < 0)
		{
			format->precision_set = 1;
			format->precision_size = 6;
		}
		else if (format->precision == 1 && format->precision_set == 0)
			format->precision_size = 1;

		temp1 = ft_longlongtoa((long long)ft_bankersround(format, f));
		integer = ft_atoi(temp1);
		if (integer <= -10 || integer >= 10)
		{
			integer /= 10;
			i++;
			free(temp1);
			temp1 = ft_itoa(integer);
		}
		if (f < 0 || 1 / f <= 0)
		{
			format->negative_nb = 1;
			str_integer = ft_substr(temp1, 1, ft_strlen(temp1) - 1);
		}
		else
		{
			if ((long long)f < 0)
				str_integer = ft_substr(temp1, 1, ft_strlen(temp1) - 1);
			else
				str_integer = ft_strdup(temp1);
		}
		if (ft_strequ(temp1, "0"))
		{
			free(str_integer);
			str_integer = ft_strdup("0");
		}
		free(temp1);
		str_decimal = get_decimalpart(format, f);
		
		if (format->flag_cardinal == 1 && format->precision_size == 1 && format->precision_set == 0)
			temp1 = ft_strdup(".");
		else if (format->flag_cardinal == 1 && format->precision_set == 1)
			temp1 = ft_strjoin(".", str_decimal);
		else if (format->precision_set == 0 || format->precision_size == 0)
			temp1 = ft_strdup("");
		else
		{
			temp1 = ft_strjoin(".", str_decimal);
		}
		temp2 = get_exponent(i);
		temp = ft_strjoin(temp1, temp2);
		final = ft_strjoin(str_integer, temp);

		print_float(format, final);
		free(temp1);
		free(temp2);
		free(str_integer);
		free(str_decimal);
		free(final);
	}
	free(temp);
}
