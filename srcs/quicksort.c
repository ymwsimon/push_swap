/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:36:39 by mayeung           #+#    #+#             */
/*   Updated: 2024/01/17 12:56:12 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    quicksort(t_stac *sts, int low, int high, char from)
{
	int	med;
	int	i;
	int	rotate;

	med = (low + high + 1) / 2;
	i = low;
	rotate = 0;
	if (low >= high)
		return ;
	while (i <= high && (high - low > 0 || from == 'b'))
	{
		if (from == 'a' && sts->na && sts->ra[0] < med)
			ft_push(NO_UPDATE_RANK, sts, PRINT, "pb\n");
		else if (from == 'a' && sts->na && sts->ra[0] >= med)
			ft_rotate(sts, -1, PRINT * ++rotate, "ra\n");
		else if (from == 'b' && sts->nb && sts->rb[0] >= med)
			ft_push(NO_UPDATE_RANK, sts, PRINT, "pa\n");
		else if (from == 'b' && sts->nb && sts->rb[0] < med)
			ft_rotate(sts, -1, PRINT * ++rotate, "rb\n");
		i++;
	}
	if (high - low == 1 && sts->na > 1 && sts->ra[0] > sts->ra[1])
		ft_swap(sts, PRINT, "sa\n");
	while (rotate--)
	{
		if (from == 'a')
			ft_rev_rotate(sts, sts->na, PRINT, "rra\n");
		else
			ft_rev_rotate(sts, sts->nb, PRINT, "rrb\n");
	}
	if (from == 'a')
	{	
		quicksort(sts, med, high, 'a');
		quicksort(sts, low, med - 1, 'b');
	}
	else
	{
		quicksort(sts, low, med - 1, 'b');
		quicksort(sts, med, high, 'a');
	}
}