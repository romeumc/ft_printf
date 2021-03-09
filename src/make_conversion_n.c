/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_conversion_n.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 23:58:18 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/09 02:37:58 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	conversion_n(t_format *format, va_list ap)
{
	int *ptr;

	ptr = va_arg(ap, void *);
	*ptr = (int)format->output_length;
}

static void	conversion_ln(t_format *format, va_list ap)
{
	long int *ptr;

	ptr = va_arg(ap, void *);
	*ptr = (long int)format->output_length;
}

static void	conversion_lln(t_format *format, va_list ap)
{
	long long int *ptr;

	ptr = va_arg(ap, void *);
	*ptr = (long long int)format->output_length;
}

static void	conversion_hn(t_format *format, va_list ap)
{
	short int	*ptr;

	ptr = va_arg(ap, void *);
	*ptr = (short int)format->output_length;
}

void		conversion_nchars(t_format *format, va_list ap)
{
	if (format->modifier_l == 0 && format->modifier_h == 0)
		conversion_n(format, ap);
	else if (format->modifier_l == 1 && format->modifier_h == 0)
		conversion_ln(format, ap);
	else if (format->modifier_l == 2 && format->modifier_h == 0)
		conversion_lln(format, ap);
	else if (format->modifier_h == 1 && format->modifier_l == 0)
		conversion_hn(format, ap);
	else if (format->modifier_h == 2 && format->modifier_l == 0)
		conversion_hhn(format, ap);
}
