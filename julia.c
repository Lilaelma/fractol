/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclarenn <aclarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:23:48 by aclarenn          #+#    #+#             */
/*   Updated: 2023/06/12 18:03:56 by aclarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	julia(t_complex c, t_complex z)
{
	double	temp;
	int		iter;

	iter = 0;
	temp = 0;
	while (iter < MAX_ITER && z.r * z.r + z.i * z.i <= 4)
	{
		temp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * temp * z.i + c.i;
		iter++;
	}
	return (get_color(iter));
}

void	draw_julia(t_mlx *mlx, t_complex c)
{
	int			x;
	int			y;
	t_complex	z;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z.r = mlx->fractal.min.r
				+ (x * (mlx->fractal.max.r - mlx->fractal.min.r) / WIDTH);
			z.i = mlx->fractal.min.i
				+ (y * (mlx->fractal.max.i - mlx->fractal.min.i) / HEIGHT);
			put_pixel(mlx, x, y, julia(c, z));
			x++;
		}
		y++;
	}
}
