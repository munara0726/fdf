/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktobo <mtoktobo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:31:44 by mtoktobo          #+#    #+#             */
/*   Updated: 2019/10/10 16:49:28 by mtoktobo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char*)dst;
	ptr2 = (unsigned char*)src;
	while (n > 0)
	{
		*(ptr1) = *(ptr2);
		if (*ptr2 == (unsigned char)c)
			return ((void*)(ptr1 + 1));
		ptr1++;
		ptr2++;
		n--;
	}
	return (NULL);
}
