/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_conversion2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:19:36 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/28 16:36:04 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	conversion_string(t_format *format, va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (str == NULL)
	{
		str = "(null)";
	}
	print_string(format, str);
}

void	conversion_int(t_format *format, va_list ap)
{
	long long int		d;
	char	*str;
	char	*temp;

	if (format->modifier_l == 0)
		d = (long long)va_arg(ap, int);
	else if (format->modifier_l == 1)
		d = (long long)va_arg(ap, long int);
	else if (format->modifier_l == 2)
		d = (long long)va_arg(ap, long long int);
	temp = ft_longlongtoa(d);
	if (d < 0)
	{
		format->negative_nb = 1;
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

void	conversion_hex(t_format *format, va_list ap, char *type)
{
	unsigned int	d;
	char			*str;

	d = (unsigned int)va_arg(ap, unsigned int);
	if (ft_strequ(type, "lower"))
	{
		if (format->flag_cardinal == 1)
			format->flag_cardinal = 10;
		str = ft_ulong_tobase(d, HEX);
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
