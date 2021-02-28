/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulong_tobase_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:12:23 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/27 22:38:42 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_radix(unsigned long nb, char *base, char *result, int *pos)
{
	unsigned int	len_base;

	len_base = ft_strlen(base);
	if (nb >= len_base)
	{
		ft_print_radix(nb / len_base, base, result, pos);
		ft_print_radix(nb % len_base, base, result, pos);
	}
	else
	{
		result[pos[0]] = base[nb];
		pos[0]++;
	}
}

char		*ft_ulong_tobase(unsigned long int nbr, char *base)
{
	char	*result;
	int		pos;

	pos = 0;
	result = malloc(sizeof(char) * (ft_getsize_ulonginbase(nbr, base) + 1));
	if (result == NULL)
		return (NULL);
	ft_print_radix(nbr, base, result, &pos);
	result[pos] = '\0';
	return (result);
}
