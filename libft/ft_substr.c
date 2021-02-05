/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:15:25 by rmartins          #+#    #+#             */
/*   Updated: 2021/01/13 22:43:10 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	lenght;

	if (!s)
		return (NULL);
	lenght = ft_strlen(s);
	if (start >= lenght || lenght == 0)
	{
		ptr = (char *)malloc(1);
		if (!ptr)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	lenght = ((lenght - start) < len ? (lenght - start) : len);
	ptr = (char *)malloc(lenght + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, &s[start], lenght);
	ptr[lenght] = '\0';
	return (ptr);
}
