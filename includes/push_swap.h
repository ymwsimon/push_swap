/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:40:29 by mayeung           #+#    #+#             */
/*   Updated: 2023/12/15 17:54:30 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stac
{
	int	*sa;
	int	*sb;
	int	*ra;
	int	*rb;
	int	na;
	int	nb;
	int	n;
}	t_stac;

void	ft_putstr_fd(char *str, int fd);

char	*ft_trim(char *str);

int		ft_parse_num(char *str, int *res, int sign);

void	ft_destroy(t_stac *sts);

int		ft_init(int arc, char **arv, t_stac *sts, int i);

int		ft_unique(t_stac *sts);

void	ft_get_rank(int n, int *st, int *rank);

void	ft_get_rankab(t_stac *sts);

int		ft_sorted(int n, int *rank);

void	ft_swap(t_stac *sts, int print, char *op);

void	ft_ss(t_stac *sts, int print, char *op);

void	ft_rotate(t_stac *sts, int i, int print, char *op);

void	ft_rr(t_stac *sts, int print, char *op);

void	ft_rev_rotate(t_stac *sts, int i, int print, char *op);

void	ft_rrr(t_stac *sts, int print, char *op);

void	ft_shift_down(int *st, int *rst, int *nst);

void	ft_shift_up(int *st, int *rst, int *nst);

void	ft_push(int getrank, t_stac *sts, int print, char *op);

void	ft_proc_st(int digit, int times, char from, t_stac *sts);

void	ft_solve(t_stac *sts);

void	ft_ssolve_1step(t_stac *sts);

void	ft_get_new_rank(t_stac *sts, int *v, int *nr);

void	ft_ssolve_2step(t_stac *sts, int v, int nr);

void	ft_ssolve_3step(t_stac *sts);

void	ft_small_solve(t_stac *sts);

int		chunk_solve(t_stac *sts, int m, int n, int print);

#endif
