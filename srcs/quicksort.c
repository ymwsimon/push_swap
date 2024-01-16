/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:36:39 by mayeung           #+#    #+#             */
/*   Updated: 2024/01/16 20:22:04 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    quicksort(t_stac *sts, int low, int high, char from)
{
	int  med;
	int  i;
	int  rotate;

	med = (low + high) / 2;
	i = low;
	rotate = 0;
	if (low >= high)// && from == 'a')
		return ;
	while (i <= high)
	{
		if (from == 'a' && sts->na > 0)
			ft_push(NO_UPDATE_RANK, sts, PRINT, "pb\n");
		else if (from == 'b' && sts->nb > 0)
			ft_push(NO_UPDATE_RANK, sts, PRINT, "pa\n");
		if (from == 'a' && sts->nb && sts->rb[0] > med)
		{    
			ft_rotate(sts, -1, PRINT, "rb\n");
			rotate++;
		}
		else if (from == 'b' && sts->na && sts->ra[0] <= med)
		{
			ft_rotate(sts, -1, PRINT, "ra\n");
			rotate++;
		}
		i++;
	}
	while (rotate--)
	{
		if (from == 'a')
			ft_rev_rotate(sts, sts->nb, PRINT, "rrb\n");
		else
			ft_rev_rotate(sts, sts->na, PRINT, "rra\n");
	}
	if (from == 'a')
	{
		quicksort(sts, med + 1, high, 'b');
		quicksort(sts, low, med, 'b');
	}
	else
	{
		quicksort(sts, low, med, 'a');
		quicksort(sts, med + 1, high, 'a');
	}
}