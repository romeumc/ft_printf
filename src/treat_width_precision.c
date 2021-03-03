/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_width_precision.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:41:06 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/02 23:28:14 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	debub___wp__________________________________________________________format(t_format *format)
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


void	treat_width(t_format *format, size_t len)
{
	int		i;
	char	c;

	i = 0;
	c = ' ';
	if (format->flag_zero == 1 && format->flag_minus == 0)
		c = '0';
	if (format->neg_width == 1)
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

	//debub___wp__________________________________________________________format(format);
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
		&& format->flag_zero == 1 && format->neg_width == 0)
		c = '0';
	while (len > 0)
	{
		output_putchar(format, c);
		len--;
	}
}
