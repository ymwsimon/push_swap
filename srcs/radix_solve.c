/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:58:20 by mayeung           #+#    #+#             */
/*   Updated: 2024/01/03 01:02:12 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_proc_st(int digit, int times, char from, t_stac *sts)
{
	int	i;

	i = 0;
	while (i < times)
	{
		if (from == 'a' && !(sts->ra[0] & digit))
			ft_rotate(sts, -1, PRINT, "ra\n");
		else if (from == 'a' && (sts->ra[0] & digit))
		{
			ft_push(NO_UPDATE_RANK, sts, PRINT, "pb\n");
			if (digit != 1)
				ft_rotate(sts, -1, PRINT, "rb\n");
		}
		else if (from == 'b' && (sts->rb[0] & digit))
			ft_rotate(sts, -1, PRINT, "rb\n");
		else if (from == 'b' && !(sts->rb[0] & digit))
		{
			ft_push(NO_UPDATE_RANK, sts, PRINT, "pa\n");
			ft_rotate(sts, -1, PRINT, "ra\n");
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
