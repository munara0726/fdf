/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktobo <mtoktobo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 23:29:45 by mtoktobo          #+#    #+#             */
/*   Updated: 2019/09/26 01:39:45 by mtoktobo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int	result;

	if (!s1 || !s2)
		return (0);
	result = ft_strcmp(s1, s2);
	if (result == 0)
		return (1);
	else
		return (0);
}
