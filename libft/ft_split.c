/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 20:55:24 by mayeung           #+#    #+#             */
/*   Updated: 2023/07/30 20:55:31 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_update_sten(char const **s, char **en, char c)
{	
	while (**s && **s == c)
		(*s)++;
	*en = ft_strchr(*s, c);
}

void	ft_init(char ***res, size_t	*sres)
{
		*res = malloc(sizeof(char *));
		*sres = 1;
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	**temp;
	char	*en;
	size_t	sres;

	ft_init(&res, &sres);
	if (!res || !s)
		return (res);
	ft_update_sten(&s, &en, c);
	while (*s)
	{
		temp = malloc(sizeof(char *) * (++sres));
		if (sres > 2)
			ft_memcpy(temp, res, sizeof(char *) * (sres - 1));
		free(res);
		res = temp;
		if (!en)
			en = (char *)&s[ft_strlen(s)];
		res[sres - 2] = malloc(sizeof(char) * (en - s + 1));
		ft_strlcpy(res[sres - 2], s, en - s + 1);
		s = en;
		ft_update_sten(&s, &en, c);
	}
	res[sres - 1] = 0;
	return (res);
}
