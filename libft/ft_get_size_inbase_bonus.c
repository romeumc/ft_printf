/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size_inbase_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 00:30:15 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/22 00:45:17 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_size_inbase(long number, char *base)
{
	size_t	lenbase;
	int		counter;

	counter = 1;
	lenbase = ft_strlen(base);
	while (number >= (long)lenbase)
	{
		number /= lenbase;
		counter++;
	}
	return (counter);
}
