/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_base_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:12:23 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/19 14:32:07 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_long_base(long int nbr, char *base)
{
	size_t	len_base;

	len_base = ft_strlen(base);
	if (nbr < 0)
	{
		nbr *= -1;
	}
	if (nbr >= (int)len_base)
	{
		ft_long_base(nbr / len_base, base);
		ft_long_base(nbr % len_base, base);
	}
	else
	{
		ft_putchar(base[nbr]);
	}
}
