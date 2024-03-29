/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:54:36 by mayeung           #+#    #+#             */
/*   Updated: 2024/01/13 17:30:37 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_stac *sts, int print, char *op)
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
	if (n < 2)
		return ;
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
	tmp = rank[0];
	rank[0] = rank[1];
	rank[1] = tmp;
}

void	ft_ss(t_stac *s, int print, char *op)
{
	if (print)
		ft_putstr_fd(op, STDOUT_FILENO);
	ft_swap(s, NO_PRINT, "sa\n");
	ft_swap(s, NO_PRINT, "sb\n");
}
