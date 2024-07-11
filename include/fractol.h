/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:45:52 by taretiuk          #+#    #+#             */
/*   Updated: 2024/07/11 14:10:16 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

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
# define INSTRUCTIONS "\n\
Usage: ./fractol --mandelbrot (-m)                \n\
                 --julia (-j) (double) (double)\n\
                 --burning-ship (-bs)          \n\
                 --help (-h)                   \n"
# define COMMANDS "Commands:\n\
				 Zoom: Shift + -\n\
				 Move: arrows\n\
				 Change color: r f t\n\
				 Change color shift step: c v b\n\
				 Reset: 1\n\
				 Randomize Julia: j\n\
				 Increase Cs (Julia): k\n\
				 Decrease Cs (Julia): l\n\
				 Exit: esc\n"

/* Constants represent the key codes for various keyboard inputs */
# define INITIAL_COLOR 365
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
	int		x;
	int		y;
	double	z_y;
	double	z_x;
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

float	ft_strtof(const char *str);
void	fractal_initiallsation(t_fractal *fractal, char *title, int flag);
int		killall_free(t_fractal *fractal);
int		set_fractal_type(char *arg);
int		check_arguments(int argc, char **argv);
void	generate_double(t_fractal *fractal);
int		key_hook(int keycode, t_fractal *fractal);
void	handle_color_shift_step(int keycode, t_fractal *fractal);
void	handle_special_keys(int keycode, t_fractal *fractal);
void	handle_other_keys(int keycode);
int		mouse_hook(int button, int x, int y, t_fractal *fractal);
void	make_fractal(t_fractal *fractal);
void	my_mlx_pixel_put(t_fractal *data, int x, int y, int color);
void	draw_infos(t_fractal *fractal);
void	draw_commands_and_infos(t_fractal *fractal);
void	draw_commands_and_infos2(t_fractal *fractal);
void	calculate_mandelbrot(t_fractal *fractal);
void	*render_mandelbrot(void *frac_void);
void	calculate_julia(t_fractal *fractal);
void	*render_julia(t_fractal *fractal);
int		julia_hook(int keycode, t_fractal *fractal);
void	reset_julia(t_fractal *fractal);

#endif
