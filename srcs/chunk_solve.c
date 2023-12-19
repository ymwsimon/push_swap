/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:15:01 by mayeung           #+#    #+#             */
/*   Updated: 2023/12/19 22:43:58 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	min_r(int *r, int n)
{
	int	i;
	int	res;

	if (!n || !r)
		return (-1);
	res = r[0];
	i = 1;
	while (r && i < n)
	{
		if (r[i] < res)
			res = r[i];
		i++;
	}
	return (res);
}

int max_r(int *r, int n)
{
	int	i;
	int	res;

	res = r[0];
	i = 1;
	while (r && i < n)
	{
		if (r[i] > res)
			res = r[i];
		i++;
	}
	return (res);
}

int	pos_r(int *r, int n, int rank)
{
	int	i;

	i = 0;
	while (i < n && r && r[i] != rank)
		i++;
	if (i == n)
		return (-1);
	return (i);
}

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
	int	lrank;
	int	urank;

	urank = sts->nb - 1;
	lrank = sts->nb;
	while (sts->nb)
	{
		if (((lrank > urank && ((sts->na > 1 && sts->ra[0] != min_r(sts->ra, sts->na) && pos_r(sts->ra, sts->na, min_r(sts->ra, sts->na)) <= sts->na / 2)))
			|| (lrank <= urank && sts->na > 1 && sts->ra[0] == lrank - 1))
			&& sts->nb > 1 && sts->rb[0] != max_r(sts->rb, sts->nb) && pos_r(sts->rb, sts->nb, max_r(sts->rb, sts->nb)) <= sts->nb / 2)
			ft_rr(sts, print * ++steps, "rr\n");
		//else if (lrank > urank && sts->na > 1 && sts->ra[0] != min_r(sts->ra, sts->na) && pos_r(sts->ra, sts->na, min_r(sts->ra, sts->na)) > sts->na / 2
		//	&& sts->nb > 1 && sts->rb[0] != max_r(sts->rb, sts->nb) && pos_r(sts->rb, sts->nb, max_r(sts->rb, sts->nb)) > sts->nb / 2)
		//	{ft_rrr(sts, print * ++steps, "rrr\n"); flag = 1;}
		else if ((lrank > urank && sts->na > 1 && sts->ra[0] != min_r(sts->ra, sts->na) && pos_r(sts->ra, sts->na, min_r(sts->ra, sts->na)) <= sts->na / 2)
			|| (lrank <= urank && sts->na > 1 && sts->ra[0] == lrank - 1))
			ft_rotate(sts, -1, print * ++steps, "ra\n");
		else if (sts->nb > 1 && sts->rb[0] != max_r(sts->rb, sts->nb) && pos_r(sts->rb, sts->nb, max_r(sts->rb, sts->nb)) <= sts->nb / 2)
			ft_rotate(sts, -1, print * ++steps, "rb\n");
		else if (lrank > urank && sts->na > 1 && sts->ra[0] != min_r(sts->ra, sts->na) && pos_r(sts->ra, sts->na, min_r(sts->ra, sts->na)) > sts->na / 2)
			ft_rev_rotate(sts, sts->na, print * ++steps, "rra\n");
		else if (sts->nb > 1 && sts->rb[0] != max_r(sts->rb, sts->nb) && pos_r(sts->rb, sts->nb, max_r(sts->rb, sts->nb)) > sts->nb / 2)
			ft_rev_rotate(sts, sts->nb, print * ++steps, "rrb\n");
		if ((lrank > urank && (!sts->na || sts->ra[0] == min_r(sts->ra, sts->na))) || (lrank <= urank && (lrank == sts->rb[0] || urank == sts->rb[0])))
		{
			ft_push(0, sts, print * ++steps, "pa\n");
			if (sts->ra[0] == lrank)
				lrank++;
			else if (sts->ra[0] != urank)
				lrank = sts->ra[0] + 1;
			urank = max_r(sts->rb, sts->nb);
		}
	}
	while (sts->na && sts->ra[0] != min_r(sts->ra, sts->na))
	{
		if (pos_r(sts->ra, sts->na, min_r(sts->ra, sts->na)) <= sts->na / 2)
			ft_rotate(sts, -1, print * ++steps, "ra\n");
		else
			ft_rev_rotate(sts, sts->na, print * ++steps, "rra\n");
	}
	return (steps);
}

int	chunk_solve(t_stac *sts, double m, int print)
{
	int	steps;

	if (ft_sorted(sts->na, sts->ra))
		return (0);
	steps = move_from_a2b_group(sts, m, 0, print);
	steps += move_from_b2a(sts, 0, print);
	return (steps);
}
