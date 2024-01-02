/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:51:53 by mayeung           #+#    #+#             */
/*   Updated: 2024/01/02 19:51:35 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_putstr_fd(char *str, int fd)
{
	if (!str)
		return ;
	while (*str)
	{
		write(fd, str, 1);
		str++;
	}
}

char	*ft_trim(char *str)
{
	while (str && *str == ' ')
		str++;
	return (str);
}

int	ft_parse_num(char *str, int *r, int sign)
{
	if (str && *str && r)
	{
		str = ft_trim(str);
		if (*str == '-' || *str == '+')
			if (*str++ == '-')
				sign = -1;
		if (!*str)
			return (0);
		while (*str && *str >= '0' && *str <= '9')
		{
			if ((sign == 1 && (*r) * 10 < 0) || (sign == -1 && (*r) * 10 > 0))
				return (0);
			*r *= 10;
			if ((sign == 1 && *r + (*str - '0') < 0) || \
				(sign == -1 && *r + (*str - '0') * -1 > 0))
				return (0);
			*r += sign * (*str - '0');
			str++;
		}
		str = ft_trim(str);
		return (!*str);
	}
	return (0);
}

int	ft_unique(t_stac *sts)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (i < sts->na)
	{
		sum += sts->ra[i];
		i++;
	}
	return (sum == (sts->na - 1) * sts->na / 2);
}

int	ft_sorted(int n, int *rank)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (rank[i] != i)
			return (0);
		i++;
	}
	return (1);
}
