/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 00:21:27 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/12 10:48:50 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_edge_case(long long number)
{
	if (number >= 9223372036854775807)
		return (-1);
	if (number <= -9223372036854775807 || number > 2147483647)
		return (0);
	if (number < -2147483648)
		return (-1);
	else
		return (number);
}

int	ft_atoi(const char *nptr)
{
	int			i;
	int			signal;
	long long	number;

	i = 0;
	signal = 1;
	number = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			signal = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = number * 10 + nptr[i] - '0';
		i++;
	}
	number = number * signal;
	return ((int)check_edge_case(number));
}
