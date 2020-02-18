/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktobo <mtoktobo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:25:07 by mtoktobo          #+#    #+#             */
/*   Updated: 2020/02/13 20:30:21 by mtoktobo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "Libft/libft.h"
#include "minilibx_macos/mlx.h"

typedef struct
{
	int height;
	int width;
	int zoom;
	int colors;
	int **z_matrix;

	void	*mlx_ptr;
	void	*win_ptr;
}			fdf;

void	read_file(char *f_name, fdf *data);

#endif