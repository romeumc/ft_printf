/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 20:53:46 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/24 13:39:02 by rmartins         ###   ########.fr       */
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

typedef struct	s_format
{
	char	*conversion;
	int		field_width;
	int		negative_width;		//1 ou 0
	size_t	output_lenght;
	int		flag_minus;
	int		flag_zero;
	int		flag_cardinal;
	int		flag_space;
	int		flag_plus;
	int		precision;
	int		precision_size;
	int		negative_precision;
	int		negative;	//quando o numero é negativo (para colocar o sinal -)
}				t_format;

int				ft_printf(const char *fmt, ...);
void			parse_fmt(size_t *i, const char *fmt, t_format *format, va_list ap);
void			make_conversion(t_format *format, va_list ap);

#endif
