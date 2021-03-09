/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_conversion_string_zero.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 12:32:45 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/09 12:35:18 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	print_string_zero(t_format *format, char *str)
{
	if (format->flag_minus == 1)
	{
		precheck_flags(format, str);
		treat_flags(format, str);
		format->flag_minus = 1;
		treat_width(format, ft_strlen(str) - format->flag_minus);
	}
	else
	{
		precheck_flags(format, str);
		format->flag_minus = 1;
		treat_width(format, ft_strlen(str) - format->flag_minus);
		treat_flags(format, str);
	}
}
