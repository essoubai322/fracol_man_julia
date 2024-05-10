/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebaai <asebaai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:16:52 by asebaai           #+#    #+#             */
/*   Updated: 2024/05/10 10:37:06 by asebaai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define MLX_ERROR 1

# define WIN_HEIGHT 500
# define WIN_WIDTH 1000

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define INDIGO 0x6F00FF
# define PINK 0xFF1493
# define MANGO_TANGO 0xFF8243
# define NEON_GREEN 0x39FF14
# define BRIGHT_YELLOW 0xFFFF00
# define PURPLE 0xBF00FF
# define SEA_GREEN 0x2E8B57
# define LIME_GREEN 0x32CD32
# define ORANGE 0xFFA500
# define AMETHYST 0x9966CC
# define CHARTREUSE 0x7FFF00
# define RED_CRIMSON 0xDC143C
# define GOLD 0xFFD700

# define ESC 65307
# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT 65361

# define A 97
# define B 98
# define C 99
# define D 100
# define E 101
# define F 102
# define G 103
# define H 104
# define I 105
# define J 106
# define K 107
# define L 108
# define M 109
# define N 110
# define O 111
# define P 112
# define Q 113
# define R 114
# define S 115
# define T 116
# define U 117
# define V 118
# define W 119
# define X 120
# define Y 121
# define Z 122

typedef struct s_complex
{
	double	re;
	double	im;
}			t_complex;

typedef struct s_fractal
{
	void	*mlx_ptr;
	void	*window_ptr;
	void	*img_ptr;
	char	*img_addr;
	int		bpp;
	int		line_len;
	int		endian;
	double	c_re;
	double	c_im;
	double	zoom;
	int		type;
	int		color;
}			t_fractal;

// functions

double		ft_atof(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		julia_fill(t_fractal *fractal);
void		julia(double x, double y, t_fractal *fractal);
t_complex	ft_polynomial_expansion(t_complex a);
t_complex	ft_add(t_complex a, t_complex b);
void		draw_on_img(double x, double y, t_fractal *fractal,
				unsigned int colour);
void		woopsies(void);
int			type_method(int ac, char **av, t_fractal *fractal);
void		selctionion(int type, t_fractal *fractal);
void		manldelbrot_fill(t_fractal *fractal);
void		mandelbrot(double x, double y, t_fractal *fractal);
void		ft_putstr(char *s);
size_t		ft_strlen(char *s);

#endif