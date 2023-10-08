/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:54:36 by mayeung           #+#    #+#             */
/*   Updated: 2023/10/07 17:16:06 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_swap(int n, int *st, int *rank, char *op)
{
	int	tmp;

	ft_putstr_fd(op, 1);
	if (n < 2)
		return ;
	tmp = st[0];
	st[0] = st[1];
	st[1] = tmp;
	tmp = rank[0];
	rank[0] = rank[1];
	rank[1] = tmp;
}

void	ft_ss(t_stac *s, char *op)
{
	ft_putstr_fd(op, 1);
	ft_swap(s->na, s->sa, s->ra, 0);
	ft_swap(s->nb, s->sb, s->rb, 0);
}
