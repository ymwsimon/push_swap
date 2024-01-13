/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:56:42 by mayeung           #+#    #+#             */
/*   Updated: 2024/01/13 16:06:19 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ssolve_1step(t_stac *s)
{
	while (!all_sorted(s->na, s->ra))
	{
		if (s->na > 1 && s->ra[0] == s->na - 1 && s->nb > 1 && s->rb[0] == 0)
			ft_rr(s, PRINT, "rr\n");
		else if (s->nb > 1 && s->ra[s->na - 1] == 0
			&& s->nb > 1 && s->rb[s->nb - 1] == s->nb - 1)
			ft_rrr(s, PRINT, "rrr\n");
		else if ((s->na > 1 && s->ra[0] > s->ra[1])
			&& (s->nb > 1 && s->rb[0] < s->rb[1]))
			ft_ss(s, PRINT, "ss\n");
		else if (s->na > 1 && s->ra[0] == s->na - 1)
			ft_rotate(s, -1, PRINT, "ra\n");
		else if (s->nb > 1 && s->rb[0] == 0)
			ft_rotate(s, -1, PRINT, "rb\n");
		else if (s->na > 1 && s->ra[s->na - 1] == 0)
			ft_rev_rotate(s, s->na, PRINT, "rra\n");
		else if (s->nb > 1 && s->rb[s->nb - 1] == s->nb - 1)
			ft_rev_rotate(s, s->nb, PRINT, "rrb\n");
		else if (s->na > 1 && s->ra[0] > s->ra[1])
			ft_swap(s, PRINT, "sa\n");
		else if (s->nb > 1 && s->rb[0] < s->rb[1])
			ft_swap(s, PRINT, "sb\n");
		else if (s->na > 0)
			ft_push(UPDATE_RANK, s, PRINT, "pb\n");
	}
}

void	ft_get_new_rank(t_stac *sts, int *v, int *nr)
{
	*v = sts->sb[0];
	ft_push(UPDATE_RANK, sts, NO_PRINT, "pa\n");
	*nr = sts->ra[0];
	ft_push(UPDATE_RANK, sts, NO_PRINT, "pb\n");
}

void	ft_ssolve_2step(t_stac *sts, int v, int nr)
{
	while (sts->nb)
	{
		ft_get_new_rank(sts, &v, &nr);
		if (nr == 0 || nr == sts->na)
		{
			if (sts->ra[0] > sts->na / 2)
				while (sts->ra[0] != 0)
					ft_rotate(sts, -1, PRINT, "ra\n");
			else
				while (sts->ra[0] != 0)
					ft_rev_rotate(sts, sts->na, PRINT, "rra\n");
		}
		else
		{
			if (sts->ra[0] < nr || nr < sts->ra[0] - sts->na / 2)
				while (!(v < sts->sa[0] && v > sts->sa[sts->na - 1]))
					ft_rotate(sts, -1, PRINT, "ra\n");
			else
				while (!(v < sts->sa[0] && v > sts->sa[sts->na - 1]))
					ft_rev_rotate(sts, sts->na, PRINT, "rra\n");
		}
		ft_push(UPDATE_RANK, sts, PRINT, "pa\n");
	}
}

void	ft_ssolve_3step(t_stac *sts)
{
	while (!all_sorted(sts->na, sts->ra))
	{
		if (sts->ra[0] > sts->na / 2)
			ft_rotate(sts, -1, PRINT, "ra\n");
		else
			ft_rev_rotate(sts, sts->na, PRINT, "rra\n");
	}
}

void	ft_small_solve(t_stac *sts)
{
	ft_ssolve_1step(sts);
	ft_get_rankab(sts);
	ft_ssolve_2step(sts, 0, 0);
	ft_ssolve_3step(sts);
}
