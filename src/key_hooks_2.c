/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:54:19 by taretiuk          #+#    #+#             */
/*   Updated: 2024/07/14 12:48:40 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	handle_color_shift_step(int keycode, t_fractal *fractal)
{
	if (keycode == C)
	{
		fractal->color_shift_step += 1;
	}
	else if (keycode == V)
	{
		fractal->color_shift_step -= 1;
	}
	else if (keycode == B)
	{
		fractal->color_shift_step = (255 * 255 * 255) / 100;
	}
}

void	handle_reset_key(int keycode, t_fractal *fractal)
{
	if (keycode == ONE)
	{
		fractal->color_shift_step = (255 * 255 * 255) / 100;
		fractal->color = INITIAL_COLOR;
		fractal->max_iter = 100;
		fractal->zoom = 300;
		fractal->offset_x = -2.1;
		fractal->offset_y = -1.21;
		if (fractal->flag == 2)
		{
			fractal->zoom = 200;
			fractal->offset_x = -2.0;
			fractal->offset_y = -2.0;
		}
		fractal->c_x = -0.835;
		fractal->c_y = -0.2321;
	}
}

void	handle_different_sets(int keycode, t_fractal *fractal)
{
	if (keycode == L)
	{
		fractal->c_x += C_STEP;
	}
	else if (keycode == K)
	{
		fractal->c_x -= C_STEP;
	}
	else if (keycode == I)
	{
		fractal->c_y -= C_STEP;
	}
	else if (keycode == O)
	{
		fractal->c_y += C_STEP;
	}
}
