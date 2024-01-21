/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:36:39 by mayeung           #+#    #+#             */
/*   Updated: 2024/01/21 23:23:50 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*typedef struct s_stac
{
	int	*sa;
	int	*sb;
	int	*ra;
	int	*rb;
	int	na;
	int	nb;
	int	n;
}	t_stac;
*/

void    quicksort(t_stac *sts, int low, int high, char from, int push)
{
	int	med;
	int	i;
	int	rotate;
	int	new_push;

	med = (low + high + 1) / 2;
	i = low;
	rotate = 0;
	if (low > high || (low == high && from == 'a'))// || (low == 0 && high < (sts->na + sts->nb) * 0.2))
		return ;
	while ((i <= high) && (push <= ((high - low) / 2)) && ((high - low) > 1 || from == 'b'))
	{
		if (from == 'a' && sts->ra[0] < med)
		{
			ft_push(NO_UPDATE_RANK, sts, PRINT, "pb\n");
			push++;
		}
		else if (from == 'a' && sts->ra[0] >= med && sts->ra[0] <= high)
		{
			ft_rotate(sts, -1, PRINT, "ra\n");
			rotate++;
		}
		else if (from == 'b' && sts->rb[0] >= med)
		{
			ft_push(NO_UPDATE_RANK, sts, PRINT, "pa\n");
			push++;
		}
		else if (from == 'b' && (high - low) && sts->rb[0] < med)
		{
			ft_rotate(sts, -1, PRINT, "rb\n");
			rotate++;
		}
		i++;
	}
	if (high - low == 1 && sts->ra[0] > sts->ra[1])
		ft_swap(sts, PRINT, "sa\n");
	new_push = 0;
	while (rotate-- && !(low == 0 || high == (sts->na + sts->nb - 1)))
	{
		if (high - med > 0 && from == 'a')
		{
			while (sts->ra[0] < (high + med + 1) / 2)
			{
				ft_push(NO_UPDATE_RANK, sts, PRINT, "pb\n");
				new_push++;
			}
		}
		if (from == 'a')
			ft_rev_rotate(sts, sts->na, PRINT, "rra\n");
		else
			ft_rev_rotate(sts, sts->nb, PRINT, "rrb\n");
	}
	quicksort(sts, med, high, 'a', new_push);
	quicksort(sts, low, med - 1, 'b', 0);
}

//quicksort(&sts, 0, sts.na - 1, 'a', 0);