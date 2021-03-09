/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_conversion_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 21:56:23 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/09 02:55:54 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static char	*conversion_hhx(t_format *format, va_list ap, char *type)
{
	int	d;

	d = (char)va_arg(ap, unsigned int);
	if (ft_strequ(type, "lower"))
	{
		if (format->flag_cardinal == 1)
			format->flag_cardinal = 10;
		if (d == -1)
			return (ft_strdup("ff"));
		else
			return (ft_ulonglong_tobase(d, HEX) + 0);
	}
	else
	{
		if (format->flag_cardinal == 1)
			format->flag_cardinal = 20;
		if (d == -1)
			return (ft_strdup("FF"));
		else
			return (ft_ulonglong_tobase(d, HEXCAP) + 0);
	}
}

static char	*conversion_hx(t_format *format, va_list ap, char *type)
{
	unsigned short	d;

	d = (unsigned short)va_arg(ap, unsigned int);
	if (ft_strequ(type, "lower"))
	{
		if (format->flag_cardinal == 1)
			format->flag_cardinal = 10;
		return (ft_ulonglong_tobase(d, HEX));
	}
	else
	{
		if (format->flag_cardinal == 1)
			format->flag_cardinal = 20;
		return (ft_ulonglong_tobase(d, HEXCAP));
	}
}

void		conversion_hex(t_format *format, va_list ap, char *type)
{
	unsigned long long int	d;
	char					*str;

	if (format->modifier_l == 0 && format->modifier_h == 0)
		d = (unsigned long long int)va_arg(ap, unsigned int);
	else if (format->modifier_l == 1 && format->modifier_h == 0)
		d = (unsigned long long int)va_arg(ap, unsigned long int);
	else if (format->modifier_l == 2 && format->modifier_h == 0)
		d = (unsigned long long int)va_arg(ap, unsigned long long int);
	else if (format->modifier_h == 1 && format->modifier_l == 0)
	{
		str = conversion_hx(format, ap, type);
		type = "";
	}
	else if (format->modifier_h == 2 && format->modifier_l == 0)
	{
		str = conversion_hhx(format, ap, type);
		type = "";
	}
	if (ft_strequ(type, "lower"))
	{
		if (format->flag_cardinal == 1)
			format->flag_cardinal = 10;
		str = ft_ulonglong_tobase(d, HEX);
	}
	else if (ft_strequ(type, "upper"))
	{
		if (format->flag_cardinal == 1)
			format->flag_cardinal = 20;
		str = ft_ulong_tobase(d, HEXCAP);
	}
	format->conversion = "decimal";
	print_string(format, str);
	free(str);
}
