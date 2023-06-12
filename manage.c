/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclarenn <aclarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:08:45 by aclarenn          #+#    #+#             */
/*   Updated: 2023/06/12 18:10:00 by aclarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	manage_fractal(t_mlx *mlx)
{
	if (mlx->fractal.julia == 0)
		draw_mandelbrot(mlx);
	else
		draw_julia(mlx, mlx->fractal.z);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_hook(mlx->win, 2, 1L << 0, key_hook, mlx);
	mlx_hook(mlx->win, 4, 1L << 2, mouse_hook, mlx);
	mlx_hook(mlx->win, 17, 0, &close_window, mlx);
	mlx_loop(mlx->mlx);
}
