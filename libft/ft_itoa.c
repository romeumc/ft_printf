/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 23:21:30 by rmartins          #+#    #+#             */
/*   Updated: 2021/01/16 18:43:24 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int number)
{
	int i;

	i = (number <= 0) ? 1 : 0;
	while (number != 0)
	{
		number /= 10;
		i++;
	}
	return (i);
}

static void	ft_putnbr_str(int nb, char *str, int len)
{
	if (nb < 0)
		str[0] = '-';
	while (nb != 0)
	{
		len--;
		str[len] = '0' + ((nb < 0) ? -1 : 1) * (nb % 10);
		nb /= 10;
	}
}

char		*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = get_size(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	ft_putnbr_str(n, str, len);
	str[len] = '\0';
	return (str);
}
