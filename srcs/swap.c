/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:54:36 by mayeung           #+#    #+#             */
/*   Updated: 2023/12/14 15:42:00 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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
	ft_swap(s, 0, "sa\n");
	ft_swap(s, 0, "sb\n");
}
