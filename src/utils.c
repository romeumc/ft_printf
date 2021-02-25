/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:51:35 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/25 23:36:28 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	output_putchar(t_format *format, char c)
{
	format->output_lenght++;
	ft_putchar(c);
}

void	output_putstr(t_format *format, char *str)
{
	format->output_lenght += ft_strlen(str);
	ft_putstr(str);
}

void	print_minus_ifnegative(t_format *format)
{
	if (format->negative_nb == 1)
		output_putchar(format, '-');
}

void	print_hex_cardinal(t_format *format, char *str)
{
	if (ft_strequ(str,"0") == 0)
	{
		if (format->flag_cardinal == 10)
		{
			output_putstr(format, "0x");
			//format->precision_size += 2;
		}
		else if (format->flag_cardinal == 20)
		{
			output_putstr(format, "0X");
			//format->precision_size += 2;
		}
	}
}
