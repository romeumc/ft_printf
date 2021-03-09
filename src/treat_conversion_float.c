/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_conversion_float.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:54:47 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/09 12:27:44 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	pre_treat_width(t_format *format, char *str)
{
	if (format->flag_plus == 1)
		treat_width(format, ft_strlen(str) + format->flag_plus);
	else if (format->flag_space == 1)
		treat_width(format, ft_strlen(str) + format->flag_space);
	else
		treat_width(format, ft_strlen(str) + format->negative_nb);
}

void		print_float(t_format *format, char *str)
{
	if (format->flag_minus == 1 || format->neg_width == 1)
	{
		treat_flags(format, str);
		output_putstr(format, str);
		pre_treat_width(format, str);
	}
	else
	{
		if (format->flag_zero == 1)
		{
			treat_flags(format, str);
			pre_treat_width(format, str);
			output_putstr(format, str);
		}
		else
		{
			pre_treat_width(format, str);
			treat_flags(format, str);
			output_putstr(format, str);
		}
	}
}

double		ft_bankersround(t_format *format, double f)
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

static char	*decimal_toa(t_format *format, double f, double decimal)
{
	char	*temp;
	int		i;

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
	return (temp);
}

char		*get_decimalpart(t_format *format, double f)
{
	double	round_inc;
	char	*str_decimal;
	double	decimal;

	decimal = f - (long long)f;
	if (decimal < 0)
		decimal *= -1;
	round_inc = (5.0 / ft_iterative_power_ll(10, format->precision_size + 1));
	decimal += round_inc;
	str_decimal = decimal_toa(format, f, decimal);
	return (str_decimal);
}
