/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebaai <asebaai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:20:31 by asebaai           #+#    #+#             */
/*   Updated: 2024/05/10 10:31:55 by asebaai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	explode(t_fractal *fractal)
{
	if (fractal->img_ptr)
		mlx_destroy_image(fractal->mlx_ptr, fractal->img_ptr);
	mlx_destroy_window(fractal->mlx_ptr, fractal->window_ptr);
	mlx_destroy_display(fractal->mlx_ptr);
	free(fractal->mlx_ptr);
	exit(0);
}

int	exit_button(t_fractal *fractal)
{
	explode(fractal);
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (mousecode == 4)
		fractal->zoom *= 0.9;
	if (mousecode == 5)
		fractal->zoom *= 1.1;
	selctionion(fractal->type, fractal);
	return (0);
}

int	key_hook(int keysym, t_fractal *fractal)
{
	if (keysym == 65307)
		explode(fractal);
	else if (keysym == 'y')
		fractal->color += 1;
	selctionion(fractal->type, fractal);
	return (0);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	fractal.type = type_method(ac, av, &fractal);
	if (fractal.type)
	{
		fractal.mlx_ptr = mlx_init();
		fractal.window_ptr = mlx_new_window(fractal.mlx_ptr, 900, 900, "APA!");
		fractal.img_ptr = mlx_new_image(fractal.mlx_ptr, 900, 900);
		selctionion(fractal.type, &fractal);
		mlx_key_hook(fractal.window_ptr, key_hook, &fractal);
		mlx_mouse_hook(fractal.window_ptr, mouse_hook, &fractal);
		mlx_hook(fractal.window_ptr, 17, 1L << 17, exit_button, &fractal);
		mlx_loop(fractal.mlx_ptr);
	}
	else
		woopsies();
}
