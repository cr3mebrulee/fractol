/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:21:27 by taretiuk          #+#    #+#             */
/*   Updated: 2024/07/11 15:28:22 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	expose_hook(void *param)
{
	t_fractal *fractal;

	fractal = (t_fractal *)param;
	make_fractal(fractal);
	return (0);
}

int	main(int argc, char **argv)
{
	int			fractal_type;
	t_fractal	*fractal;

	fractal_type = check_arguments(argc, argv);
	fractal = malloc(sizeof(t_fractal));
	if (!fractal)
		return (-1);
	fractal_initiallsation(fractal, "Fractol", fractal_type);
	if (fractal_type == 2)
	{
		if (argc == 5)
		{
			fractal->c_x = ft_strtof(argv[2]);
			fractal->c_y = ft_strtof(argv[3]);
		}
		else
			generate_double(fractal);
	}
	make_fractal(fractal);
	mlx_key_hook(fractal->win, key_hook, fractal);
	mlx_mouse_hook(fractal->win, mouse_hook, fractal);
	mlx_hook(fractal->win, 17, 0L, killall_free, fractal);
	mlx_expose_hook(fractal->win, expose_hook, &fractal);
	mlx_loop(fractal->mlx);
	return (0);
}
