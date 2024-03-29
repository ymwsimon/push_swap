/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:54:51 by mayeung           #+#    #+#             */
/*   Updated: 2024/01/03 01:01:57 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rotate(t_stac *sts, int i, int print, char *op)
{
	int	tmp;
	int	n;
	int	*rank;
	int	*stack;

	if (print)
		ft_putstr_fd(op, STDOUT_FILENO);
	n = sts->nb;
	rank = sts->rb;
	stack = sts->sb;
	if (op && op[1] == 'a')
	{
		n = sts->na;
		rank = sts->ra;
		stack = sts->sa;
	}
	tmp = rank[0];
	while (++i < n - 1 && n > 1)
		rank[i] = rank[i + 1];
	rank[i] = tmp;
	i = -1;
	tmp = stack[0];
	while (++i < n - 1 && n > 1)
		stack[i] = stack[i + 1];
	stack[i] = tmp;
}

void	ft_rr(t_stac *sts, int print, char *op)
{
	if (print)
		ft_putstr_fd(op, STDOUT_FILENO);
	ft_rotate(sts, -1, NO_PRINT, "ra\n");
	ft_rotate(sts, -1, NO_PRINT, "rb\n");
}

void	ft_rev_rotate(t_stac *sts, int i, int print, char *op)
{
	int	tmp;
	int	n;
	int	*rank;
	int	*stack;

	if (print)
		ft_putstr_fd(op, STDOUT_FILENO);
	n = sts->nb;
	rank = sts->rb;
	stack = sts->sb;
	if (op && op[2] == 'a')
	{
		n = sts->na;
		rank = sts->ra;
		stack = sts->sa;
	}
	tmp = rank[i - 1];
	while (--i > 0 && n > 1)
		rank[i] = rank[i - 1];
	rank[i] = tmp;
	i = n;
	tmp = stack[i - 1];
	while (--i > 0 && n > 1)
		stack[i] = stack[i - 1];
	stack[i] = tmp;
}

void	ft_rrr(t_stac *sts, int print, char *op)
{
	if (print)
		ft_putstr_fd(op, STDOUT_FILENO);
	ft_rev_rotate(sts, sts->na, NO_PRINT, "rra\n");
	ft_rev_rotate(sts, sts->nb, NO_PRINT, "rrb\n");
}
