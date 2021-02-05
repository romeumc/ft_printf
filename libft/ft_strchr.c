/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:33:22 by rmartins          #+#    #+#             */
/*   Updated: 2021/01/12 16:34:29 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** size_t	search_area;
**
** search_area = ft_strlen(s) + 1;
** return ((char *)ft_memchr(s, c, search_area));
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
