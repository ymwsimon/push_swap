/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:36:39 by mayeung           #+#    #+#             */
/*   Updated: 2024/01/17 22:39:10 by mayeung          ###   ########.fr       */
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

void    quicksort(t_stac *sts, int low, int high, char from)
{
	int	med;
	int	i;
	int	rotate;

	med = (low + high + 1) / 2;
	i = low;
	rotate = 0;
	if (low > high || (low == high && from == 'a'))
		return ;
	while (i <= high && (high - low > 1 || from == 'b'))
	{
		if (from == 'a' && sts->ra[0] < med)
			ft_push(NO_UPDATE_RANK, sts, PRINT, "pb\n");
		else if (from == 'a' && sts->ra[0] >= med)
			ft_rotate(sts, -1, PRINT * ++rotate, "ra\n");
		else if (from == 'b' && sts->rb[0] >= med)
			ft_push(NO_UPDATE_RANK, sts, PRINT, "pa\n");
		else if (from == 'b' && sts->rb[0] < med)
			ft_rotate(sts, -1, PRINT * ++rotate, "rb\n");
		i++;
	}
	if (high - low == 1  && sts->ra[0] > sts->ra[1])
		ft_swap(sts, PRINT, "sa\n");
	while (rotate-- && !(low == 0 && high == (sts->na + sts->nb - 1)))
	{
		if (from == 'a')
			ft_rev_rotate(sts, sts->na, PRINT, "rra\n");
		else
			ft_rev_rotate(sts, sts->nb, PRINT, "rrb\n");
	}
	quicksort(sts, med, high, 'a');
	quicksort(sts, low, med - 1, 'b');
}

//quicksort(&sts, 0, sts.na - 1, 'a');