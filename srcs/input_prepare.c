/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:13:44 by mayeung           #+#    #+#             */
/*   Updated: 2024/01/18 19:45:00 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int ft_arr_size(char **arr)
{
	int  i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}

char	**ft_flatten_str_arr(char ***arr, int size)
{
	char	**res;
	size_t	total_size;
	int		i;
	int		j;
	int		k;

	i = 0;
	total_size = 0;
	while (arr && i < size)
	{
		total_size += ft_arr_size(arr[i]);
		i++;
	}
	res = malloc(sizeof(char *) * (total_size + 1));
	if (!res)
		return (NULL);
	res[total_size] = NULL;
	i = 0;
	j = 0;
	while (i < size)
	{
		k = 0;
		while (arr[i][k])
		{
			res[j] = arr[i][k];
			j++;
			k++;
		}
		//free(arr[i]);
		i++;
	}
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
		// if (!arr[i - 1])
		//	cleanup arr;
		i++;
	}
	return (arr);
}