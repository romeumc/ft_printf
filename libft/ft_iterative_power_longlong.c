/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power_longlong.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 10:05:37 by rmartins          #+#    #+#             */
/*   Updated: 2021/03/03 16:39:51 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	ft_iterative_power_ll(unsigned long long nb, int power)
{
	int	i;
	int number;

	number = nb;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
	{
		i = power - 1;
		while (i > 0)
		{
			number = number * nb;
			i--;
		}
		return (number);
	}
}
