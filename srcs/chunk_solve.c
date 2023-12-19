/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:15:01 by mayeung           #+#    #+#             */
/*   Updated: 2023/12/19 19:15:15 by mayeung          ###   ########.fr       */
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

int	last_index_from_head(t_stac *sts, int rank)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (i < sts->na)
	{
		if (sts->ra[i] < rank)
			res = i;
		i++;
	}
	return (res);
}

int	last_index_from_end(t_stac *sts, int rank)
{
	int res;
	int	i;

	i = sts->na - 1;
	res = sts->na - 1;
	while (i >= 0)
	{
		if (sts->ra[i] < rank)
			res = i;
		i--;
	}
	return (res);
}

int	move_from_a2b_group(t_stac *sts, double m, int steps, int print)
{
	int	chunk_size;
	int	move_up_to;

	chunk_size = sts->na * 1.0 / m;
	if (!chunk_size)
		chunk_size = 1;
	move_up_to = chunk_size;
	while (sts->na)
	{
		//if (last_index_from_head(sts, move_up_to) < sts->na - last_index_from_end(sts, move_up_to))
		//{
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
		/*}
		else
		{
			while (sts->na && get_min_rank(sts->ra, sts->na) < move_up_to)
			{
				if (sts->na && sts->ra[0] < (move_up_to + chunk_size))
					ft_push(0, sts, print * ++steps, "pb\n");
				if (sts->nb && sts->rb[0] < move_up_to && sts->na
					&& sts->ra[0] >= (move_up_to + chunk_size))
					ft_rrr(sts, print * ++steps, "rrr\n");
				else if (sts->nb && sts->rb[0] < move_up_to)
					ft_rev_rotate(sts, sts->nb, print * ++steps, "rrb\n");
				else if (sts->na && sts->ra[0] >= (move_up_to + chunk_size))
					ft_rev_rotate(sts, sts->na, print * ++steps, "rra\n");
			}
		}*/
		move_up_to += chunk_size;
	}
	return (steps);
}

int	move_from_b2a(t_stac *sts, int steps, int print)
{
	int	lrank;
	int	urank;
	int flag;

	urank = sts->nb - 1;
	lrank = sts->nb;
	while (sts->nb)
	{
		flag = 0;
		if (((lrank > urank && ((sts->na > 1 && sts->ra[0] != min_r(sts->ra, sts->na) && pos_r(sts->ra, sts->na, min_r(sts->ra, sts->na)) <= sts->na / 2)))
			|| (lrank <= urank && sts->na > 1 && sts->ra[0] == lrank - 1))
			&& sts->nb > 1 && sts->rb[0] != max_r(sts->rb, sts->nb) && pos_r(sts->rb, sts->nb, max_r(sts->rb, sts->nb)) <= sts->nb / 2)
			{ft_rr(sts, print * ++steps, "rr\n"); flag = 1;}
		//else if (lrank > urank && sts->na > 1 && sts->ra[0] != min_r(sts->ra, sts->na) && pos_r(sts->ra, sts->na, min_r(sts->ra, sts->na)) > sts->na / 2
		//	&& sts->nb > 1 && sts->rb[0] != max_r(sts->rb, sts->nb) && pos_r(sts->rb, sts->nb, max_r(sts->rb, sts->nb)) > sts->nb / 2)
		//	{ft_rrr(sts, print * ++steps, "rrr\n"); flag = 1;}
		else if ((lrank > urank && sts->na > 1 && sts->ra[0] != min_r(sts->ra, sts->na) && pos_r(sts->ra, sts->na, min_r(sts->ra, sts->na)) <= sts->na / 2)
			|| (lrank <= urank && sts->na > 1 && sts->ra[0] == lrank - 1))
			{ft_rotate(sts, -1, print * ++steps, "ra\n"); flag = 1;}
		else if (sts->nb > 1 && sts->rb[0] != max_r(sts->rb, sts->nb) && pos_r(sts->rb, sts->nb, max_r(sts->rb, sts->nb)) <= sts->nb / 2)
			{ft_rotate(sts, -1, print * ++steps, "rb\n"); flag = 1;}
		else if (lrank > urank && sts->na > 1 && sts->ra[0] != min_r(sts->ra, sts->na) && pos_r(sts->ra, sts->na, min_r(sts->ra, sts->na)) > sts->na / 2)
			{ft_rev_rotate(sts, sts->na, print * ++steps, "rra\n"); flag = 1;}
		else if (sts->nb > 1 && sts->rb[0] != max_r(sts->rb, sts->nb) && pos_r(sts->rb, sts->nb, max_r(sts->rb, sts->nb)) > sts->nb / 2)
			{ft_rev_rotate(sts, sts->nb, print * ++steps, "rrb\n"); flag = 1;}
		if ((lrank > urank && (!sts->na || sts->ra[0] == min_r(sts->ra, sts->na))) || (lrank <= urank && (lrank == sts->rb[0] || urank == sts->rb[0])))
		{
			flag = 1;
			ft_push(0, sts, print * ++steps, "pa\n");
			if (sts->ra[0] == lrank)
				lrank++;
			else if (sts->ra[0] != urank)
				lrank = sts->ra[0] + 1;
			urank = max_r(sts->rb, sts->nb);
		}
		if (!flag)
			return 0;
		}
		while (sts->na && sts->ra[0] != min_r(sts->ra, sts->na))
		{
			if (pos_r(sts->ra, sts->na, min_r(sts->ra, sts->na)) <= sts->na / 2)
				{ft_rotate(sts, -1, print * ++steps, "ra\n"); flag = 1;}
			else
				{ft_rev_rotate(sts, sts->na, print * ++steps, "rra\n"); flag = 1;}
		}
		return (steps);
		/*
		if (lower_rank >= upper_rank || sts->rb[0] == lower_rank || sts->rb[0] == upper_rank)
		{
			ft_push(0, sts, print * ++steps, "pa\n");
			if (sts->ra[0] != upper_rank)
				lower_rank = sts->ra[0] + 1;
			else
				upper_rank--;
			if (upper_rank < lower_rank)
			{
				if (sts->na && get_pos_of_rank(sts->ra, sts->na, get_min_rank(sts->ra, sts->na)) < sts->na / 2)
					while (sts->na && sts->ra[0] != upper_rank)
						ft_rotate(sts, -1, print * ++steps, "ra\n");
				else
					while (sts->na && get_min_rank(sts->ra, sts->na) != sts->ra[0])
						ft_rev_rotate(sts, sts->na, print * ++steps, "rra\n");
				upper_rank = get_min_rank(sts->ra, sts->na);
			}
			flag = 1;
		}

		if (sts->na && sts->ra[0] == lower_rank - 1 && sts->nb && get_pos_of_rank(sts->rb, sts->nb, upper_rank) < sts->nb / 2)
			{ft_rr(sts, print * ++steps, "rr\n"); flag = 1;}
		else if (sts->na && sts->ra[0] == lower_rank - 1)
			{ft_rotate(sts, -1, print * ++steps, "ra\n"); flag = 1;}
		if (sts->nb && get_pos_of_rank(sts->rb, sts->nb, upper_rank) != -1 && get_pos_of_rank(sts->rb, sts->nb, upper_rank) < sts->nb / 2)
			{ft_rotate(sts, -1, print * ++steps, "rb\n"); flag = 1;}
		else if (sts->nb && get_pos_of_rank(sts->rb, sts->nb, upper_rank) > sts->nb / 2)
			{ft_rev_rotate(sts, sts->nb, print * ++steps, "rrb\n"); flag = 1;}
		if (!flag)
			return 0;*/
		/*
		if (sts->nb && get_pos_of_rank(sts->rb, sts->nb, upper_rank) < sts->nb && sts->na && sts->ra[0] == lower_rank && lower_rank < upper_rank)
			ft_rr(sts, print * ++steps, "rr\n");
		else if (sts->na > 1 && sts->ra[0] == lower_rank)
			ft_rotate(sts, -1, print * ++steps, "ra\n");
		else if (sts->nb && get_pos_of_rank(sts->rb, sts->nb, upper_rank) != -1 && get_pos_of_rank(sts->rb, sts->nb, upper_rank) < sts->nb / 2)
			ft_rotate(sts, -1, print * ++steps, "rb\n");
		else if (sts->nb && get_pos_of_rank(sts->rb, sts->nb, upper_rank) > sts->nb / 2)
			ft_rev_rotate(sts, sts->nb, print * ++steps, "rrb\n");
		else if (sts->na > 1 && get_min_rank(sts->ra, sts->na) != sts->ra[0])
		{
			ft_rotate(sts, -1, print * ++steps, "ra\n");
			upper_rank = get_min_rank(sts->ra, sts->na);
			lower_rank = upper_rank + 1;
		}*/
		/*
		if (sts->nb && get_pos_of_rank(sts->rb, sts->nb, upper_rank) < sts->nb && sts->na && sts->ra[0] == lower_rank && lower_rank < upper_rank)
			ft_rr(sts, print * ++steps, "rr\n");
		else if (sts->na && sts->ra[0] == lower_rank)
			ft_rotate(sts, -1, print * ++steps, "ra\n");
		else if (sts->nb && get_pos_of_rank(sts->rb, sts->nb, upper_rank) != -1 && get_pos_of_rank(sts->rb, sts->nb, upper_rank) < sts->nb)
			ft_rotate(sts, -1, print * ++steps, "rb\n");
		else if (sts->nb && get_pos_of_rank(sts->rb, sts->nb, upper_rank) > sts->nb)
			ft_rev_rotate(sts, sts->nb, print * ++steps, "rrb\n");
		else if (sts->na && get_min_rank(sts->ra, sts->na) != sts->ra[0])
		{
			ft_rotate(sts, -1, print * ++steps, "ra\n");
			upper_rank = sts->ra[0];
			lower_rank = upper_rank + 1;
		}
		*/
		/*
				if (lower_rank > upper_rank || sts->rb[0] == lower_rank + 1 || sts->rb[0] == upper_rank)
		{
			ft_push(0, sts, print * ++steps, "pa\n");
			if (sts->ra[0] != upper_rank)
				lower_rank = sts->ra[0];
			else
				upper_rank--;
		}
		if (sts->nb && get_pos_of_rank(sts->rb, sts->nb, upper_rank) != -1 && get_pos_of_rank(sts->rb, sts->nb, upper_rank) < sts->nb
			&& sts->ra[0] == lower_rank && lower_rank + 1 < upper_rank)
			ft_rr(sts, print * ++steps, "rr\n");
		else if (lower_rank + 1 == upper_rank)
		{
			while (sts->na && sts->ra[0] != get_min_rank(sts->ra, sts->na))
				ft_rev_rotate(sts, sts->na, print * ++steps, "rra\n");
			if (sts->na)
				upper_rank = get_min_rank(sts->ra, sts->na) - 1;
		}
		else if (sts->na && sts->ra[0] == lower_rank)
			ft_rotate(sts, -1, print * ++steps, "ra\n");
		else if (sts->nb && get_pos_of_rank(sts->rb, sts->nb, upper_rank) != -1 && get_pos_of_rank(sts->rb, sts->nb, upper_rank) < sts->nb / 2)
		{
			while (sts->rb[0] != upper_rank)
				ft_rotate(sts, -1, print * ++steps, "rb\n");
		}
		else if (sts->nb && get_pos_of_rank(sts->rb, sts->nb, upper_rank) != -1 && get_pos_of_rank(sts->rb, sts->nb, upper_rank) > sts->nb / 2)
		{
			while (sts->rb[0] != upper_rank)
				ft_rev_rotate(sts, sts->nb, print * ++steps, "rrb\n"); 
		}
		*/
}
		/*
		if (pos_of_upper_rank < sts->nb / 2)
			while (sts->nb && sts->rb[0] != upper_rank)
				ft_rotate(sts, -1, print * ++steps, "rb\n");
		else
			while (sts->nb && sts->rb[0] != upper_rank)
				ft_rev_rotate(sts, sts->nb, print * ++steps, "rrb\n");
		ft_push(0, sts, print, "pa\n");
		steps++;
		pos_of_upper_rank = get_pos_of_rank(sts->rb, sts->nb, --upper_rank);
		*/
int	chunk_solve(t_stac *sts, double m, int print)
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