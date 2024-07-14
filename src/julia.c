/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:21:13 by taretiuk          #+#    #+#             */
/*   Updated: 2024/07/14 12:44:10 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	reset_julia(t_fractal *fractal)
{
	fractal->c_x = 0.0;
	fractal->c_y = 0.138240;
	fractal->color_shift_step = (255 * 255 * 255) / 100;
	fractal->color = INITIAL_COLOR;
	fractal->max_iter = 100;
	fractal->zoom = 300;
	fractal->offset_x = -2.1;
	fractal->offset_y = -1.21;
	ft_printf("Reset Julia!\n");
}

void	get_plane_coordinates(t_fractal *fractal, double pixel_y)
{
	double	zoom;
	int		pixel_x;
	double	offset_x;
	double	offset_y;

	zoom = fractal->zoom;
	pixel_x = fractal->x;
	offset_x = fractal->offset_x;
	offset_y = fractal->offset_y;
	fractal->z_x = (pixel_x / zoom) + offset_x;
	fractal->z_y = (pixel_y / zoom) + offset_y;
}

int	iterate_coordinates(t_fractal *fractal, int i)
{
	double	x_tmp;
	double	z_x_squared;
	double	z_y_squared;

	z_x_squared = fractal->z_x * fractal->z_x;
	z_y_squared = fractal->z_y * fractal->z_y;
	while (i < fractal->max_iter && (z_x_squared + z_y_squared) < 4)
	{
		x_tmp = fractal->z_x;
		fractal->z_x = z_x_squared - z_y_squared + fractal->c_x;
		fractal->z_y = 2.0 * x_tmp * fractal->z_y + fractal->c_y;
		z_x_squared = fractal->z_x * fractal->z_x;
		z_y_squared = fractal->z_y * fractal->z_y;
		i++;
	}
	return (i);
}

void	calculate_julia(t_fractal *fractal)
{
	double	flipped_y;
	int		i;

	i = 1;
	flipped_y = HEIGHT - fractal->y - 1;
	get_plane_coordinates(fractal, flipped_y);
	i = iterate_coordinates(fractal, i);
	if (i == fractal->max_iter)
	{
		my_mlx_pixel_put(fractal, fractal->x, fractal->y, 0x000000);
	}
	else
	{
		my_mlx_pixel_put(fractal, fractal->x, fractal->y, (i * fractal->color));
	}
}

void	*render_julia(t_fractal *fractal)
{
	fractal->x = 0;
	while (fractal->x < WIDTH)
	{
		fractal->y = 0;
		while (fractal->y < HEIGHT)
		{
			calculate_julia(fractal);
			fractal->y++;
		}
		fractal->x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
	draw_commands_and_infos(fractal);
	return (NULL);
}
