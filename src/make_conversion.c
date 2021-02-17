/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:06:29 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/17 17:34:45 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	check_arg_string(char *str)
{
	if (str == NULL)
		return (0);
	if (ft_strlen(str) > 0)
		return (1);
	else
		return (0);
}

int	conversion_string(char ***output, va_list ap)
{
	char	*str;

	
	str = va_arg(ap, char *);
	//printf("ARG:%s \n", str);
	if (check_arg_string(str) == 1)
	{
		//printf(ANSI_F_BWHITE"maloc:%ld | outputlen:%ld | strlen:%ld\t\t\t"ANSI_RESET, malloc_usable_size(**output), ft_strlen(**output), ft_strlen(str));
		**output = ft_realloc(**output, ft_strlen(**output) + ft_strlen(str) + 1);
		if (output == NULL)
			return (0);
		else
			**output = ft_strcat(**output, str);
		//printf(ANSI_F_BWHITE"maloc:%ld | outputlen:%ld | strlen:%ld ==> output:%s\n"ANSI_RESET, malloc_usable_size(**output), ft_strlen(**output), ft_strlen(str), **output);
		return (1);
	}
	else
		return (0);
}

int	conversion_decimal(char ***output, va_list ap)
{
	int		d;
	char	*str;

	d = va_arg(ap, int);
	str = ft_itoa(d);
	//printf(ANSI_F_BWHITE"maloc:%ld | outputlen:%ld | strlen:%ld\t\t\t"ANSI_RESET, malloc_usable_size(**output), ft_strlen(**output), ft_strlen(str));
	**output = ft_realloc(**output, ft_strlen(**output) + ft_strlen(str) + 1);
	if (output == NULL)
		return (-1);
	else
		**output = ft_strcat(**output, str);
	//printf(ANSI_F_BWHITE"maloc:%ld | outputlen:%ld | strlen:%ld ==> output:%s\n"ANSI_RESET, malloc_usable_size(**output), ft_strlen(**output), ft_strlen(str), **output);
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

int	make_conversion(t_format *format, char **output, va_list ap)
{
	if (ft_strequ(format->conversion, "percentage"))
		*output = ft_strdup_join(*output, '%');
	if (ft_strequ(format->conversion, "string"))
		if (conversion_string(&output, ap) == 0)
			return (0);
	if (ft_strequ(format->conversion, "decimal"))
		if (conversion_decimal(&output, ap) == 0)
			return (0);
	if (ft_strequ(format->conversion, "char"))
		if (conversion_char(&output, ap) == 0)
			return (0);
	return (1);
}
