/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_conversion_f.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 19:42:42 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/02 16:53:28 by rmartins         ###   ########.fr       */
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
	char	*str_decimal;
	char	*str_remainder;
	char	*temp;
	char	*final;

	float	f;
	int		d;
	float	remainer;
	int		i;
	int		dr;

	if (format->precision == 0 && format->precision_set == 0)
		format->precision_size = 6;
	f = (float)va_arg(ap, double);
	d = (int)f;
	str_decimal = ft_itoa(d);
	remainer = f - d;
	if (remainer == 0)
	{
		i = 0;
		while (i < format->precision_size)
		{
			str_remainder[i] = '0';
			i++;
		}
		str_remainder[i] = '\0';
	}
	else
	{
		i = 0;
		while (i < format->precision_size)
		{
			remainer *= 10;
			i++;
		}
		dr = (int)remainer;
		str_remainder = ft_itoa(dr);
	}


	// debub__f____________________________________________________________format(format);
	// printf("float:%f ", f);
	// printf("int:%d ", d);
	// printf("remainer:%f\n", remainer);

	
	temp = ft_strjoin(str_decimal, ".");
	final = ft_strjoin(temp, str_remainder);

	//printf("%s\n", final);
	print_string(format, final);
	
	free(str_decimal);
	free(str_remainder);
	free(temp);
	free(final);
}
