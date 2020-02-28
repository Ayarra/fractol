/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 19:58:43 by hhamdaou          #+#    #+#             */
/*   Updated: 2019/12/27 23:34:37 by hhamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_arrows(int key, t_mlx *mlx)
{
	if (key == 123)
	{
		mlx->x_max += 0.01;
		mlx->x_min += 0.01;
	}
	if (key == 124)
	{
		mlx->x_max -= 0.01;
		mlx->x_min -= 0.01;
	}
	if (key == 125)
	{
		mlx->y_max += 0.01;
		mlx->y_min += 0.01;
	}
	if (key == 126)
	{
		mlx->y_max -= 0.01;
		mlx->y_min -= 0.01;
	}
}

int		key_press(int key, t_mlx *mlx)
{
	if (key == 8)
		mlx->img.color += 100;
	if (key == 49)
		mlx->pause = !mlx->pause;
	if (key == 53)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
		mlx_destroy_window(mlx, mlx->win);
		ft_memdel((void **)&(mlx->mlx_ptr));
		exit(1);
	}
	if (key == 69)
		mlx->iter += 10;
	if (key == 78)
		mlx->iter -= 10;
	if (key == 15)
		fractal_init(mlx);
	move_arrows(key, mlx);
	switch_fractal(key, mlx);
	mlx_reset(mlx);
	fractal_put(mlx);
	return (0);
}

int		mouse_hook(int event, int x, int y, t_mlx *mlx)
{
	if (event == 4)
		zoom(mlx, x, y, 0.9);
	if (event == 5)
		zoom(mlx, x, y, 1.1);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_HEIGHT, WIN_WIDTH);
	mlx_clear_window(mlx->mlx_ptr, mlx->win);
	fractal_put(mlx);
	return (0);
}

int		mouse_move(int x, int y, t_mlx *mlx)
{
	if (mlx->type == 2 && mlx->pause)
	{
		mlx->julia.y = mlx->y_max - (double)y *
			(mlx->y_max - mlx->y_min) / WIN_HEIGHT;
		mlx->julia.x = mlx->x_min + (double)x *
			(mlx->x_max - mlx->x_min) / WIN_HEIGHT;
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
		mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_HEIGHT, WIN_WIDTH);
		mlx_clear_window(mlx->mlx_ptr, mlx->win);
		fractal_put(mlx);
	}
	return (0);
}

void	zoom(t_mlx *mlx, int x, int y, double scale)
{
	t_complex zoom;

	zoom.y = mlx->y_max - (double)y * (mlx->y_max - mlx->y_min) / WIN_HEIGHT;
	zoom.x = mlx->x_min + (double)x * (mlx->x_max - mlx->x_min) / WIN_HEIGHT;
	mlx->x_min = scale * (mlx->x_min - zoom.x) + zoom.x;
	mlx->x_max = scale * (mlx->x_max - zoom.x) + zoom.x;
	mlx->y_min = scale * (mlx->y_min - zoom.y) + zoom.y;
	mlx->y_max = scale * (mlx->y_max - zoom.y) + zoom.y;
}
