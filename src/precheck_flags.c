/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precheck_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 02:27:36 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/09 02:29:37 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	precheck_flags(t_format *format, char *str)
{
	if (format->flag_cardinal != 0 && ft_strequ(str, "0") == 0)
		format->precision_size += 2;
	if (format->flag_space == 1 && format->negative_nb == 0)
	{
		if (format->precision == 1 && ft_strequ(str, "0") &&
			ft_strequ(format->conversion, "decimal") &&
			format->precision_size == 0 && format->flag_minus == 1 &&
			format->flag_zero == 1)
			format->width -= 1;
		else
			format->precision_size += 1;
	}
	if (format->flag_plus == 1 && format->negative_nb == 0)
	{
		if (format->precision == 1 && ft_strequ(str, "0") &&
			ft_strequ(format->conversion, "decimal")
		&& format->precision_size == 0)
			format->width -= 1;
		else
			format->precision_size += 1;
	}
}
