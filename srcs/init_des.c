/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_des.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:53:26 by mayeung           #+#    #+#             */
/*   Updated: 2024/01/18 19:31:16 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_destroy(t_stac *sts, char **arr)
{
	int	i;

	if (sts)
	{
		free(sts->sa);
		free(sts->sb);
		free(sts->ra);
		free(sts->rb);
	}
	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}

int	ft_init(int arc, char **arv, t_stac *sts, int i)
{
	sts->sa = malloc(sizeof(int) * (arc - 1));
	sts->sb = malloc(sizeof(int) * (arc - 1));
	sts->ra = malloc(sizeof(int) * (arc - 1));
	sts->rb = malloc(sizeof(int) * (arc - 1));
	sts->na = arc;
	sts->nb = 0;
	sts->n = arc - 1;
	while (sts->n)
	{
		i++;
		sts->n /= 2;
	}
	sts->n = i;
	i = 0;
	while (i < arc)
	{
		sts->sa[i] = 0;
		if (!parse_validate_num(arv[i], &sts->sa[i], 1))
			return (0);
		i++;
	}
	ft_get_rankab(sts);
	return (1);
}
