/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_solve_logic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:53:52 by mayeung           #+#    #+#             */
/*   Updated: 2023/12/20 15:54:11 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	need_ra(t_stac *s, int lrank)
{
	int	urank;

	urank = max_r(s->rb, s->nb);
	if ((lrank > urank && s->na > 1 && s->ra[0] != min_r(s->ra, s->na)
			&& pos_r(s->ra, s->na, min_r(s->ra, s->na)) <= s->na / 2)
		|| (lrank <= urank && s->na > 1 && s->ra[0] == lrank - 1))
		return (1);
	return (0);
}

int	need_rb(t_stac *s)
{
	if (s->nb > 1 && s->rb[0] != max_r(s->rb, s->nb)
		&& pos_r(s->rb, s->nb, max_r(s->rb, s->nb)) <= s->nb / 2)
		return (1);
	return (0);
}

int	can_pa(t_stac *s, int lrank)
{
	int	urank;

	urank = max_r(s->rb, s->nb);
	if (s->nb && ((lrank > urank && (!s->na || s->ra[0] == min_r(s->ra, s->na)))
			|| (lrank <= urank && (s->rb[0] == lrank || s->rb[0] == urank))))
		return (1);
	return (0);
}

int	need_rra(t_stac *s, int lrank)
{
	int	urank;

	urank = max_r(s->rb, s->nb);
	if (lrank > urank && s->na > 1 && s->ra[0] != min_r(s->ra, s->na)
		&& pos_r(s->ra, s->na, min_r(s->ra, s->na)) > s-> na / 2)
		return (1);
	return (0);
}

int	need_rrb(t_stac *s)
{
	if (s->nb > 1 && s->rb[0] != max_r(s->rb, s->nb)
		&& pos_r(s->rb, s->nb, max_r(s->rb, s->nb)) > s->nb / 2)
		return (1);
	return (0);
}
