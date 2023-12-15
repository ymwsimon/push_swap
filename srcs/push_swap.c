/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:40:44 by mayeung           #+#    #+#             */
/*   Updated: 2023/12/15 18:14:11 by mayeung          ###   ########.fr       */
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

void	search_chuck_size(t_stac sts, int *m, int *n)
{
	t_stac	sts_cpy;
	int		i;
	int		j;
	int		steps;
	int		min_steps;

	i = sts.n - 4;
	min_steps = INT_MAX;
	while (i <= sts.n * 40)
	{
		j = 1;
		while (j <= 101)
		{
			sts_cpy = cpy_stack(sts);
			steps = chunk_solve(&sts_cpy, i, j, 0);
			if (steps < min_steps)
			{
				min_steps = steps;
				*m = i;
				*n = j;
			}
			ft_destroy(&sts_cpy);
			if ((steps - min_steps) * 100 / min_steps > 20)
				break ;
			j++;
		}
		i++;
	}
}

int	main(int arc, char **arv)
{
	t_stac	sts;
	int		min_m;
	int		min_n;

	if (arc == 1)
		return (0);
	if (!ft_init(arc, arv, &sts, 0) || !ft_unique(&sts))
	{
		ft_destroy(&sts);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (arc - 1 > 30)
	{	
		search_chuck_size(sts, &min_m, &min_n);
		chunk_solve(&sts, min_m, min_n, 1);
	}
	else
		ft_small_solve(&sts);
	ft_destroy(&sts);
	return (0);
}
