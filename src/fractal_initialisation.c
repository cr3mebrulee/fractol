/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_initialisation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:20:55 by taretiuk          #+#    #+#             */
/*   Updated: 2024/07/11 15:09:06 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	fractal_initiallsation(t_fractal *fractal, char *name, int flag)
{
	fractal->flag = flag;
	fractal->mlx = mlx_init();
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, name);
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel,
			&fractal->line_length, &fractal->endian);
	fractal->x = 0;
	fractal->y = 0;
	fractal->zoom = 300;
	fractal->offset_x = -2.0;
	fractal->offset_y = -1.21;
	fractal->z_y = 0;
	fractal->z_x = 0;
	fractal->c_y = 0;
	fractal->c_x = 0;
	fractal->max_iter = 100;
	fractal->color = INITIAL_COLOR;
	fractal->color_shift_step = (255 * 255 * 255) / 100;
	fractal->color_shift_max = 0xFFFFFF;
	fractal->color_shift_min = 0x000000;
	ft_printf("Fractal Initialized\n");
}
