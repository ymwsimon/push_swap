/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:55:30 by mayeung           #+#    #+#             */
/*   Updated: 2023/10/07 17:17:18 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_shift_down(int *st, int *rst, int *nst)
{
	int	i;

	i = *nst;
	while (i)
	{
		st[i] = st[i - 1];
		rst[i] = rst[i - 1];
		i--;
	}
	(*nst)++;
}

void	ft_shift_up(int *st, int *rst, int *nst)
{
	int	i;

	i = 0;
	(*nst)--;
	while (i < *nst)
	{
		st[i] = st[i + 1];
		rst[i] = rst[i + 1];
		i++;
	}
}

void	ft_push(char c, int getrank, t_stac *sts, char *op)
{
	ft_putstr_fd(op, 1);
	if (c == 'a' && sts->nb > 0)
	{
		ft_shift_down(sts->sa, sts->ra, &sts->na);
		sts->sa[0] = sts->sb[0];
		sts->ra[0] = sts->rb[0];
		ft_shift_up(sts->sb, sts->rb, &sts->nb);
	}
	else if (c == 'b' && sts->na > 0)
	{
		ft_shift_down(sts->sb, sts->rb, &sts->nb);
		sts->sb[0] = sts->sa[0];
		sts->rb[0] = sts->ra[0];
		ft_shift_up(sts->sa, sts->ra, &sts->na);
	}
	if (getrank)
		ft_get_rankab(sts);
}
