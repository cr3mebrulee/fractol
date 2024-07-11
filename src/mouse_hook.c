/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:21:02 by taretiuk          #+#    #+#             */
/*   Updated: 2024/07/11 10:50:23 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	mouse_hook(int button, int x, int y, t_fractal *fractal)
{
	if (button == WHEEL_UP || button == LEFT_CLICK)
	{
		fractal->zoom *= 1.1f;
		fractal->offset_x -= ((WIDTH / 2) - x) / fractal->zoom;
		fractal->offset_y -= ((HEIGHT / 2) - y) / fractal->zoom;
	}
	else if (button == WHEEL_DOWN || button == RIGHT_CLICK)
	{
		fractal->zoom /= 1.1f;
		fractal->offset_x += (x - (WIDTH / 2)) / fractal->zoom;
		fractal->offset_y += (y - (HEIGHT / 2)) / fractal->zoom;
	}
	printf("Button pressed: %d\n", button);
	draw_fractal(fractal);
	return (0);
}
