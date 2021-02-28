/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 20:53:46 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/28 20:06:46 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "ft_ansi.h"

# ifdef __unix__
#  include <malloc.h>
# endif
# ifdef __APPLE__
#  include <stdlib.h>
#  include <malloc/malloc.h>
# endif

# define FLAGS "-0# +"
# define WIDTH "*1234567890"
# define PRECISION ".*1234567890"
# define NULLSTR "0x0"
# define PREFIXHEX "0x"
# define HEX "0123456789abcdef"
# define HEXCAP "0123456789ABCDEF"
# define LENGHTMODIFIER "lh"

typedef struct	s_format
{
	char	*conversion;
	int		width;
	int		neg_width;
	int		flag_minus;
	int		flag_zero;
	int		flag_cardinal;
	int		flag_space;
	int		flag_plus;
	int		precision;
	int		precision_size;
	int		neg_precision;
	int		negative_nb;
	int		modifier_l;
	int		modifier_h;
	size_t	output_lenght;
	char	*output;
}				t_format;

int				ft_printf(const char *fmt, ...);
void			parse_fmt(size_t *i, const char *fmt,
							t_format *format, va_list ap);
void			make_conversion(t_format *format, va_list ap);
void			output_putchar(t_format *format, char c);
void			output_putstr(t_format *format, char *str);
void			output_putnstr(t_format *format, char *str, int output_len);
void			print_string(t_format *format, char *str);
void			conversion_string(t_format *format, va_list ap);
void			conversion_int(t_format *format, va_list ap);
void			conversion_unsigned_int(t_format *format, va_list ap);
void			conversion_hex(t_format *format, va_list ap, char *type);
void			treat_width(t_format *format, size_t len);
void			treat_precision_decimal(t_format *format, size_t len);
void			treat_width_decimal(t_format *format, int len);
void			print_hex_cardinal(t_format *format, char *str);
void			treat_flags(t_format *format, char *str);
void			precheck_flags(t_format *format, char *str);
void			conversion_n_chars(t_format *format, va_list ap);
void			conversion_unsigned_int(t_format *format, va_list ap);

#endif
