/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:51:35 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/26 16:35:31 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	output_putchar(t_format *format, char c)
{
	format->output_lenght++;
	ft_putchar(c);
}

void	output_putstr(t_format *format, char *str)
{
	format->output_lenght += ft_strlen(str);
	ft_putstr(str);
}

void	output_putnstr(t_format *format, char *str, int output_len)
{
	format->output_lenght += output_len;
	ft_putnstr(str, format->precision_size);
}



// void	output_putchar(t_format *format, char c)
// {
// 	char	*temp;

// 	temp = ft_strdup(format->output);
// 	format->output = ft_strdup_join(temp, c);
// 	free(temp);
// }

// void	output_putstr(t_format *format, char *str)
// {
// 	char	*temp;

// 	temp = ft_strdup(format->output);
// 	printf("temp:%s | %ld   temp1:%s | %ld\n", temp, ft_strlen(temp), str, ft_strlen(str));
// 	//format->output = ft_strjoin(temp, str);
// 	format->output = ft_strcat(temp, str);
// 	free(temp);
// 	printf("output:%s | %ld ==> %ld\n", format->output, ft_strlen(format->output), malloc_usable_size(format->output));
// }

// void	output_putnstr(t_format *format, char *str, int output_len)
// {
// 	char	*temp;
// 	char	*temp1;

// 	temp1 = ft_substr(str, 0, format->precision_size);
// 	temp = ft_strdup(format->output);
// 	printf("temp:%s | %ld \t\t\t temp1:%s | %ld", temp, ft_strlen(temp), temp1, ft_strlen(temp1));
// 	format->output = ft_strjoin(temp, temp1);

// 	format->output_lenght += output_len;
// 	free(temp);
// }
 