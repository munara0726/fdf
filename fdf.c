/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktobo <mtoktobo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:24:52 by mtoktobo          #+#    #+#             */
/*   Updated: 2020/02/17 20:41:17 by mtoktobo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "Libft/libft.h"

int		ft_height(char *f_name)// get_height
{
	char *line;
	int fd;
	int height;

	fd = open(f_name, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int		ft_width(char *f_name)// get_width
{
	int fd;
	int width;
	char *line;

	fd = open(f_name, O_RDONLY, 0);
	get_next_line(fd, &line);
	width = ft_wcount(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	fill_matrix(int *z_line, char *line)
{
	int i;
	char **num;

	i = 0;
	num = ft_strsplit(line, ' ');
	while (num[i])
	{
		z_line[i] = ft_atoi(num[i]);
		free(num[i]);
		i++;
	}
	free(num);
}

void	read_file(char *f_name, fdf *data)
{
	int fd;
	char *line;
	int i;

	data->height = ft_height(f_name);
	data->width = ft_width(f_name);
	data->z_matrix = (int**)malloc(sizeof(int*) * (data->height + 1));
	i = 0;
	while (i <= data->height)
	{
		data->z_matrix[i++] = (int*)malloc(sizeof(int) * data->width + 1);
	}
	fd = open(f_name, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	close(fd);
	data->z_matrix[i] = NULL;
}
