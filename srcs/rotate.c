/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:54:51 by mayeung           #+#    #+#             */
/*   Updated: 2023/10/07 17:15:39 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_rotate(int n, int *st, int *rank, char *op)
{
	int	tmpst;
	int	tmpr;
	int	i;

	ft_putstr_fd(op, 1);
	if (n < 2)
		return ;
	i = 0;
	tmpst = st[i];
	tmpr = rank[i];
	while (i < n - 1)
	{
		st[i] = st[i + 1];
		rank[i] = rank[i + 1];
		i++;
	}
	st[i] = tmpst;
	rank[i] = tmpr;
}

void	ft_rr(t_stac *s, char *op)
{
	ft_putstr_fd(op, 1);
	ft_rotate(s->na, s->sa, s->ra, 0);
	ft_rotate(s->nb, s->sb, s->rb, 0);
}

void	ft_rev_rotate(int n, int *st, int *rank, char *op)
{
	int	tmpst;
	int	tmpr;
	int	i;

	ft_putstr_fd(op, 1);
	if (n < 2)
		return ;
	i = n - 1;
	tmpst = st[i];
	tmpr = rank[i];
	while (i)
	{
		st[i] = st[i - 1];
		rank[i] = rank[i - 1];
		i--;
	}
	st[i] = tmpst;
	rank[i] = tmpr;
}

void	ft_rrr(t_stac *s, char *op)
{
	ft_putstr_fd(op, 1);
	ft_rev_rotate(s->na, s->sa, s->ra, 0);
	ft_rev_rotate(s->nb, s->sb, s->rb, 0);
}
