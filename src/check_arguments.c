/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:48:55 by taretiuk          #+#    #+#             */
/*   Updated: 2024/07/11 14:03:51 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	check_arguments(int argc, char **argv)
{
	int	fractal_number;

	if (argc < 2)
	{
		ft_printf("Usage: see ./fractal --help \n");
		ft_printf("%s", INSTRUCTIONS);
		exit(0);
	}
	if (!ft_strncmp(argv[1], "--help\0", 7) || !ft_strncmp(argv[1], "-h\0", 3))
	{
		ft_printf("%s", INSTRUCTIONS);
		exit(0);
	}
	fractal_number = set_fractal_type(argv[1]);
	if (fractal_number == 0)
	{
		ft_printf("Error: invalid argument!\n");
		ft_printf("%s", INSTRUCTIONS);
		exit(0);
	}
	return (fractal_number);
}
