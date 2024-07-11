/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:04:32 by taretiuk          #+#    #+#             */
/*   Updated: 2024/07/11 12:00:22 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/fractol.h"

void	my_mlx_pixel_put(t_fractal *fractal, int x, int y, int color)
{
	char	*dst;
	// Calculates dst to point to the correct location in the image buffer
	dst = fractal->addr + (y * fractal->line_length + x * (fractal->bits_per_pixel / 8));
	// Writes the color value to the memory location pointed to by dst
	*(unsigned int *)dst = color;
}

void	draw_infos(t_fractal *fractal)
{
	char	*str;

	str = ft_itoa(fractal->max_iter);
	mlx_string_put(fractal->mlx, fractal->win, 650, 30, 0xFFFFFF, "Infos:");
	mlx_string_put(fractal->mlx, fractal->win, 670, 50, 0xFFFFFF,
		"Max Iterations: ");
	mlx_string_put(fractal->mlx, fractal->win, 670, 70, 0xFFFFFF, str);
	free(str);
	str = 0;
}

void	draw_commands_and_infos(t_fractal *fractal)
{
	draw_infos(fractal);
	mlx_string_put(fractal->mlx, fractal->win, 20, 30, 0xFFFFFF,
		"Commands:");
	mlx_string_put(fractal->mlx, fractal->win, 40, 50, 0xFFFFFF,
		"Zoom: Shift + -");
	mlx_string_put(fractal->mlx, fractal->win, 40, 70, 0xFFFFFF,
		"Move: Arrows");
	mlx_string_put(fractal->mlx, fractal->win, 40, 90, 0xFFFFFF,
		"Change Colors: r f t");
	mlx_string_put(fractal->mlx, fractal->win, 40, 110, 0xFFFFFF,
		"Color Shift Step: c v b");
	mlx_string_put(fractal->mlx, fractal->win, 40, 130, 0xFFFFFF,
		"Increase Iterations: space");
	mlx_string_put(fractal->mlx, fractal->win, 40, 150, 0xFFFFFF,
		"Decrease Iterations: backspace");
	draw_commands_and_infos2(fractal);
}

void	draw_commands_and_infos2(t_fractal *fractal)
{
	mlx_string_put(fractal->mlx, fractal->win, 40, 170, 0xFFFFFF, "Reset: 1");
	if (fractal->flag == 2)
	{
		mlx_string_put(fractal->mlx, fractal->win, 40, 190, 0xFFFFFF,
			"Randomize Julia: j");
		mlx_string_put(fractal->mlx, fractal->win, 40, 210, 0xFFFFFF,
			"Increase\\Decrease Cs: k l");
		mlx_string_put(fractal->mlx, fractal->win, 40, 230, 0xFFFFFF,
			"Exit: ESC");
	}
	else
		mlx_string_put(fractal->mlx, fractal->win, 40, 190, 0xFFFFFF,
			"Exit: ESC");
}

void	make_fractal(t_fractal *fractal)
{
	if (fractal->flag == 1)
	{
		render_mandelbrot(fractal);
	}
	else if (fractal->flag == 2)
	{
		render_julia(fractal);
	}
}
