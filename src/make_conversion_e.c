/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_conversion_e.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 19:42:42 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/09 18:41:21 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static char	*get_exponent(int i)
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

static int	reduce_tounit(double *f, int i)
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

static char	*final_str_engineer(t_format *format, double f)
{
	char	*str_integer;
	char	*temp;
	char	*temp1;
	char	*temp2;
	char	*final;

	str_integer = get_integer_fromfloat(format, f);
	temp1 = get_str_decimal(format, f);
	temp2 = get_exponent(format->exp_counter);
	temp = ft_strjoin(temp1, temp2);
	final = ft_strjoin(str_integer, temp);
	free(temp);
	free(temp1);
	free(temp2);
	free(str_integer);
	return (final);
}

void		conversion_engineer(t_format *format, va_list ap)
{
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
		format->exp_counter = reduce_tounit(&f, 0);
		check_float_precision(format);
		final = final_str_engineer(format, f);
	}
	print_float(format, final);
	free(final);
}
