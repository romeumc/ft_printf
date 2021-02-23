/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size_inbase_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 00:30:15 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/23 20:03:24 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_size_inbase(long nb, char *base)
{
	size_t			lenbase;
	int				counter;
	unsigned long	nbu;

	counter = 1;
	if (nb < 0)
	{
		//counter++;
		nbu = (unsigned long)(nb * -1);
	}
	else
		nbu = (unsigned long)nb;
	lenbase = ft_strlen(base);
	while (nbu >= (unsigned long)lenbase)
	{
		nbu /= lenbase;
		counter++;
	}
	return (counter);
}
