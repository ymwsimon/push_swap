/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:40:44 by mayeung           #+#    #+#             */
/*   Updated: 2023/12/14 16:19:07 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>
#include <limits.h>

t_stac	cpy_stack(t_stac sts)
{
	t_stac	res;
	int		i;

	res.ra = malloc(sizeof(int) * sts.na);
	res.rb = malloc(sizeof(int) * sts.na);
	res.sa = malloc(sizeof(int) * sts.na);
	res.sb = malloc(sizeof(int) * sts.na);
	res.n = sts.n;
	res.na = sts.na;
	res.nb = sts.nb;
	i = 0;
	while (i < res.na)
	{
		res.ra[i] = sts.ra[i];
		res.sa[i] = sts.sa[i];
		i++;
	}
	return (res);
}

int	search_chuck_size(t_stac sts)
{
	t_stac	sts_cpy;
	int		i;
	int		steps;
	int		min_i;
	int		min_steps;

	i = sts.n - 2;
	min_i = i;
	min_steps = INT_MAX;
	while (i <= sts.n * 4)
	{
		sts_cpy = cpy_stack(sts);
		steps = chunk_solve(&sts_cpy, i, 0);
		if (steps < min_steps)
		{
			min_steps = steps;
			min_i = i;
		}
		ft_destroy(&sts_cpy);
		i++;
	}
	return (min_i);
}

int	main(int arc, char **arv)
{
	t_stac	sts;

	if (arc == 1)
		return (0);
	if (!ft_init(arc, arv, &sts, 0) || !ft_unique(&sts))
	{
		ft_destroy(&sts);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (arc - 1 > 30)
		chunk_solve(&sts, search_chuck_size(sts), 1);
	else
		ft_small_solve(&sts);
	ft_destroy(&sts);
	return (0);
}
