/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:21:20 by taretiuk          #+#    #+#             */
/*   Updated: 2024/07/11 14:07:45 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	handle_movement(int keycode, t_fractal *fractal)
{
	if (keycode == LEFT)
	{
		printf("Shifted left!\n");
		fractal->offset_x -= 42 / fractal->zoom;
	}
	else if (keycode == RIGHT)
	{
		fractal->offset_x += 42 / fractal->zoom;
		printf("Shifted right!\n");
	}
	else if (keycode == UP)
	{
		fractal->offset_y -= 42 / fractal->zoom;
		printf("Shifted up!\n");
	}
	else if (keycode == DOWN)
	{
		fractal->offset_y += 42 / fractal->zoom;
		printf("Shifted down!\n");
	}
}

void	handle_zoom(int keycode, t_fractal *fractal)
{
	if (keycode == PLUS)
	{
		fractal->zoom *= 1.1;
		printf("Zoomed in!\n");
	}
	else if (keycode == MINUS)
	{
		fractal->zoom /= 1.1;
		printf("Zoomed out!\n");
	}
}

void	handle_iterations(int keycode, t_fractal *fractal)
{
	if (keycode == SPACE)
	{
		printf("Increased max iterations!\n");
		fractal->max_iter += 10;
	}
	else if (keycode == BACKSPACE)
	{
		fractal->max_iter -= 10;
		printf("Decreased max iterations!\n");
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
		printf("Increased color shift!\n");
	}
	else if (keycode == F)
	{
		fractal->color -= fractal->color_shift_step;
		if (fractal->color < fractal->color_shift_min)
		{
			fractal->color = INITIAL_COLOR;
		}
		printf("Decreased color shift!\n");
	}
	else if (keycode == T)
	{
		fractal->color = INITIAL_COLOR;
		printf("Reset color shift!\n");
	}
}

int	key_hook(int keycode, t_fractal *fractal)
{
	if (keycode == ESC)
	{
		printf("ESC pressed!\n");
		killall_free(fractal);
	}
	else
	{
		handle_movement(keycode, fractal);
		handle_zoom(keycode, fractal);
		handle_iterations(keycode, fractal);
		handle_color_shift(keycode, fractal);
		handle_color_shift_step(keycode, fractal);
		handle_special_keys(keycode, fractal);
		handle_other_keys(keycode);
	}
	make_fractal(fractal);
	printf("%s", COMMANDS);
	return (0);
}
