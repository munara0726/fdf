/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktobo <mtoktobo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:25:07 by mtoktobo          #+#    #+#             */
/*   Updated: 2020/02/17 20:54:37 by mtoktobo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "Libft/libft.h"
#include "minilibx_macos/mlx.h"
#include <math.h>

typedef struct
{
	int height;
	int width;
	int zoom;
	int color;
	int **z_matrix;

	void	*mlx_ptr;
	void	*win_ptr;
}			fdf;

void	read_file(char *f_name, fdf *data);
/*int		ft_height(char *f_name);
int		ft_width(char *f_name);
void	fill_matrix(int *z_line, char *line);
float   mod(float i);*/
void    draw_line(float x, float y, float x1, float y1, fdf *data);
void    draw(fdf *data);
#endif
