/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_conversion_n.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 23:58:18 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/06 17:53:34 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	conversion_n(t_format *format, va_list ap)
{
	int *ptr;

	ptr = va_arg(ap, void *);
	*ptr = (int)format->output_lenght;
}

static void	conversion_ln(t_format *format, va_list ap)
{
	long int *ptr;

	ptr = va_arg(ap, void *);
	*ptr = (long int)format->output_lenght;
}

static void	conversion_lln(t_format *format, va_list ap)
{
	long long int *ptr;

	ptr = va_arg(ap, void *);
	*ptr = (long long int)format->output_lenght;
}

static void	conversion_hn(t_format *format, va_list ap)
{
	short int	*ptr;

	ptr = va_arg(ap, void *);
	*ptr = (short int)format->output_lenght;
}

static void	conversion_hhn(t_format *format, va_list ap)
{
	char	*ptr;

	ptr = va_arg(ap, void *);
	*ptr = (char)format->output_lenght;
}

void		conversion_nchars(t_format *format, va_list ap)
{
	if (format->modifier_l == 0)
		conversion_n(format, ap);
	else if (format->modifier_l == 1)
		conversion_ln(format, ap);
	else if (format->modifier_l == 2)
		conversion_lln(format, ap);
	else if (format->modifier_h == 1)
		conversion_hn(format, ap);
	else if (format->modifier_h == 2)
		conversion_hhn(format, ap);
}
