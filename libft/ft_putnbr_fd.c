/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 20:34:04 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/06 01:31:08 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_bonus(long nb, int fd)
{
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar_fd('-', fd);
	}
	if (nb >= 10)
	{
		ft_putnbr_bonus(nb / 10, fd);
		ft_putnbr_bonus(nb % 10, fd);
	}
	else
		ft_putchar_fd(nb + '0', fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	ft_putnbr_bonus(n, fd);
}
