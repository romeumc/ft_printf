/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 09:11:04 by rmartins          #+#    #+#             */
/*   Updated: 2021/01/14 10:45:55 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_start(char const *s1, char const *set)
{
	int		flag;
	int		counter;
	size_t	j;
	size_t	i;

	i = 0;
	counter = 0;
	flag = 1;
	while (i < ft_strlen(s1) && flag == 1)
	{
		j = 0;
		flag = 0;
		while (j < ft_strlen(set))
		{
			if (s1[i] == set[j])
			{
				counter++;
				flag = 1;
			}
			j++;
		}
		i++;
	}
	return (counter);
}

static int	count_end(char const *s1, char const *set, size_t pos)
{
	int		flag;
	int		counter;
	size_t	j;
	size_t	i;

	i = ft_strlen(s1) - 1;
	counter = 0;
	flag = 1;
	while (i > pos && flag == 1)
	{
		j = 0;
		flag = 0;
		while (j < ft_strlen(set))
		{
			if (s1[i] == set[j])
			{
				counter++;
				flag = 1;
			}
			j++;
		}
		i--;
	}
	return (counter);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start_counter;
	size_t	end_counter;
	char	*ptr;

	if (!s1)
		return (NULL);
	start_counter = count_start(s1, set);
	end_counter = count_end(s1, set, start_counter);
	ptr = (char *)malloc(ft_strlen(s1) - (start_counter + end_counter) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < (ft_strlen(s1) - (start_counter + end_counter)))
	{
		ptr[i] = s1[start_counter + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
