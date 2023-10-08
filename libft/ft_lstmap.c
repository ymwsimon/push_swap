/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 20:54:13 by mayeung           #+#    #+#             */
/*   Updated: 2023/07/30 20:54:13 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n;
	void	*c;

	n = 0;
	while (lst && f && del)
	{
		c = (*f)(lst -> content);
		ft_lstadd_back(&n, ft_lstnew(c));
		if (ft_lstlast(n)->content != c)
		{
			ft_lstclear(&n, del);
			return (n);
		}
		lst = lst -> next;
	}
	return (n);
}
