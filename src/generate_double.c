/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:59:05 by taretiuk          #+#    #+#             */
/*   Updated: 2024/07/12 12:13:36 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	generate_double(t_fractal *fractal)
{
	if (fractal->c_x == 0 && fractal->c_y == 0)
	{
		fractal->c_x = -0.835;
		fractal->c_y = -0.2321;
		return ;
	}
	fractal->c_x *= 1.1 * 4 - 2;
	fractal->c_y *= 1.1 * 4 - 2;
	if (fractal->c_x > 2)
	{
		fractal->c_x = 0;
	}
	if (fractal->c_y > 2)
	{
		fractal->c_y = 0;
	}
	return ;
}
