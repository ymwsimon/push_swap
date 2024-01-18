/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:40:44 by mayeung           #+#    #+#             */
/*   Updated: 2024/01/18 19:45:28 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int arc, char **arv)
{
	t_stac	sts;
	char	***arr;
	char	**inputs;

	if (arc == 1)
		return (0);
	arr = ft_split_arr(arc, arv);
	if (!arr)
		return (1);
	inputs = ft_flatten_str_arr(arr, arc - 1);
	if (!inputs)
		return (1);
	if (!ft_init(ft_arr_size(inputs), inputs, &sts, 0) || !all_unique(&sts))
	{
		ft_destroy(&sts, inputs);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (1);
	}
	if (arc - 1 > 30)
		chunk_solve(&sts, search_chunk_size(sts), PRINT);
	else
		ft_small_solve(&sts);
	ft_destroy(&sts, inputs);
	return (0);
}
