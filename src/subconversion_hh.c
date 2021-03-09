/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subconversion_hh.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 02:37:04 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/09 02:44:35 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	conversion_uhh(t_format *format, va_list ap)
{
	int				d;
	char			*str;

	d = (char)va_arg(ap, unsigned int);
	if (d == 0)
		str = ft_strdup("0");
	else if (d == -1)
		str = ft_strdup("255");
	else
		str = ft_itoa(d + 0);
	print_string(format, str);
	free(str);
}

void	conversion_hhn(t_format *format, va_list ap)
{
	char	*ptr;

	ptr = va_arg(ap, void *);
	*ptr = (char)format->output_length;
}

char	*conversion_hhd(t_format *format, va_list ap)
{
	int	d;

	d = (char)va_arg(ap, int);
	if (d < 0)
		format->negative_nb = 1;
	return (ft_itoa(d + 0));
}
