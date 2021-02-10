/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 20:53:46 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/10 16:10:12 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "ft_ansi.h"
# include <malloc.h>

typedef struct s_format
{
	char	*conversion;
}	t_format;

int		ft_printf(const char *fmt, ...);
void	parse_fmt(size_t *i, const char *fmt, t_format *format);
void	make_conversion(t_format *format, char **output, va_list ap);

#endif