/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:33:22 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/12 10:52:16 by rmartins         ###   ########.fr       */
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
	size_t			i;
	unsigned char	ch;

	i = 0;
	ch = (unsigned char)(c);
	while (i <= ft_strlen(s))
	{
		if (s[i] == ch)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
