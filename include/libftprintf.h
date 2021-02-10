/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 20:53:46 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/09 18:55:15 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdio.h>
#include "../libft/libft.h"
# include "ft_ansi.h"

typedef struct s_format
{
	char	*conversion;
}	t_format;

int	ft_printf(const char *fmt, ...);
size_t ft_strlen1(char *s);

#endif