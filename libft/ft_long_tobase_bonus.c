/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_tobase_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:12:23 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/23 20:03:16 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** Nesta função estão duas formas de tratar os ponteiros
*/

static void	ft_print_radix(long int nb, char *base, char *result, int *pos)
{
	unsigned int	len_base;
	unsigned long	nbu;

	len_base = ft_strlen(base);
	if (nb < 0)
	{
		nbu = (unsigned long)(nb * -1);
		// result[*pos] = '-';
		// (*pos)++;
	}
	else
		nbu = (unsigned long)nb;
	if (nbu >= len_base)
	{
		ft_print_radix(nbu / len_base, base, result, pos);
		ft_print_radix(nbu % len_base, base, result, pos);
	}
	else
	{
		result[pos[0]] = base[nbu];
		pos[0]++;
	}
}

char		*ft_long_tobase(long int nbr, char *base)
{
	char	*result;
	int		pos;

	pos = 0;
	result = malloc(sizeof(char) * (ft_get_size_inbase(nbr, base) + 1));
	if (result == NULL)
		return (NULL);
	ft_print_radix(nbr, base, result, &pos);
	result[pos] = '\0';
	return (result);
}
