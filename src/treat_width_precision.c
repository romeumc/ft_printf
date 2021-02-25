/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_width_precision.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:41:06 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/25 19:03:58 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	treat_width(t_format *format, size_t len)
{
	int		i;
	char	c;

	i = 0;
	c = ' ';
	if (format->flag_zero == 1 && format->flag_minus == 0)
		c = '0';
	if (format->negative_width == 1)
		c = ' ';
	while (i < format->width - (int)len)
	{
		output_putchar(format, c);
		i++;
	}
}

void	treat_precision_decimal(t_format *format, size_t len)
{
	int		i;
	char	c;

	i = 0;
	c = '0';
	while (i < format->precision_size - (int)len)
	{
		output_putchar(format, c);
		i++;
	}
}

void	treat_width_decimal(t_format *format, int len)
{
	char	c;

	c = ' ';
	if (format->neg_precision == 1 && format->flag_minus == 0
		&& format->flag_zero == 1 && format->negative_width == 0)
		c = '0';
	while (len > 0)
	{
		output_putchar(format, c);
		len--;
	}
}
