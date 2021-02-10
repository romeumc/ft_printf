/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_join_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 13:06:33 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/10 13:08:36 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_join(char *s, char c)
{
	int		i;
	char	*temp;

	i = 0;
	temp = malloc(sizeof(char) * (ft_strlen(s) + 2));
	if (temp == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		temp[i] = s[i];
		i++;
	}
	temp[i++] = c;
	temp[i] = '\0';
	free(s);
	return (temp);
}
