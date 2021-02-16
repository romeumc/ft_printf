/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 10:18:26 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/16 18:11:57 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*newptr;

	if (ptr == NULL)
	{
		ptr = malloc(size);
		if (ptr == NULL)
			return (NULL);
	}
	if (size == 0 && ptr != NULL)
		free(ptr);
	else
	{
		newptr = malloc(size);
		if (newptr == NULL)
			return (NULL);
		else
		{
			ft_memcpy(newptr, ptr, size);
			free(ptr);
			return (newptr);
		}
	}
	return (ptr);
}
