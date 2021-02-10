/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:06:29 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/10 16:56:38 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

int	conversion_string(char ***output, va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	//printf(ANSI_F_BWHITE"maloc:%ld | outputlen:%ld | strlen:%ld\t\t\t"ANSI_RESET, malloc_usable_size(**output), ft_strlen(**output), ft_strlen(str));
	**output = ft_strcat(**output, str);
	//pr intf(ANSI_F_BWHITE"maloc:%ld | outputlen:%ld | strlen:%ld"ANSI_RESET, malloc_usable_size(**output), ft_strlen(**output), ft_strlen(str));
	return (1);
}

int	conversion_decimal(char ***output, va_list ap)
{
	int		d;
	char	*str;

	d = va_arg(ap, int);
	str = ft_itoa(d);
	**output = ft_strcat(**output, str);
	free(str);
	return (1);
}

int	conversion_char(char ***output, va_list ap)
{
	char c;

	c = (char)va_arg(ap, int);
	**output = ft_strdup_join(**output, c);
	return (1);
}

void	make_conversion(t_format *format, char **output, va_list ap)
{
	if (ft_strequ(format->conversion, "percentage"))
		*output = ft_strdup_join(*output, '%');
	if (ft_strequ(format->conversion, "string"))
		conversion_string(&output, ap);
	if (ft_strequ(format->conversion, "decimal"))
		conversion_decimal(&output, ap);
	if (ft_strequ(format->conversion, "char"))
		conversion_char(&output, ap);
}
