/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktobo <mtoktobo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 13:39:41 by mtoktobo          #+#    #+#             */
/*   Updated: 2019/10/10 16:53:20 by mtoktobo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		new_str[i] = f(s[i]);
	return (new_str);
}
