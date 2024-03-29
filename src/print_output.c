/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:51:35 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/09 13:11:34 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	output_putchar(t_format *format, char c)
{
	format->output_length++;
	ft_putchar(c);
}

void	output_putstr(t_format *format, char *str)
{
	format->output_length += ft_strlen(str);
	ft_putstr(str);
}

void	output_putnstr(t_format *format, char *str, int output_len)
{
	format->output_length += output_len;
	ft_putnstr(str, format->precision_size);
}
