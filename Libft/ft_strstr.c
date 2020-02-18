/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktobo <mtoktobo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:26:36 by mtoktobo          #+#    #+#             */
/*   Updated: 2019/10/10 16:55:01 by mtoktobo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;

	i = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		if (!ft_memcmp(haystack + i, needle, ft_strlen(needle)))
			return ((char*)(haystack + i));
		i++;
	}
	return (NULL);
}
