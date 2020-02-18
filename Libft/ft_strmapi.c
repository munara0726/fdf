/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktobo <mtoktobo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 15:55:18 by mtoktobo          #+#    #+#             */
/*   Updated: 2019/10/10 16:53:30 by mtoktobo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	size;
	char	*new_str;
	size_t	i;

	i = -1;
	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	new_str = ft_strnew(size);
	if (!new_str)
		return (NULL);
	while (s[++i])
		new_str[i] = f(i, s[i]);
	return (new_str);
}
