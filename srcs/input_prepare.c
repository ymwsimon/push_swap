/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_prepare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:13:44 by mayeung           #+#    #+#             */
/*   Updated: 2024/01/19 15:15:48 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_arr_size(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}

int	ft_total_num_input(int size, char ***arr)
{
	int	total_size;
	int	i;

	i = 0;
	total_size = 0;
	while (arr && i < size)
	{
		if (!ft_arr_size(arr[i]))
			return (0);
		total_size += ft_arr_size(arr[i]);
		i++;
	}
	return (total_size);
}

char	**ft_clean_up_split_arr(int size, char ***arr, int print)
{
	int	i;

	if (print)
		ft_putstr_fd("Error\n", STDERR_FILENO);
	i = 0;
	while (i < size)
	{
		ft_clean_up_split(ft_arr_size(arr[i]), arr[i]);
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	**ft_flatten_str_arr(char ***arr, int size)
{
	char	**res;
	size_t	total_size;
	int		i;
	int		j;
	int		k;

	i = 0;
	total_size = ft_total_num_input(size, arr);
	if (!total_size)
		return (ft_clean_up_split_arr(size, arr, PRINT));
	res = malloc(sizeof(char *) * (total_size + 1));
	if (!res)
		return (ft_clean_up_split_arr(size, arr, NO_PRINT));
	res[total_size] = NULL;
	i = -1;
	j = -1;
	while (++i < size)
	{
		k = -1;
		while (arr[i][++k])
			res[++j] = arr[i][k];
		free(arr[i]);
	}
	free(arr);
	return (res);
}

char	***ft_split_arr(int arc, char **arv)
{
	char	***arr;
	int		i;

	arr = malloc(sizeof(char **) * arc);
	if (!arr)
		return (NULL);
	arr[arc - 1] = NULL;
	i = 1;
	while (i < arc)
	{
		arr[i - 1] = ft_split(arv[i], ' ');
		if (!arr[i - 1])
		{
			ft_clean_up_split_arr(i - 1, arr, NO_PRINT);
			free(arr);
			return (NULL);
		}
		i++;
	}
	return (arr);
}
