/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcount.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktobo <mtoktobo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 14:51:56 by mtoktobo          #+#    #+#             */
/*   Updated: 2020/02/06 14:59:24 by mtoktobo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_wcount(char const *str, char c)
{
    int word;
    int i;

    i = 0;
    word = 0;
    while (str[i] != '\0')
    {
        while (str[i] == c && str[i] != '\0')
        i++;
        if (str[i])
        word++;
        while (str[i] != c && str[i] != '\0')
        i++;
    }
    return (word);
}
