/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 20:53:46 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/18 01:37:45 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "ft_ansi.h"
# include <malloc.h>

# define FLAGS "-0# +"
# define WIDTH "*1234567890"
# define PRECISION ".*1234567890"

typedef struct	s_format
{
	char	*conversion;
	int		field_width;
	size_t	output_lenght;
	int		flag_minus;
	int		flag_zero;
	int		flag_cardinal;
	int		flag_space;
	int		flag_plus;
	int		precision;
	int		precision_size;
}				t_format;

int				ft_printf(const char *fmt, ...);
void			parse_fmt(size_t *i, const char *fmt, t_format *format, va_list ap);
void			make_conversion(t_format *format, va_list ap);

#endif
