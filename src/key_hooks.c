/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:21:20 by taretiuk          #+#    #+#             */
/*   Updated: 2024/07/14 12:48:44 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	handle_movement(int keycode, t_fractal *fractal)
{
	if (keycode == LEFT)
	{
		fractal->offset_x -= 42 / fractal->zoom;
	}
	else if (keycode == RIGHT)
	{
		fractal->offset_x += 42 / fractal->zoom;
	}
	else if (keycode == UP)
	{
		fractal->offset_y -= 42 / fractal->zoom;
	}
	else if (keycode == DOWN)
	{
		fractal->offset_y += 42 / fractal->zoom;
	}
}

void	handle_zoom(int keycode, t_fractal *fractal)
{
	if (keycode == PLUS)
	{
		fractal->zoom *= 1.1;
	}
	else if (keycode == MINUS)
	{
		fractal->zoom /= 1.1;
	}
}

void	handle_iterations(int keycode, t_fractal *fractal)
{
	if (keycode == SPACE)
	{
		fractal->max_iter += 10;
	}
	else if (keycode == BACKSPACE)
	{
		fractal->max_iter -= 10;
	}
}

void	handle_color_shift(int keycode, t_fractal *fractal)
{
	if (keycode == R)
	{
		fractal->color += fractal->color_shift_step;
		if (fractal->color > fractal->color_shift_max)
		{
			fractal->color = INITIAL_COLOR;
		}
	}
	else if (keycode == F)
	{
		fractal->color -= fractal->color_shift_step;
		if (fractal->color < fractal->color_shift_min)
		{
			fractal->color = INITIAL_COLOR;
		}
	}
	else if (keycode == T)
	{
		fractal->color = INITIAL_COLOR;
	}
}

int	key_hook(int keycode, t_fractal *fractal)
{
	if (keycode == ESC)
	{
		kill_and_free(fractal);
	}
	else
	{
		handle_movement(keycode, fractal);
		handle_zoom(keycode, fractal);
		handle_iterations(keycode, fractal);
		handle_color_shift(keycode, fractal);
		handle_color_shift_step(keycode, fractal);
		handle_reset_key(keycode, fractal);
		if (fractal->flag == 2)
		{
			handle_different_sets(keycode, fractal);
		}
	}
	make_fractal(fractal);
	ft_printf("%s", COMMANDS);
	return (0);
}
