/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tie.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktobo <mtoktobo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:58:33 by mtoktobo          #+#    #+#             */
/*   Updated: 2020/02/12 22:53:58 by mtoktobo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

#define MAX(a, b) (a > b ? a: b)
#define MOD(a) ((a < 0) ? -a : a)

float   mod(float i)
{
    return (i < 0) ? -i : i;
}

void     cubic(float *x, float *y, int z)
{
    *x = (*x - *y) * cos(0.8)
    *y = (*x + *y) * sin(0.8) - z
}
 
void    draw_line(float x, float y, float x1, float y1, fdf *data)
{
    float x_size;
    float y_size;
    int max;
    int z;
    int z1;

   z = data->z_matrix[(int)y][(int)x];
   z1 = data->z_matrix[(int)y1][(int)x1];

   //----ZOOM----
   x = x * data->zoom;
   y = y * data->zoom;
   x1 = x1 * data->zoom;
   y1 = y1 * data->zoom;

   //----COLOR-----
    data->color = (z || z1) ? 0xe80c0c : 0xffffff;
    //-----3D------
    cubic(&x, &y, z);
    cubic(&x1, &y1, z1);
    //-----shift----
    x += 150;
    y += 150;
    x1 += 150;
    y1 += 150;


    x_size = x1 - x;
    y_size = y1 - y;
    max = MAX(MOD(x_size), MOD(y_size));
    x_size /= max;
    y_size /= max;
    while ((int)(x - x1) || (int) (y - y1))
    {
        place_mlx_pxl(data->mlx_ptr, data->win_ptr, x, y, data->color)
        x = x + x_size;
        y = y + y_size;
    }
}


    x_size = x1 - x;
    y_size = y1 - y;

    void    draw(fdf *data)
    {
        int x;
        int y;

        y = 0;
        x = 0;
        while (y < data->width)
        {
            while (x < data->width)
            {
                if (x < data->width - 1)
                draw_line(x, y, x + 1, y, data);
                if (y < data->height - 1)
                draw_line(x, y, x, y + 1, data);
                x++;
            }
            y++;
        }
    }


}
