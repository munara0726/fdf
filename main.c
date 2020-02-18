/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktobo <mtoktobo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 12:32:00 by mtoktobo          #+#    #+#             */
/*   Updated: 2020/02/17 20:52:16 by mtoktobo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		deal_key(int key, void *data)
{
	printf("%d", key);
	return (0);
}

int	main(int argc, char *argv[])
{
	fdf *data;

	data = (fdf*)malloc(sizeof(fdf));
	read_file(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "fils de fer");
	data->zoom = 20;
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, NULL);
	mlx_loop(data->mlx_ptr);
}
