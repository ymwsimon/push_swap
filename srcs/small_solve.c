/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:56:42 by mayeung           #+#    #+#             */
/*   Updated: 2023/10/07 17:13:53 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_ssolve_1step(t_stac *s)
{
	while (!ft_sorted(s->na, s->ra))
	{
		if (s->nb > 1 && s->ra[0] == s->na - 1 && s->rb[0] < s->nb / 2)
			ft_rr(s, "rr\n");
		else if (s->nb > 1 && s->ra[s->na - 1] == 0 && \
				s->rb[s->nb - 1] > s->nb / 2)
			ft_rrr(s, "rrr\n");
		else if ((s->na > 1 && s->ra[0] > s->ra[1]) && \
				(s->nb > 1 && s->rb[0] < s->rb[1]))
			ft_ss(s, "ss\n");
		else if (s->na > 1 && s->ra[0] == s->na - 1)
			ft_rotate(s->na, s->sa, s->ra, "ra\n");
		else if (s->nb > 1 && s->rb[0] == 0)
			ft_rotate(s->nb, s->sb, s->rb, "rb\n");
		else if (s->na > 1 && s->ra[s->na - 1] == 0)
			ft_rev_rotate(s->na, s->sa, s->ra, "rra\n");
		else if (s->nb > 1 && s->rb[s->nb - 1] == s->nb - 1)
			ft_rev_rotate(s->nb, s->sb, s->rb, "rrb\n");
		else if (s->na > 1 && s->ra[0] > s->ra[1])
			ft_swap(s->na, s->sa, s->ra, "sa\n");
		else if (s->nb > 1 && s->rb[0] < s->rb[1])
			ft_swap(s->nb, s->sb, s->rb, "sb\n");
		else if (s->na > 0)
			ft_push('b', 1, s, "pb\n");
	}
}

void	ft_get_new_rank(t_stac *sts, int *v, int *nr)
{
	*v = sts->sb[0];
	ft_push('a', 1, sts, 0);
	*nr = sts->ra[0];
	ft_push('b', 1, sts, 0);
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
					ft_rotate(sts->na, sts->sa, sts->ra, "ra\n");
			else
				while (sts->ra[0] != 0)
					ft_rev_rotate(sts->na, sts->sa, sts->ra, "rra\n");
		}
		else
		{
			if (sts->ra[0] < nr || nr < sts->ra[0] - sts->na / 2)
				while (!(v < sts->sa[0] && v > sts->sa[sts->na - 1]))
					ft_rotate(sts->na, sts->sa, sts->ra, "ra\n");
			else
				while (!(v < sts->sa[0] && v > sts->sa[sts->na - 1]))
					ft_rev_rotate(sts->na, sts->sa, sts->ra, "rra\n");
		}
		ft_push('a', 1, sts, "pa\n");
	}
}

void	ft_ssolve_3step(t_stac *sts)
{
	while (!ft_sorted(sts->na, sts->ra))
	{
		if (sts->ra[0] > sts->na / 2)
			ft_rotate(sts->na, sts->sa, sts->ra, "ra\n");
		else
			ft_rev_rotate(sts->na, sts->sa, sts->ra, "rra\n");
	}
}

void	ft_small_solve(t_stac *sts)
{
	ft_ssolve_1step(sts);
	ft_get_rankab(sts);
	ft_ssolve_2step(sts, 0, 0);
	ft_ssolve_3step(sts);
}
