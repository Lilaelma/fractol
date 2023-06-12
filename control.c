/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclarenn <aclarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:24:58 by aclarenn          #+#    #+#             */
/*   Updated: 2023/06/12 18:00:15 by aclarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/fractol.h"

void	zoom(t_mlx *mlx, int x, int y, double factor)
{
	t_complex	pos;

	pos.r = mlx->fractal.min.r + x * mlx->fractal.factor.r;
	pos.i = mlx->fractal.max.i - y * mlx->fractal.factor.i;
	mlx->fractal.factor.r /= factor;
	mlx->fractal.factor.i /= factor;
	mlx->fractal.min.r = pos.r - x * mlx->fractal.factor.r;
	mlx->fractal.max.i = pos.i + y * mlx->fractal.factor.i;
	mlx->fractal.max.r = mlx->fractal.min.r + WIDTH * mlx->fractal.factor.r;
	mlx->fractal.min.i = mlx->fractal.max.i - HEIGHT * mlx->fractal.factor.i;
}

void	move(t_mlx *mlx, int direction)
{
	double	delta;

	delta = (mlx->fractal.max.r - mlx->fractal.min.r) * MOVE_FACTOR;
	if (direction == 0)
	{
		mlx->fractal.min.r -= delta;
		mlx->fractal.max.r -= delta;
	}
	else if (direction == 1)
	{
		mlx->fractal.min.i += delta;
		mlx->fractal.max.i += delta;
	}
	else if (direction == 2)
	{
		mlx->fractal.min.r += delta;
		mlx->fractal.max.r += delta;
	}
	else if (direction == 3)
	{
		mlx->fractal.min.i -= delta;
		mlx->fractal.max.i -= delta;
	}
}

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
		exit(0);
	else if (keycode == 97)
		move(mlx, 0);
	else if (keycode == 119)
		move(mlx, 1);
	else if (keycode == 100)
		move(mlx, 2);
	else if (keycode == 115)
		move(mlx, 3);
	mlx_clear_window(mlx->mlx, mlx->win);
	manage_fractal(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_mlx *mlx)
{
	(void) x;
	(void) y;
	if (button == 4)
		zoom(mlx, WIDTH / 2, HEIGHT / 2, ZOOM_FACTOR);
	else if (button == 5)
		zoom(mlx, WIDTH / 2, HEIGHT / 2, 1 / ZOOM_FACTOR);
	mlx_clear_window(mlx->mlx, mlx->win);
	manage_fractal(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}

int	close_window(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}
