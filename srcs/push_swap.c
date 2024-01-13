/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:40:44 by mayeung           #+#    #+#             */
/*   Updated: 2024/01/13 17:17:33 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int arc, char **arv)
{
	t_stac	sts;

	if (arc == 1)
		return (0);
	if (!ft_init(arc, arv, &sts, 0) || !all_unique(&sts))
	{
		ft_destroy(&sts);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (1);
	}
	if (arc - 1 > 30)
		chunk_solve(&sts, search_chunk_size(sts), PRINT);
	else
		ft_small_solve(&sts);
	ft_destroy(&sts);
	return (0);
}
