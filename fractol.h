/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclarenn <aclarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:21:34 by aclarenn          #+#    #+#             */
/*   Updated: 2023/06/12 18:25:09 by aclarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"

# define WIDTH 1200
# define HEIGHT 900
# define MAX_ITER 100
# define ZOOM_FACTOR 1.1
# define MOVE_FACTOR 0.1

typedef struct s_complex
{
	double	r;
	double	i;
}				t_complex;

typedef struct s_fractal
{
	t_complex	min;
	t_complex	max;
	t_complex	factor;
	t_complex	z;
	int			max_iter;
	int			julia;
}				t_fractal;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	t_fractal	fractal;
}				t_mlx;

void			manage_fractal(t_mlx *mlx);
void			draw_mandelbrot(t_mlx *mlx);
void			draw_julia(t_mlx *mlx, t_complex z);
void			put_pixel(t_mlx *mlx, int x, int y, int color);
unsigned int	my_argb(int a, int r, int g, int b);
int				get_color(int iter);
void			zoom(t_mlx *mlx, int x, int y, double factor);
void			move(t_mlx *mlx, int direction);
int				mouse_hook(int button, int x, int y, t_mlx *mlx);
int				key_hook(int keycode, t_mlx *mlx);
int				ft_strcmp(char *s1, char *s2);
int				ft_strcmp(char *s1, char *s2);
double			ft_atof(const char *str);
void			error_msg(void);
int				close_window(t_mlx *mlx);

#endif