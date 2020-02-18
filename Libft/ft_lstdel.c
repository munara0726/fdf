/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktobo <mtoktobo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:42:33 by mtoktobo          #+#    #+#             */
/*   Updated: 2019/10/10 16:49:43 by mtoktobo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*node_ptr;
	t_list	*next_ptr;

	node_ptr = *alst;
	while (node_ptr)
	{
		next_ptr = node_ptr->next;
		ft_lstdelone(&node_ptr, del);
		node_ptr = next_ptr;
	}
	*alst = NULL;
}
