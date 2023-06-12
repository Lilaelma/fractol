/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclarenn <aclarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:04:48 by aclarenn          #+#    #+#             */
/*   Updated: 2023/06/12 18:12:59 by aclarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_fractol(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "Fract-ol");
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->data = mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->size_line, &mlx->endian);
	mlx->fractal.min.r = -2.0;
	mlx->fractal.max.r = 0.8;
	mlx->fractal.min.i = -1.12;
	mlx->fractal.max.i = 1.12;
	mlx->fractal.factor.r = (mlx->fractal.max.r - mlx->fractal.min.r)
		/ (WIDTH - 1);
	mlx->fractal.factor.i = (mlx->fractal.max.i - mlx->fractal.min.i)
		/ (HEIGHT - 1);
	mlx->fractal.max_iter = MAX_ITER;
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (!(argc == 2 && ft_strcmp(argv[1], "Mandelbrot") == 0)
		&& !(argc == 4 && ft_strcmp(argv[1], "Julia") == 0))
		error_msg();
	init_fractol(&mlx);
	if (argc == 4)
	{
		mlx.fractal.z.r = ft_atof(argv[2]);
		mlx.fractal.z.i = ft_atof(argv[3]);
		mlx.fractal.julia = 1;
	}
	manage_fractal(&mlx);
	return (0);
}
