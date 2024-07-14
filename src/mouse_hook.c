/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 12:08:17 by taretiuk          #+#    #+#             */
/*   Updated: 2024/07/14 12:08:20 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	mouse_hook(int button, int x, int y, t_fractal *fractal)
{
	double	pre_zoom_x;
	double	pre_zoom_y;
	double	scale_factor;

	pre_zoom_x = (x / fractal->zoom) + fractal->offset_x;
	pre_zoom_y = (y / fractal->zoom) + fractal->offset_y;
	if (button == WHEEL_UP || button == LEFT_CLICK)
	{
		scale_factor = 1.1f;
		fractal->zoom *= scale_factor;
	}
	else if (button == WHEEL_DOWN || button == RIGHT_CLICK)
	{
		scale_factor = 1 / 1.1f;
		fractal->zoom /= 1.1f;
	}
	fractal->offset_x = pre_zoom_x - (x / fractal->zoom);
	fractal->offset_y = pre_zoom_y - (y / fractal->zoom);
	make_fractal(fractal);
	return (0);
}
