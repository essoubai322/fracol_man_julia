/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebaai <asebaai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:01:46 by asebaai           #+#    #+#             */
/*   Updated: 2024/05/09 22:32:57 by asebaai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_on_img(double x, double y, t_fractal *fractal, unsigned int colour)
{
	unsigned int	byte_offset;

	byte_offset = (y * fractal->line_len) + (x * (fractal->bpp / 8));
	*(unsigned int *)(fractal->img_addr + byte_offset) = colour;
}

t_complex	ft_add(t_complex a, t_complex b)
{
	t_complex	c;

	c.re = a.re + b.re;
	c.im = a.im + b.im;
	return (c);
}

t_complex	ft_polynomial_expansion(t_complex a)
{
	t_complex	b;

	b.re = a.re * a.re - a.im * a.im;
	b.im = 2 * a.re * a.im;
	return (b);
}

void	julia(double x, double y, t_fractal *fractal)
{
	int				i;
	unsigned int	colour;
	t_complex		z;
	t_complex		c;

	i = 0;
	z.re = (4 * x / 900 - 2) * fractal->zoom;
	z.im = (-4 * y / 900 + 2) * fractal->zoom;
	c.re = fractal->c_re;
	c.im = fractal->c_im;
	while (i < 100)
	{
		z = ft_polynomial_expansion(z);
		z = ft_add(z, c);
		if (z.re * z.re + z.im * z.im > 4)
		{
			colour = 0xE63946 * i / 9000;
			draw_on_img(x, y, fractal, colour << (fractal->color % 16));
			return ;
		}
		i++;
	}
	draw_on_img(x, y, fractal, 0xE63946);
}

void	julia_fill(t_fractal *fractal)
{
	double	x;
	double	y;

	x = 0;
	while (x < 900)
	{
		y = 0;
		while (y < 900)
		{
			julia(x, y, fractal);
			y++;
		}
		x++;
	}
}
