/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:15:01 by mayeung           #+#    #+#             */
/*   Updated: 2023/12/10 22:49:52 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	get_min_rank(int *r, int n)
{
	int	i;
	int	res;

	res = r[0];
	i = 1;
	while (i < n)
	{
		if (r[i] < res)
			res = r[i];
		i++;
	}
	return (res);
}

int	get_pos_of_rank(int *r, int n, int rank)
{
	int	i;

	i = 0;
	while (i < n && r[i] != rank)
		i++;
	return (i);
}

void	chunk_solve(t_stac *sts)
{
	int	chunk_size;
	int	move_up_to;
	int	pos_of_top_rank;
	int	top_rank;

	chunk_size = sts->na / sts->n;
	move_up_to = chunk_size;
	while (sts->na)
	{
		while (sts->na && get_min_rank(sts->ra, sts->na) < move_up_to)
		{
			if (sts->ra[0] < move_up_to)
				ft_push('b', 0, sts, "pb\n");
			else
				ft_rotate(sts->na, sts->sa, sts->ra, "ra\n");
		}
		move_up_to += chunk_size;
	}
	top_rank = sts->nb - 1;
	pos_of_top_rank = get_pos_of_rank(sts->rb, sts->nb, top_rank);
	while (sts->nb)
	{
		if (pos_of_top_rank < sts->nb / 2)
		{
			while (sts->nb && sts->rb[0] != top_rank)
				ft_rotate(sts->nb, sts->sb, sts->rb, "rb\n");
		}
		else
		{
			while (sts->nb && sts->rb[0] != top_rank)
				ft_rev_rotate(sts->nb, sts->sb, sts->rb, "rrb\n");
		}
		ft_push('a', 0, sts, "pa\n");
		top_rank--;
		pos_of_top_rank = get_pos_of_rank(sts->rb, sts->nb, top_rank);
	}
}
