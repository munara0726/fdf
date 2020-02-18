/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktobo <mtoktobo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 21:23:02 by mtoktobo          #+#    #+#             */
/*   Updated: 2019/10/10 16:49:12 by mtoktobo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	ptr1 = (unsigned char*)dst;
	ptr2 = (unsigned char*)src;
	i = 0;
	if (dst == src)
		return (dst);
	else if (ptr2 < ptr1)
		while (++i <= len)
			ptr1[len - i] = ptr2[len - i];
	else
		while (len > 0)
		{
			*ptr1++ = *ptr2++;
			len--;
		}
	return (dst);
}
