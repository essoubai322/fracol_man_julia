/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebaai <asebaai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:03:27 by asebaai           #+#    #+#             */
/*   Updated: 2024/05/10 10:42:08 by asebaai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(double x, double y, t_fractal *fractal)
{
	int				i;
	unsigned int	colour;
	t_complex		z;
	t_complex		c;

	i = 0;
	c.re = (4 * x / 900 - 2) * fractal->zoom;
	c.im = (-4 * y / 900 + 2) * fractal->zoom;
	z.re = c.re;
	z.im = c.im;
	while (i < 200)
	{
		z = ft_polynomial_expansion(z);
		z = ft_add(z, c);
		if (z.re * z.re + z.im * z.im > 4)
		{
			colour = 0x76B041 * i / 50;
			draw_on_img(x, y, fractal, colour);
			return ;
		}
		i++;
	}
	draw_on_img(x, y, fractal, 0);
}

void	manldelbrot_fill(t_fractal *fractal)
{
	double	x;
	double	y;

	x = 0;
	while (x < 900)
	{
		y = 0;
		while (y < 900)
		{
			mandelbrot(x, y, fractal);
			y++;
		}
		x++;
	}
}

void	selctionion(int type, t_fractal *fractal)
{
	if (fractal->img_ptr)
		mlx_destroy_image(fractal->mlx_ptr, fractal->img_ptr);
	fractal->img_ptr = mlx_new_image(fractal->mlx_ptr, 900, 900);
	fractal->img_addr = mlx_get_data_addr(fractal->img_ptr, &fractal->bpp,
			&fractal->line_len, &fractal->endian);
	if (type == 1)
		manldelbrot_fill(fractal);
	if (type == 2)
		julia_fill(fractal);
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->window_ptr,
		fractal->img_ptr, 0, 0);
}

int	type_method(int ac, char **av, t_fractal *fractal)
{
	int	type;

	type = 0;
	if (ac == 2)
	{
		if (!ft_strncmp(av[1], "mandelbort", 10))
			type = 1;
	}
	if (ac == 4 && !ft_strncmp(av[1], "julia", 5))
	{
		fractal->c_re = ft_atof(av[2]);
		fractal->c_im = ft_atof(av[3]);
		type = 2;
	}
	fractal->zoom = 1;
	return (type);
}

void	woopsies(void)
{
	write(1, "\n\t#  The parameter is invalid. #\n", 33);
	write(1, "\n* Prototype : >> ./fractol [FRACTOL NAME] \n", 44);
	write(1, "\t\t- [FRACTOL NAME] : julia, mandelbrot\n", 39);
	write(1,
		"\n* Multi-Julia: >> ./fractol julia [ONLY NUMBER] [ONLY NUMBER]\n",
		63);
	exit(1);
}
