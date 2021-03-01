/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_conversion_d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 19:42:42 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/28 23:49:55 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static char	*conversion_d(t_format *format, va_list ap)
{
	int	d;

	d = va_arg(ap, int);
	if (d < 0)
		format->negative_nb = 1;
	return (ft_itoa(d));
}

static char	*conversion_ld(t_format *format, va_list ap)
{
	long int	d;

	d = (long int)va_arg(ap, long int);
	if (d < 0)
		format->negative_nb = 1;
	return (ft_longtoa(d));
}

static char	*conversion_lld(t_format *format, va_list ap)
{
	long long int	d;

	d = (long long int)va_arg(ap, long long int);
	if (d < 0)
		format->negative_nb = 1;
	return (ft_longlongtoa(d));
}

static char	*conversion_hd(t_format *format, va_list ap)
{
	short	d;

	d = (short)va_arg(ap, int);
	if (d < 0)
		format->negative_nb = 1;
	return (ft_itoa(d));
}

static char	*conversion_hhd(t_format *format, va_list ap)
{
	int	d;

	d = (char)va_arg(ap, int);
	if (d < 0)
		format->negative_nb = 1;
	return (ft_itoa(d + 0));
}

void		conversion_int(t_format *format, va_list ap)
{
	char	*str;
	char	*temp;

	if (format->modifier_l == 0 && format->modifier_h == 0)
		temp = conversion_d(format, ap);
	else if (format->modifier_l == 1 && format->modifier_h == 0)
		temp = conversion_ld(format, ap);
	else if (format->modifier_l == 2 && format->modifier_h == 0)
		temp = conversion_lld(format, ap);
	else if (format->modifier_h == 1 && format->modifier_l == 0)
		temp = conversion_hd(format, ap);
	else if (format->modifier_h == 2 && format->modifier_l == 0)
		temp = conversion_hhd(format, ap);
	if (format->negative_nb == 1)
	{
		str = ft_substr(temp, 1, ft_strlen(temp) - 1);
	}
	else
	{
			str = ft_strdup(temp);
	}
	free(temp);
	print_string(format, str);
	free(str);
}
