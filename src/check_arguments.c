/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:48:55 by taretiuk          #+#    #+#             */
/*   Updated: 2024/07/14 13:18:29 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	set_fractal_type(char *name)
{
	if (!ft_strncmp(name, "--mandelbrot\0", 13) || !ft_strncmp(name, "-m\0", 3))
	{
		return (1);
	}
	else if (!ft_strncmp(name, "--julia\0", 8) || !ft_strncmp(name, "-j\0", 3))
	{
		return (2);
	}
	else
	{
		return (0);
	}
}

int	check_arguments(int argc, char **argv, t_fractal *fractal)
{
	if (argc < 2)
	{
		ft_printf("Usage: see ./fractal --help \n");
		ft_printf("%s", INSTRUCTIONS);
		free(fractal);
		exit(0);
	}
	if (!ft_strncmp(argv[1], "--help\0", 7) || !ft_strncmp(argv[1], "-h\0", 3))
	{
		ft_printf("%s", INSTRUCTIONS);
		free(fractal);
		exit(0);
	}
	fractal->flag = set_fractal_type(argv[1]);
	if (fractal->flag == 0)
	{
		ft_printf("Error: invalid argument!\n");
		ft_printf("%s", INSTRUCTIONS);
		free(fractal);
		exit(0);
	}
	return (0);
}
