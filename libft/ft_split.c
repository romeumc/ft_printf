/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 10:45:22 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/09 14:11:22 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*saveword(const char *str, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] != c && str[i] != '\0')
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	wordcount(const char *s, char c, char **res, int save)
{
	int		i;
	int		wc;

	i = 0;
	wc = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
		{
			if (save == 1)
				res[wc] = saveword(&s[i + 1], c);
			wc++;
		}
		else if (wc == 0 && s[i] != c)
		{
			if (save == 1)
				res[wc] = saveword(&s[i], c);
			wc++;
		}
		i++;
	}
	return (wc);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		wc;

	if (!s)
		return (NULL);
	wc = wordcount(s, c, NULL, 0);
	res = malloc(sizeof(char *) * (wc + 1));
	if (!res)
		return (NULL);
	wordcount(s, c, res, 1);
	res[wc] = NULL;
	return (res);
}
