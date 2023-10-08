/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 20:53:21 by mayeung           #+#    #+#             */
/*   Updated: 2023/08/18 14:01:50 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char			*t;
	size_t			i;
	unsigned int	maxsize = -1;

	t = 0;
	if ((nmemb <= maxsize || size <= maxsize) && nmemb * size <= maxsize)
		t = malloc(nmemb * size);
	i = 0;
	if (t)
	{
		while (i < (nmemb * size))
		{
			t[i] = 0;
			i++;
		}
	}
	return (t);
}
