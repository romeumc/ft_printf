/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_conversion2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:19:36 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/25 19:25:32 by rmartins         ###   ########.fr       */
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
	int		d;
	char	*str;
	char	*temp;

	d = va_arg(ap, int);
	temp = ft_itoa(d);
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

void	conversion_unsigned_int(t_format *format, va_list ap)
{
	unsigned int	d;
	char			*str;

	d = (unsigned int)va_arg(ap, int);
	str = ft_longtoa(d);
	format->conversion = "decimal";
	print_string(format, str);
	free(str);
}

void	conversion_hex(t_format *format, va_list ap, char *type)
{
	unsigned int	d;
	char			*str;

	d = (unsigned int)va_arg(ap, int);
	if (ft_strequ(type, "lower"))
	{
		str = ft_ulong_tobase(d, HEX);
	}
	else
	{
		str = ft_ulong_tobase(d, HEXCAP);
	}
	format->conversion = "decimal";
	print_string(format, str);
	free(str);
}
