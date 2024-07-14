/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:21:27 by taretiuk          #+#    #+#             */
/*   Updated: 2024/07/14 13:43:18 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	expose_hook(void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	make_fractal(fractal);
	return (0);
}

void	convert_parameters(char *s_1, char *s_2, int num, t_fractal *fractal)
{
	if (num == 4)
	{
		fractal->c_x = ft_strtof(s_1);
		fractal->c_y = ft_strtof(s_2);
	}
	else
		generate_double(fractal);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	fractal = NULL;
	fractal = malloc(sizeof(t_fractal));
	if (!fractal)
	{
		return (-1);
	}
	check_arguments(argc, argv, fractal);
	fractal_initiallisation(fractal, "Fractol", fractal->flag);
	if (fractal->flag == 2)
	{
		convert_parameters(argv[2], argv[3], argc, fractal);
	}
	make_fractal(fractal);
	mlx_key_hook(fractal->win, key_hook, fractal);
	mlx_mouse_hook(fractal->win, mouse_hook, fractal);
	mlx_hook(fractal->win, 17, 0L, close_window_hook, fractal);
	mlx_expose_hook(fractal->win, expose_hook, &fractal);
	mlx_loop(fractal->mlx);
	return (0);
}
