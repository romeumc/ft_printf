/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:49:53 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/12 10:52:32 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*temp;

	i = 0;
	temp = (char *)malloc(ft_strlen(s) + 1);
	if (temp != NULL)
	{
		while (s[i] != '\0')
		{
			temp[i] = s[i];
			i++;
		}
		temp[i] = '\0';
		return (temp);
	}
	return (NULL);
}
