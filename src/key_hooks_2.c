/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:54:19 by taretiuk          #+#    #+#             */
/*   Updated: 2024/07/11 14:07:52 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	handle_color_shift_step(int keycode, t_fractal *fractal)
{
	if (keycode == C)
	{
		fractal->color_shift_step += 1;
		ft_printf("Increased color shift step!\n");
	}
	else if (keycode == V)
	{
		fractal->color_shift_step -= 1;
		ft_printf("Decreased color shift step!\n");
	}
	else if (keycode == B)
	{
		fractal->color_shift_step = (255 * 255 * 255) / 100;
		ft_printf("Reset color shift step!\n");
	}
}

void	handle_special_keys(int keycode, t_fractal *fractal)
{
	if (keycode == ONE)
	{
		fractal->color_shift_step = (255 * 255 * 255) / 100;
		fractal->color = INITIAL_COLOR;
		fractal->max_iter = 100;
		fractal->zoom = 300;
		fractal->offset_x = -2.1;
		fractal->offset_y = -1.21;
		ft_printf("Reset all!\n");
	}
	else if (keycode == J && fractal->flag == 2)
	{
		generate_double(fractal);
	}
}

void	handle_other_keys(int keycode)
{
	if (keycode != ENTER)
	{
		ft_printf("Unmapped key: %d\n%s\n", keycode, COMMANDS);
	}
}
