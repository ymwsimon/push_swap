/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:40:29 by mayeung           #+#    #+#             */
/*   Updated: 2024/01/19 15:04:27 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define PRINT 1
# define NO_PRINT 0
# define UPDATE_RANK 1
# define NO_UPDATE_RANK 0

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

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

char	*next_non_space(char *str);

int		parse_validate_num(char *str, int *res, int sign);

void	ft_destroy(t_stac *sts, char **arr);

int		ft_init(int arc, char **arv, t_stac *sts, int i);

int		all_unique(t_stac *sts);

void	ft_get_rank(int n, int *st, int *rank);

void	ft_get_rankab(t_stac *sts);

int		all_sorted(int n, int *rank);

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

int		chunk_solve(t_stac *sts, double m, int print);

int		min_r(int *r, int n);

int		max_r(int *r, int n);

int		pos_r(int *r, int n, int rank);

int		need_ra(t_stac *s, int lrank);

int		need_rb(t_stac *s);

int		can_pa(t_stac *s, int lrank);

int		need_rra(t_stac *s, int lrank);

int		need_rrb(t_stac *s);

double	search_chunk_size(t_stac sts);

t_stac	cpy_stack(t_stac sts);

char	**ft_split(char const *s, char c);

char	**ft_flatten_str_arr(char ***arr, int size);

int		ft_arr_size(char **arr);

char	***ft_split_arr(int arc, char **arv);

char	**ft_clean_up_split(size_t k, char **arr);

char	**ft_clean_up_split_arr(int k, char ***arr, int print);

#endif
