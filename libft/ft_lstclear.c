/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 20:53:55 by mayeung           #+#    #+#             */
/*   Updated: 2023/07/30 20:53:55 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*t;

	if (lst && del)
	{
		t = *lst;
		while (*lst)
		{
			t = *lst;
			*lst = (*lst)->next;
			del(t->content);
			free(t);
		}
		*lst = 0;
	}
}