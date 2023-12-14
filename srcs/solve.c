/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:58:20 by mayeung           #+#    #+#             */
/*   Updated: 2023/12/14 15:54:01 by mayeung          ###   ########.fr       */
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
			ft_rotate(sts, -1, 1, "ra\n");
		else if (from == 'a' && (sts->ra[0] & digit))
		{
			ft_push(0, sts, 1, "pb\n");
			if (digit != 1)
				ft_rotate(sts, -1, 1, "rb\n");
		}
		else if (from == 'b' && (sts->rb[0] & digit))
			ft_rotate(sts, -1, 1, "rb\n");
		else if (from == 'b' && !(sts->rb[0] & digit))
		{
			ft_push(0, sts, 1, "pa\n");
			ft_rotate(sts, -1, 1, "ra\n");
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
