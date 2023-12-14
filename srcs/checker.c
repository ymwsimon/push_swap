/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:42:28 by mayeung           #+#    #+#             */
/*   Updated: 2023/12/14 16:00:43 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

int	ft_get_cmd(char **res)
{
	char	buf[2];
	char	*tmp;

	*res = 0;
	buf[1] = 0;
	while (read(0, buf, 1) == 1)
	{
		if (buf[0] != '\n' && buf[0] != EOF)
		{
			tmp = *res;
			*res = ft_strjoin(*res, buf);
			free(tmp);
		}
		else
			return (1);
	}
	return (0);
}

int	ft_valid_cmd(char *cmd)
{
	if (!ft_strncmp(cmd, "pa", 3) || !ft_strncmp(cmd, "pb", 3) || \
		!ft_strncmp(cmd, "sa", 3) || !ft_strncmp(cmd, "sb", 3) || \
		!ft_strncmp(cmd, "ss", 3) || !ft_strncmp(cmd, "ra", 3) || \
		!ft_strncmp(cmd, "rb", 3) || !ft_strncmp(cmd, "rr", 3) || \
		!ft_strncmp(cmd, "rra", 4) || !ft_strncmp(cmd, "rrb", 4) || \
		!ft_strncmp(cmd, "rrr", 4))
		return (1);
	return (0);
}

void	ft_exe_cmd(char *cmd, t_stac *sts)
{
	if (!ft_strncmp(cmd, "pa", 3))
		ft_push(0, sts, 0, "pa\n");
	else if (!ft_strncmp(cmd, "pb", 3))
		ft_push(0, sts, 0, "pb\n");
	else if (!ft_strncmp(cmd, "sa", 3))
		ft_swap(sts, 0, "sa\n");
	else if (!ft_strncmp(cmd, "sb", 3))
		ft_swap(sts, 0, "sb\n");
	else if (!ft_strncmp(cmd, "ss", 3))
		ft_ss(sts, 0, "ss\n");
	else if (!ft_strncmp(cmd, "ra", 3))
		ft_rotate(sts, -1, 0, "ra\n");
	else if (!ft_strncmp(cmd, "rb", 3))
		ft_rotate(sts, -1, 0, "rb\n");
	else if (!ft_strncmp(cmd, "rr", 3))
		ft_rr(sts, 0, "rr\n");
	else if (!ft_strncmp(cmd, "rrr", 4))
		ft_rrr(sts, 0, "rrr\n");
	else if (!ft_strncmp(cmd, "rra", 4))
		ft_rev_rotate(sts, sts->na, 0, "rra\n");
	else if (!ft_strncmp(cmd, "rrb", 4))
		ft_rev_rotate(sts, sts->nb, 0, "rrb\n");
}

void	ft_proc(t_stac *sts)
{
	char	*cmd;

	cmd = 0;
	while (ft_get_cmd(&cmd))
	{
		if (ft_valid_cmd(cmd))
			ft_exe_cmd(cmd, sts);
		else
		{
			ft_putstr_fd("Error\n", 2);
			free(cmd);
			ft_destroy(sts);
			exit(1);
		}
		free(cmd);
	}
	ft_get_rankab(sts);
	if (sts->nb || !ft_sorted(sts->na, sts->ra))
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
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
	ft_proc(&sts);
	ft_destroy(&sts);
	return (0);
}
