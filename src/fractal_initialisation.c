#include "../inc/fractol.h"

void	fractal_initiallsation(t_fractal *fractal, char *name, int flag)
{
    // Set the fractal's flag attribute to the passed flag value.
	fractal->flag = flag;
    // Initialize the connection to the (mlx) library.
	fractal->mlx = mlx_init();
    // Create a new window with the given name, and set the window dimensions to WIDTH and HEIGHT.
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, name);
    // Create a new image in memory to draw the fractal on.
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
    // Get the address of the image's data and set up the image parameters (bits per pixel, line length, endian).
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel,
								&fractal->line_length, &fractal->endian);
	// Set the initial offsets in the complex plane for the fractal's top-left corner.
	fractal->x = 0;    // Pixel x-coordinate in the image
    fractal->y = 0;    // Pixel y-coordinate in the image
	fractal->zoom = 300; // Initial zoom level
	fractal->offset_x = -2.1;
	fractal->offset_y = -1.21;
	// Initialize other fractal parameters.
    fractal->z_y = 0;  // Imaginary part of z (used in fractal iterations)
    fractal->z_x = 0;  // Real part of z (used in fractal iterations)
    fractal->c_y = 0;  // Imaginary part of c (used in fractal iterations)
    fractal->c_x = 0;  // Real part of c (used in fractal iterations)

	// Set the maximum number of iterations
	if (flag == 3)
		fractal->max_iter = 30;
	else
		fractal->max_iter = 100;
	// Set initial color and color shifting parameters.
	fractal->color = BASE_COLOR;
	fractal->color_shift_step = (255 * 255 * 255) / 100;
	fractal->color_shift_max = 0xFFFFFF;
	fractal->color_shift_min = 0x000000;
	ft_printf("Fractal Initialized.\n");
}