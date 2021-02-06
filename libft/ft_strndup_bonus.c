/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 02:40:22 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/06 02:47:46 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*temp;

	i = ft_strlen(s) > n ? n : ft_strlen(s);
	temp = (char *)malloc(i + 1);
	i = 0;
	if (temp != NULL)
	{
		while (s[i] != '\0' && i < n)
		{
			temp[i] = s[i];
			i++;
		}
		temp[i] = '\0';
		return (temp);
	}
	return (NULL);
}
