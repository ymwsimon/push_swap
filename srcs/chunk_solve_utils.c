/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_solve_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:53:46 by mayeung           #+#    #+#             */
/*   Updated: 2024/01/03 01:00:28 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	min_r(int *r, int n)
{
	int	i;
	int	res;

	if (!n || !r)
		return (-1);
	res = r[0];
	i = 1;
	while (r && i < n)
	{
		if (r[i] < res)
			res = r[i];
		i++;
	}
	return (res);
}

int	max_r(int *r, int n)
{
	int	i;
	int	res;

	res = r[0];
	i = 1;
	while (r && i < n)
	{
		if (r[i] > res)
			res = r[i];
		i++;
	}
	return (res);
}

int	pos_r(int *r, int n, int rank)
{
	int	i;

	i = 0;
	while (i < n && r && r[i] != rank)
		i++;
	if (i == n)
		return (-1);
	return (i);
}
