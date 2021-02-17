/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:48:09 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/17 16:55:52 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static char	*get_convertion(char fmt_char)
{
	if (fmt_char == 's')
		return ("string");
	if (fmt_char == 'd')
		return ("decimal");
	if (fmt_char == 'c')
		return ("char");
	if (fmt_char == '%')
		return ("percentage");
	else
		return (NULL);
}

/*
** colocar check para FIELD WITDTH e incrementar se for diferente de null
** colocar check para PRECISION
** colocar check para LENGHT MODIFIER
*/

void		parse_fmt(size_t *i, const char *fmt, t_format *format)
{
	*i += 1;
	//printf(ANSI_F_CYAN " width: %d " ANSI_RESET, format->field_width);
	while (ft_isdigit(fmt[*i]))
	{
		//printf(ANSI_F_RED " fmt[i]:%c %d " ANSI_RESET, fmt[*i], fmt[*i] - '0');
		format->field_width = format->field_width * 10 + (fmt[*i] - '0');
		*i += 1;
	}
	//printf(ANSI_F_CYAN " width: %d " ANSI_RESET, format->field_width);
	format->conversion = get_convertion(fmt[*i]);
}
