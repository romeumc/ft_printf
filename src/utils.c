/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:51:35 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/25 18:53:48 by rmartins         ###   ########.fr       */
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
