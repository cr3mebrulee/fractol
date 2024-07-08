#include "../inc/fractol.h"

int	main(int argc, char **argv)
{
	int			fractal_type;
	t_fractal	*fractal;
	// Check valid arguments, set and return fractal type number
	fractal_type = check_args(argc, argv);
	fractal = malloc(sizeof(t_fractal));
	if (!fractal)
	{
		return (-1);
	}
	fractal_initiallsation(fractal, "Fractol", fractal_type);
	if (fractal_type == 2)
	{
		if (argc == 5)
		{
			fractal->c_x = ft_strtof(argv[2]);
			fractal->c_y = ft_strtof(argv[3]);
		}
		else
			random_double(fractal);
	}
	draw_fractal(fractal);
	mlx_key_hook(fractal->win, key_hook, fractal);
	mlx_mouse_hook(fractal->win, mouse_hook, fractal);
	mlx_hook(fractal->win, 17, 0L, killall_free, fractal);
	mlx_loop(fractal->mlx);
	return (0);
}
