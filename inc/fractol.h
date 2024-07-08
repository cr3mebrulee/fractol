/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <fzucconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:26:48 by fzucconi          #+#    #+#             */
/*   Updated: 2023/12/06 14:26:33 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
/****************************************************************************/
/*                               LIBRARIES                                  */
/****************************************************************************/
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <time.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

/* Defines */
# define WIDTH 800
# define HEIGHT 800
# define INSTRUCTIONS "\n\n\
/*****************************************************\\\n\
Usage: ./fractol --mandelbrot (-m)                |\n\
|                    --julia (-j) (double) (double)   |\n\
|                    --burning-ship (-bs)             |\n\
|                    --tricorn (-t)                   |\n\
|                    --help (-h)                      |\n\
\\****************************************************/\n\n"
# define COMMANDS "Commands:\n\
				 Zoom: + -\n\
				 Move: arrows\n\
				 Change color: r f t\n\
				 Change color shift step: c v b\n\
				 Reset: 1\n\
				 Randomize Julia: j\n\
				 Increase Cs (Julia): k\n\
				 Decrease Cs (Julia): l\n\
				 Exit: esc\n"

# define BASE_COLOR 265
# define C_STEP 0.001
# define ESC 65307
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364
# define PLUS 61
# define MINUS 45
# define SPACE 32
# define BACKSPACE 65288
# define ENTER 65293
# define R 114
# define F 102
# define T 116
# define C 99
# define V 118
# define B 98
# define J 106
# define K 107
# define L 108
# define ONE 49
# define WHEEL_UP 4
# define WHEEL_DOWN 5
# define LEFT_CLICK 1
# define RIGHT_CLICK 3

typedef struct s_fractal
{
	int		flag;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	offset_x;
	double	offset_y;
	// the pixel coordinates
	int		x;
	int		y;
	// the real and imaginary parts of the initial complex number z
	double	z_y;
	double	z_x;
	// the real and imaginary part of complex number c
	double	c_y;
	double	c_x;
	double	zoom;
	int		max_iter;
	int		color;
	int		color_shift;
	int		color_shift_max;
	int		color_shift_min;
	int		color_shift_step;
}	t_fractal;

/* Prototypes*/
float	ft_strtof(const char *str);
/* Utils.c*/
void	fractal_initiallsation(t_fractal *fractal, char *title, int flag);
int		killall_free(t_fractal *fractal);
int		set_fractal_type(char *arg);
int		check_args(int argc, char **argv);
void	random_double(t_fractal *fractal);
/* Key_hooks.c */
int		key_hook(int keycode, t_fractal *fractal);
void	key_hook2(int keycode, t_fractal *fractal);
void	key_hook3(int keycode, t_fractal *fractal);
void	key_hook4(int keycode, t_fractal *fractal);
void	key_hook5(int keycode, t_fractal *fractal);
/* Mouse_hooks.c */
int		mouse_hook(int button, int x, int y, t_fractal *fractal);
/* Draw.c */
void	draw_fractal(t_fractal *fractal);
void	my_mlx_pixel_put(t_fractal *data, int x, int y, int color);
void	draw_infos(t_fractal *fractal);
void	draw_commands_and_infos(t_fractal *fractal);
void	draw_commands_and_infos2(t_fractal *fractal);
/* Mandelbrot.c */
void	calculate_mandelbrot(t_fractal *fractal);
void	*draw_mandelbrot(void *frac_void);
/* Julia.c */
void	calculate_julia(t_fractal *fractal);
void	*draw_julia(t_fractal *fractal);
int		julia_hook(int keycode, t_fractal *fractal);
void	reset_julia(t_fractal *fractal);
/* Burningship.c */
void	calculate_burningship(t_fractal *fractal);
void	*draw_burningship(void *frac_void);
/* Tricorn.c */
void	calculate_tricorn(t_fractal *fractal);
void	*draw_tricorn(void *frac_void);

#endif