/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlongtoa_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 23:21:30 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/27 22:57:24 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(long long number)
{
	int	i;

	if (number <= 0)
		i = 1;
	else
		i = 0;
	while (number != 0)
	{
		number /= 10;
		i++;
	}
	return (i);
}

static void	ft_putnbr_str(long long nb, char *str, int len)
{
	int	sign;

	if (nb < 0)
		str[0] = '-';
	while (nb != 0)
	{
		len--;
		if (nb < 0)
			sign = -1;
		else
			sign = 1;
		str[len] = sign * (nb % 10) + '0';
		nb /= 10;
	}
}

char		*ft_longlongtoa(long long n)
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
