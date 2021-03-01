/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_conversion_f.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 19:42:42 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/01 00:21:05 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	debub__f____________________________________________________________format(t_format *format)
{
	printf(ANSI_B_BBLUE "width:[%d]" ANSI_RESET " ", format->width);
	printf(ANSI_B_BBLUE "zero:[%d]" ANSI_RESET " ", format->flag_zero);
	printf(ANSI_B_BBLUE "precision:[%d]" ANSI_RESET " ", format->precision);
	printf(ANSI_B_BBLUE "precision_size:[%d]" ANSI_RESET " ", format->precision_size);
	printf(ANSI_B_BBLUE "minus:[%d]" ANSI_RESET " ", format->flag_minus);
	printf(ANSI_B_BBLUE "neg_precision:[%d]" ANSI_RESET " ", format->neg_precision);
	printf(ANSI_B_BBLUE "neg_width:[%d]" ANSI_RESET " ", format->neg_width);
	printf(ANSI_B_BBLUE "negative_nb:[%d]" ANSI_RESET " ", format->negative_nb);
	// printf(ANSI_B_BBLUE "sharp:[%d]" ANSI_RESET " ", format->flag_cardinal);
	// printf(ANSI_B_BBLUE "space:[%d]" ANSI_RESET " ", format->flag_space);
	// printf(ANSI_B_BBLUE "plus:[%d]" ANSI_RESET " ", format->flag_plus);
}

void		conversion_float(t_format *format, va_list ap)
{
	// char	*str;
	// char	*temp;
	float	f;
	int		d;
	float	remainer;

	f = (float)va_arg(ap, double);
	d = (int)f;
	remainer = f - d;

	debub__f____________________________________________________________format(format);
	printf("float:%f ", f);
	printf("int:%d ", d);
	printf("remainer:%f\n", remainer);
	if (format->negative_nb == 1)
	{
		printf("a");
	}

	// 	str = ft_substr(temp, 1, ft_strlen(temp) - 1);
	// }
	// else
	// {
	// 		str = ft_strdup(temp);
	// }
	// free(temp);
	// print_string(format, str);
	// free(str);
}
