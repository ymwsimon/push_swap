/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 20:55:24 by mayeung           #+#    #+#             */
/*   Updated: 2024/01/19 14:34:01 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static size_t	ft_count_word(const char *s, char c)
{
	size_t	res;

	res = 0;
	while (s && *s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			while (*s && *s != c)
				s++;
			res++;
		}
	}
	return (res);
}

static size_t	ft_word_length(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s && s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_clean_up_split(size_t k, char **arr)
{
	size_t	i;

	i = 0;
	while (i < k)
	{
		free(arr[i]);
		i++;
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char		**res;
	size_t		i;
	size_t		k;

	k = 0;
	res = malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	while (res && s && *s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			res[k] = malloc(sizeof(char) * (ft_word_length(s, c) + 1));
			if (!res[k])
				return (ft_clean_up_split(k, res));
			i = -1;
			while (s[++i] && s[i] != c)
				res[k][i] = s[i];
			res[k++][i] = 0;
			s += i;
		}
	}
	if (res)
		res[k] = NULL;
	return (res);
}
