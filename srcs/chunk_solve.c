/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:15:01 by mayeung           #+#    #+#             */
/*   Updated: 2023/12/14 17:03:24 by mayeung          ###   ########.fr       */
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

int	move_from_a2b_group(t_stac *sts, int m, int steps, int print)
{
	int	chunk_size;
	int	move_up_to;

	chunk_size = sts->na / m;
	if (!chunk_size)
		chunk_size = 1;
	move_up_to = chunk_size;
	while (sts->na)
	{
		while (sts->na && get_min_rank(sts->ra, sts->na) < move_up_to)
		{
			if (sts->na && sts->ra[0] < (move_up_to + chunk_size))
				ft_push(0, sts, print * ++steps, "pb\n");
			if (sts->nb && sts->rb[0] >= move_up_to && sts->na
				&& sts->ra[0] >= (move_up_to + chunk_size))
				ft_rr(sts, print * ++steps, "rr\n");
			else if (sts->nb && sts->rb[0] >= move_up_to)
				ft_rotate(sts, -1, print * ++steps, "rb\n");
			else if (sts->na && sts->ra[0] >= (move_up_to + chunk_size))
				ft_rotate(sts, -1, print * ++steps, "ra\n");
		}
		move_up_to += chunk_size;
	}
	return (steps);
}

int	move_from_b2a(t_stac *sts, int steps, int print)
{
	int	pos_of_top_rank;
	int	top_rank;

	top_rank = sts->nb - 1;
	pos_of_top_rank = get_pos_of_rank(sts->rb, sts->nb, top_rank);
	while (sts->nb)
	{
		if (pos_of_top_rank < sts->nb / 2)
			while (sts->nb && sts->rb[0] != top_rank)
				ft_rotate(sts, -1, print * ++steps, "rb\n");
		else
			while (sts->nb && sts->rb[0] != top_rank)
				ft_rev_rotate(sts, sts->nb, print * ++steps, "rrb\n");
		ft_push(0, sts, print, "pa\n");
		steps++;
		pos_of_top_rank = get_pos_of_rank(sts->rb, sts->nb, --top_rank);
	}
	return (steps);
}

int	chunk_solve(t_stac *sts, int m, int print)
{
	int	steps;

	if (ft_sorted(sts->na, sts->ra))
		return (0);
	steps = move_from_a2b_group(sts, m, 0, print);
	steps += move_from_b2a(sts, 0, print);
	return (steps);
}

/*

int	pos_search_from_head(int *r, int n, int rank)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (r[i] < rank)
			return (i);
		i++;
	}
	return (-1);
}

int	pos_search_from_end(int *r, int n, int rank)
{
	int	i;

	i = n - 1;
	while (i >= 0)
	{
		if (r[i] < rank)
			return (i);
		i--;
	}
	return (-1);
}

*/