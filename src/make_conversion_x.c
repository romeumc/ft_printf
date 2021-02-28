/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_conversion_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 21:56:23 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/28 21:56:41 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	conversion_hex(t_format *format, va_list ap, char *type)
{
	unsigned long long int	d;
	char			*str;

	if (format->modifier_l == 0)
		d = (unsigned long long int)va_arg(ap, unsigned int);
	else if (format->modifier_l == 1)
		d = (unsigned long long int)va_arg(ap, unsigned long int);
	else if (format->modifier_l == 2)
		d = (unsigned long long int)va_arg(ap, unsigned long long int);
	if (ft_strequ(type, "lower"))
	{
		if (format->flag_cardinal == 1)
			format->flag_cardinal = 10;
		str = ft_ulonglong_tobase(d, HEX);
	}
	else
	{
		if (format->flag_cardinal == 1)
			format->flag_cardinal = 20; 
		str = ft_ulong_tobase(d, HEXCAP);
	}
	format->conversion = "decimal";
	print_string(format, str);
	free(str);
}