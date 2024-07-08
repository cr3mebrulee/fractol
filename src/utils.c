
#include "../inc/fractol.h"

int	killall_free(t_fractal *fractal)
{
	ft_printf("ESC pressed!\n");
	ft_printf("Killing all processes...\n");
	mlx_destroy_image(fractal->mlx, fractal->img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	free(fractal);
	ft_printf("Memory Cleared.\nExiting...\n");
	exit(1);
	return (0);
}

//  Ser the number of fractal type
int	set_fractal_type(char *arg)
{
	if (!ft_strncmp(arg, "--mandelbrot\0", 13) || !ft_strncmp(arg, "-m\0", 3))
		return (1);
	else if (!ft_strncmp(arg, "--julia\0", 8) || !ft_strncmp(arg, "-j\0", 3))
		return (2);
	else if (!ft_strncmp(arg, "--burning-ship\0", 15)
		|| !ft_strncmp(arg, "-bs\0", 4))
		return (3);
	else if (!ft_strncmp(arg, "--tricorn\0", 10) || !ft_strncmp(arg, "-t\0", 3))
		return (4);
	else
		return (0);
}

// Check arguments validality and return the number of fractal type
int	check_args(int argc, char **argv)
{
	int	fractal_number;

	if (argc < 2)
	{
		ft_printf("Usage: specify fractal type!\n");
		ft_printf("%s", INSTRUCTIONS);
		exit(1);
	}
	if (!ft_strncmp(argv[1], "--help\0", 7) || !ft_strncmp(argv[1], "-h\0", 3))
	{
		ft_printf("%s", INSTRUCTIONS);
		exit(1);
	}
	fractal_number = set_fractal_type(argv[1]);
	if (fractal_number == 0)
	{
		ft_printf("Error: invalid argument!\n");
		ft_printf("%s", INSTRUCTIONS);
		exit(1);
	}
	return (fractal_number);
}

void	random_double(t_fractal *fractal)
{
	if (fractal->c_x == 0 && fractal->c_y == 0)
	{
		fractal->c_x = 0;
		fractal->c_y = 0.138240;
		return ;
	}
	fractal->c_x *= 1.1 * 4 - 2;
	fractal->c_y *= 1.1 * 4 - 2;
	if (fractal->c_x > 2)
		fractal->c_x = 0;
	if (fractal->c_y > 2)
		fractal->c_y = 0;
}
