/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 16:11:52 by hhamdaou          #+#    #+#             */
/*   Updated: 2019/12/27 21:23:09 by hhamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		convergence_checker(t_mlx *mlx, t_complex c, int max_iter)
{
	int			iter;
	t_complex	z;
	double		zx;

	if (mlx->type != 2)
	{
		z.x = 0;
		z.y = 0;
	}
	else
	{
		z.x = c.x;
		z.y = c.y;
	}
	iter = 0;
	while (z.x * z.x + z.y * z.y <= 4 && iter < max_iter)
	{
		zx = z.x;
		fractal_op1(mlx, c, &z, zx);
		fractal_op2(mlx, c, &z, zx);
		iter++;
	}
	return (iter);
}

void	fractal_put(t_mlx *mlx)
{
	t_complex	c;
	int			i;
	int			j;
	int			iterator;

	i = 0;
	j = 0;
	while (i < WIN_WIDTH)
	{
		c.y = mlx->y_max - i * (mlx->y_max - mlx->y_min) / WIN_HEIGHT;
		while (j < WIN_HEIGHT)
		{
			c.x = mlx->x_min + j * (mlx->x_max - mlx->x_min) / WIN_HEIGHT;
			iterator = convergence_checker(mlx, c, mlx->iter);
			if (iterator != mlx->iter)
				mlx->img.data[i * WIN_WIDTH + j] = iterator * mlx->img.color;
			else
				mlx->img.data[i * WIN_WIDTH + j] = 0x000000;
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
}

void	fractal_init(t_mlx *mlx)
{
	mlx->x_max = 2;
	mlx->x_min = -2;
	mlx->y_max = 2;
	mlx->y_min = -2;
	mlx->iter = 50;
	if (mlx->type == 2)
	{
		mlx->pause = 1;
		mlx->julia.x = -0.8;
		mlx->julia.y = 0.156;
	}
}

void	fractal_set(t_mlx *mlx)
{
	fractal_init(mlx);
	fractal_put(mlx);
}
