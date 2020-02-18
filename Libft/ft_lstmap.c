/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktobo <mtoktobo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:44:53 by mtoktobo          #+#    #+#             */
/*   Updated: 2019/10/10 16:49:36 by mtoktobo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_lst;
	t_list *current;
	t_list *new_elem;

	new_lst = f(lst);
	lst = lst->next;
	current = new_lst;
	while (lst)
	{
		new_elem = f(lst);
		if (new_elem == NULL)
			return (NULL);
		current->next = new_elem;
		current = current->next;
		lst = lst->next;
	}
	return (new_lst);
}
