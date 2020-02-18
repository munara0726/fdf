/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_at_the_end.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktobo <mtoktobo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:43:27 by mtoktobo          #+#    #+#             */
/*   Updated: 2019/10/10 16:49:48 by mtoktobo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_at_the_end(t_list **alst, void const *content, size_t new)
{
	t_list	*node_ptr;

	node_ptr = *alst;
	while (node_ptr->next)
		node_ptr = node_ptr->next;
	node_ptr->next = ft_lstnew(content, new);
}
