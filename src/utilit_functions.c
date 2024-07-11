/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilit_functions.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:21:50 by taretiuk          #+#    #+#             */
/*   Updated: 2024/07/10 18:49:19 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	killall_free(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	free(fractal);
	exit(1);
	return (0);
}

int	set_fractal_type(char *arg)
{
	if (!ft_strncmp(arg, "--mandelbrot\0", 13) || !ft_strncmp(arg, "-m\0", 3))
		return (1);
	else if (!ft_strncmp(arg, "--julia\0", 8) || !ft_strncmp(arg, "-j\0", 3))
		return (2);
	else
		return (0);
}
