/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_des.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:53:26 by mayeung           #+#    #+#             */
/*   Updated: 2023/10/07 13:48:35 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_destroy(t_stac *sts)
{
	if (!sts)
		return ;
	free(sts->sa);
	free(sts->sb);
	free(sts->ra);
	free(sts->rb);
}

int	ft_init(int arc, char **arv, t_stac *sts, int i)
{
	sts->sa = malloc(sizeof(int) * (arc - 1));
	sts->sb = malloc(sizeof(int) * (arc - 1));
	sts->ra = malloc(sizeof(int) * (arc - 1));
	sts->rb = malloc(sizeof(int) * (arc - 1));
	sts->na = arc - 1;
	sts->nb = 0;
	sts->n = arc - 2;
	while (sts->n)
	{
		i++;
		sts->n /= 2;
	}
	sts->n = i;
	i = 0;
	while (i < arc - 1)
	{
		sts->sa[i] = 0;
		if (!ft_parse_num(arv[i + 1], &sts->sa[i], 1))
			return (0);
		i++;
	}
	ft_get_rankab(sts);
	return (1);
}
