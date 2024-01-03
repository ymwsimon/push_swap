/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:57:53 by mayeung           #+#    #+#             */
/*   Updated: 2024/01/03 01:01:49 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_get_rank(int n, int *st, int *rank)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		rank[i] = 0;
		j = 0;
		while (j < i)
		{
			if (st[j] < st[i])
				rank[i]++;
			j++;
		}
		j = n - 1;
		while (j > i)
		{
			if (st[j] < st[i])
				rank[i]++;
			j--;
		}
		i++;
	}
}

void	ft_get_rankab(t_stac *sts)
{
	ft_get_rank(sts->na, sts->sa, sts->ra);
	ft_get_rank(sts->nb, sts->sb, sts->rb);
}
