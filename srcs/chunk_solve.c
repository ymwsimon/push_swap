/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:15:01 by mayeung           #+#    #+#             */
/*   Updated: 2023/12/14 14:48:52 by mayeung          ###   ########.fr       */
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

int	chunk_solve(t_stac *sts, int m, int print)
{
	int	chunk_size;
	int	move_up_to;
	int	pos_of_top_rank;
	int	top_rank;
	int	steps;

	if (ft_sorted(sts->na, sts->ra))
		return (0);
	chunk_size = sts->na / m;
	if (!chunk_size)
		chunk_size = 1;
	move_up_to = chunk_size;
	steps = 0;
	while (sts->na)
	{
		while (sts->na && get_min_rank(sts->ra, sts->na) < move_up_to)
		{
			if (sts->ra[0] < (move_up_to + chunk_size))
			{
				if (print)
					ft_push('b', 0, sts, "pb\n");
				else
					ft_push('b', 0, sts, "");
				steps++;
			}
			if (sts->nb && sts->rb[0] >= move_up_to && sts->na && sts->ra[0] >= (move_up_to + chunk_size))
			{
				if (print)
					ft_rr(sts, "rr\n");
				else
					ft_rr(sts, "");
				steps++;
			}
			else if (sts->nb && sts->rb[0] >= move_up_to)
				ft_rotate(sts->nb, sts->sb, sts->rb, "rb\n");
			else if (sts->na && sts->ra[0] >= (move_up_to + chunk_size))
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
			{
				if (print)
					ft_rotate(sts->nb, sts->sb, sts->rb, "rb\n");
				else
					ft_rotate(sts->nb, sts->sb, sts->rb, "");
				steps++;
			}
		}
		else
		{
			while (sts->nb && sts->rb[0] != top_rank)
			{
				if (print)
					ft_rev_rotate(sts->nb, sts->sb, sts->rb, "rrb\n");
				else
					ft_rev_rotate(sts->nb, sts->sb, sts->rb, "");
				steps++;
			}
		}
		if (print)
			ft_push('a', 0, sts, "pa\n");
		else
			ft_push('a', 0, sts, "");
		steps++;
		top_rank--;
		pos_of_top_rank = get_pos_of_rank(sts->rb, sts->nb, top_rank);
	}
	return (steps);
}
