/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclarenn <aclarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:14:50 by aclarenn          #+#    #+#             */
/*   Updated: 2023/06/12 18:15:14 by aclarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	mandelbrot(t_complex c)
{
	t_complex	z;
	double		tmp;
	int			iter;

	z.r = 0;
	z.i = 0;
	iter = 0;
	while (z.r * z.r + z.i * z.i <= 4 && iter < MAX_ITER)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * tmp * z.i + c.i;
		iter++;
	}
	return (get_color(iter));
}

void	draw_mandelbrot(t_mlx *mlx)
{
	int			x;
	int			y;
	t_complex	c;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.r = mlx->fractal.min.r + x * mlx->fractal.factor.r;
			c.i = mlx->fractal.max.i - y * mlx->fractal.factor.i;
			put_pixel(mlx, x, y, mandelbrot(c));
			x++;
		}
		y++;
	}
}
