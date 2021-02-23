/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_tobase_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:12:23 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/23 14:18:25 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nesta função estão duas formas de tratar os ponteiros
*/

static void	ft_print_radix(long int nbr, char *base, char *result, int *pos)
{
	int	len_base;

	len_base = ft_strlen(base);
	if (nbr < 0)
	{
		len_base *= -1;
		//nbr *= -1;
		result[*pos] = '-';
		(*pos)++;
	}
	if (nbr >= len_base)
	{
		ft_print_radix(nbr / len_base, base, result, pos);
		ft_print_radix(nbr % len_base, base, result, pos);
	}
	else
	{
		result[pos[0]] = base[nbr];
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
