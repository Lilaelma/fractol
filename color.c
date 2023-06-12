/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclarenn <aclarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:22:43 by aclarenn          #+#    #+#             */
/*   Updated: 2023/06/12 17:58:32 by aclarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->data + (y * mlx->size_line + x * (mlx->bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	my_argb(int a, int r, int g, int b)
{
	return (((a & 0xFF) << 24) + ((r & 0xFF) << 16)
		+ ((g & 0xFF) << 8) + (b & 0xFF));
}

int	get_color(int iter)
{
	if (iter == MAX_ITER)
		return (0);
	return (my_argb(0, (3 * iter) % 256, (1 * iter) % 256, (10 * iter) % 256));
}
