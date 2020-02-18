/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktobo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:36:18 by mtoktobo          #+#    #+#             */
/*   Updated: 2020/01/24 16:00:48 by mtoktobo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_join(char **dst, char *src)
{
	char *tmp;

	tmp = *dst;
	*dst = ft_strjoin(*dst, src);
	free(tmp);
	return (*dst);
}

static void		ft_help(char **dst, char *src)
{
	char *p_n;

	p_n = ft_strchr(src, '\n');
	if (p_n)
		*dst = ft_strsub(src, 0, p_n - src);
	else
		*dst = ft_strdup(src);
}

int				get_next_line(const int fd, char **line)
{
	static char	*rem[4096];
	char		buf[BUFF_SIZE + 1];
	int			len;
	char		*tmp;

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	(!rem[fd]) ? rem[fd] = ft_strnew(1) : ft_bzero(buf, BUFF_SIZE + 1);
	while ((len = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[len] = '\0';
		ft_join(&rem[fd], buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	ft_help(line, rem[fd]);
	if (ft_strchr(rem[fd], '\n'))
	{
		tmp = rem[fd];
		rem[fd] = ft_strdup(ft_strchr(rem[fd], '\n') + 1);
		ft_strdel(&tmp);
	}
	else
		ft_strdel(&rem[fd]);
	return ((len == 0 && *line[0] == '\0' && rem[fd] == NULL) ? 0 : 1);
}

int main()
{
	int fd;
	char *line;
	
	while(1)
		;
	return 0;
}
