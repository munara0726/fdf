/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktobo <mtoktobo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:17:43 by mtoktobo          #+#    #+#             */
/*   Updated: 2019/10/10 16:54:54 by mtoktobo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		skip(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	return (i);
}

static int		len_word(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static int		count_word(char const *s, char c)
{
	int	i;
	int	n;
	int result;

	i = 0;
	n = 0;
	result = 0;
	while (s[i] != '\0')
	{
		i = i + skip(s + i, c);
		n = len_word(s + i, c);
		if (n > 0)
			result++;
		i = i + n;
	}
	return (result);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		word;
	int		len;
	char	**arr_str;

	if (!s)
		return (NULL);
	word = count_word(s, c);
	if (!(arr_str = (char**)malloc(sizeof(char*) * (word + 1))))
		return (NULL);
	i = 0;
	while (i < word)
	{
		s = s + skip(s, c);
		len = len_word(s, c);
		arr_str[i] = (char*)malloc(sizeof(char) * (len + 1));
		j = -1;
		while (++j < len)
			arr_str[i][j] = s[j];
		s = s + len;
		arr_str[i++][len] = '\0';
	}
	arr_str[word] = 0;
	return (arr_str);
}
