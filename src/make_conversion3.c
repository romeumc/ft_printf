/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_conversion3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 23:58:18 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/28 00:09:01 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	conversion_n(t_format *format, va_list ap)
{
	int *ptr;

	ptr = va_arg(ap, void *);
	*ptr = (int)format->output_lenght;
}

static void	conversion_nl(t_format *format, va_list ap)
{
	long int *ptr;

	ptr = va_arg(ap, void *);
	*ptr = (long int)format->output_lenght;
}

static void	conversion_nll(t_format *format, va_list ap)
{
	long long int *ptr;

	ptr = va_arg(ap, void *);
	*ptr = (long long int)format->output_lenght;
}


void	conversion_n_chars(t_format *format, va_list ap)
{
	if (format->modifier_l == 0)
		conversion_n(format, ap);
	else if (format->modifier_l == 1)
		conversion_nl(format, ap);
	else if (format->modifier_l == 2)
		conversion_nll(format, ap);
}