/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:48:09 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/10 16:19:59 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

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

	// colocar check para FIELD WITDTH e incrementar se for diferente de null
	// colocar check para PRECISION
	// colocar check para LENGHT MODIFIER

void	parse_fmt(size_t *i, const char *fmt, t_format *format)
{
	*i += 1;
	format->conversion = get_convertion(fmt[*i]);
}
