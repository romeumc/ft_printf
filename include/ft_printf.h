/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 20:53:46 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/17 15:25:59 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "ft_ansi.h"
# include <malloc.h>

typedef struct	s_format
{
	char	*conversion;
	int		field_width;
}				t_format;

int				ft_printf(const char *fmt, ...);
void			parse_fmt(size_t *i, const char *fmt, t_format *format);
int				make_conversion(t_format *format, char **output, va_list ap);

#endif
