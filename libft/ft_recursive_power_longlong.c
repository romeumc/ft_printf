/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power_longlong.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 13:46:15 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/03 16:30:41 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	ft_recursive_power_ll(unsigned long long nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
	{
		return (nb * ft_recursive_power(nb, power - 1));
	}
}
