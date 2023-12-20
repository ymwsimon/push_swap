/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:15:01 by mayeung           #+#    #+#             */
/*   Updated: 2023/12/20 15:54:22 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	move_from_a2b_group(t_stac *sts, double m, int steps, int print)
{
	int	chunk_size;
	int	move_up_to;

	chunk_size = sts->na / m;
	if (!chunk_size)
		chunk_size = 1;
	move_up_to = chunk_size;
	while (sts->na)
	{
		while (sts->na && min_r(sts->ra, sts->na) < move_up_to)
		{
			if (sts->na && sts->ra[0] < (move_up_to + chunk_size))
				ft_push(NO_UPDATE_RANK, sts, print * ++steps, "pb\n");
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

int	move_from_b2a(t_stac *sts, int steps, int lrank, int print)
{
	while (sts->nb)
	{
		if (need_ra(sts, lrank) && need_rb(sts))
			ft_rr(sts, print * ++steps, "rr\n");
		else if (need_rra(sts, lrank) && need_rrb(sts))
			ft_rrr(sts, print * ++steps, "rrr\n");
		else if (need_ra(sts, lrank))
			ft_rotate(sts, -1, print * ++steps, "ra\n");
		else if (need_rb(sts))
			ft_rotate(sts, -1, print * ++steps, "rb\n");
		else if (need_rra(sts, lrank))
			ft_rev_rotate(sts, sts->na, print * ++steps, "rra\n");
		else if (need_rrb(sts))
			ft_rev_rotate(sts, sts->nb, print * ++steps, "rrb\n");
		if (can_pa(sts, lrank))
		{
			if (sts->rb[0] == lrank)
				lrank++;
			else if (sts->rb[0] != max_r(sts->rb, sts->nb))
				lrank = sts->rb[0] + 1;
			ft_push(NO_UPDATE_RANK, sts, print * ++steps, "pa\n");
		}
	}
	return (steps);
}

int	rotate_min_to_top(t_stac *s, int print)
{
	int	steps;

	steps = 0;
	while (s->na && s->ra[0] != min_r(s->ra, s->na))
	{
		if (pos_r(s->ra, s->na, min_r(s->ra, s->na)) <= s->na / 2)
			ft_rotate(s, -1, print * ++steps, "ra\n");
		else
			ft_rev_rotate(s, s->na, print * ++steps, "rra\n");
	}
	return (steps);
}

int	chunk_solve(t_stac *sts, double m, int print)
{
	int	steps;

	if (all_sorted(sts->na, sts->ra))
		return (0);
	steps = move_from_a2b_group(sts, m, 0, print);
	steps += move_from_b2a(sts, 0, sts->nb, print);
	steps += rotate_min_to_top(sts, print);
	return (steps);
}
