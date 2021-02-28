/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_conversion_u.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 16:33:58 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/28 17:00:48 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	conversion_u(t_format *format, va_list ap)
{
	unsigned int	d;
	char			*str;

	d = (unsigned int)va_arg(ap, unsigned int);
	if (d == 0)
		str = ft_strdup("0");
	else
		str = ft_utoa(d);
	format->conversion = "decimal";
	print_string(format, str);
	free(str);
}

static void	conversion_ul(t_format *format, va_list ap)
{
	unsigned long int	d;
	char				*str;

	d = (unsigned long int)va_arg(ap, unsigned long int);
	if (d == 0)
		str = ft_strdup("0");
	else
		str = ft_ulongtoa(d);
	format->conversion = "decimal";
	print_string(format, str);
	free(str);
}

static void	conversion_ull(t_format *format, va_list ap)
{
	unsigned long long int	d;
	char					*str;

	d = (unsigned long long int)va_arg(ap, unsigned long long int);
	if (d == 0)
		str = ft_strdup("0");
	else
		str = ft_ulonglongtoa(d);
	format->conversion = "decimal";
	print_string(format, str);
	free(str);
}

void	conversion_unsigned_int(t_format *format, va_list ap)
{
		if (format->modifier_l == 0)
		conversion_u(format, ap);
	else if (format->modifier_l == 1)
		conversion_ul(format, ap);
	else if (format->modifier_l == 2)
		conversion_ull(format, ap);
}