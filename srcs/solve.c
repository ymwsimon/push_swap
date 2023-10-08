/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:58:20 by mayeung           #+#    #+#             */
/*   Updated: 2023/10/07 14:02:39 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_proc_st(int digit, int times, char from, t_stac *sts)
{
	int	i;

	i = 0;
	while (i < times)
	{
		if (from == 'a' && !(sts->ra[0] & digit))
			ft_rotate(sts->na, sts->sa, sts->ra, "ra\n");
		else if (from == 'a' && (sts->ra[0] & digit))
		{
			ft_push('b', 0, sts, "pb\n");
			if (digit != 1)
				ft_rotate(sts->nb, sts->sb, sts->rb, "rb\n");
		}
		else if (from == 'b' && (sts->rb[0] & digit))
			ft_rotate(sts->nb, sts->sb, sts->rb, "rb\n");
		else if (from == 'b' && !(sts->rb[0] & digit))
		{
			ft_push('a', 0, sts, "pa\n");
			ft_rotate(sts->na, sts->sa, sts->ra, "ra\n");
		}
		i++;
	}
}

void	ft_solve(t_stac *sts)
{
	int	i;
	int	tmp;

	i = 0;
	while (i <= sts->n)
	{
		tmp = sts->nb;
		if (i != sts->n)
			ft_proc_st(1 << i, sts->na, 'a', sts);
		ft_proc_st(1 << i, tmp, 'b', sts);
		i++;
	}
}
