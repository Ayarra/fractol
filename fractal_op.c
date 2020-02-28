/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:28:56 by hhamdaou          #+#    #+#             */
/*   Updated: 2019/12/28 00:26:49 by hhamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_op1(t_mlx *mlx, t_complex c, t_complex *z, double zx)
{
	if (mlx->type == 1 || mlx->type == 3)
	{
		(*z).x = (*z).x * (*z).x - (*z).y * (*z).y + c.x;
		if (mlx->type == 1)
			(*z).y = 2 * zx * (*z).y + c.y;
		if (mlx->type == 3)
			(*z).y = -2 * fabs(zx * (*z).y) + c.y;
	}
	else if (mlx->type == 2)
	{
		(*z).x = (*z).x * (*z).x - (*z).y * (*z).y + mlx->julia.x;
		if (mlx->type == 2)
			(*z).y = 2 * zx * (*z).y + mlx->julia.y;
	}
}

void	fractal_op2(t_mlx *mlx, t_complex c, t_complex *z, double zx)
{
	if (mlx->type == 4)
	{
		(*z).x = (*z).x * (*z).x * (*z).x - 3 * (*z).x * (*z).y * (*z).y + c.x;
		(*z).y = 3 * zx * zx * (*z).y - (*z).y * (*z).y * (*z).y + c.y;
	}
	else if (mlx->type == 5)
	{
		(*z).x = (*z).x * (*z).x * (*z).x * (*z).x - 6 * (*z).x *
			(*z).x * (*z).y * (*z).y + (*z).y * (*z).y * (*z).y * (*z).y + c.x;
		(*z).y = 4 * zx * zx * zx * (*z).y - 4 * zx *
			(*z).y * (*z).y * (*z).y + c.y;
	}
	else if (mlx->type == 6)
	{
		(*z).x = (*z).x * (*z).x * (*z).x * (*z).x * (*z).x - 10 * (*z).x *
			(*z).x * (*z).x * (*z).y * (*z).y + 5 * (*z).y *
			(*z).y * (*z).y * (*z).y * (*z).x + c.x;
		(*z).y = 5 * zx * zx * zx * zx * (*z).y - 10 * zx * zx *
			(*z).y * (*z).y * (*z).y + (*z).y * (*z).y
			* (*z).y * (*z).y * (*z).y + c.y;
	}
}

void	print_error(void)
{
	ft_putendl("Usage: ./ft_fractol [fractal_name]");
	ft_putendl("FRACTALS:\n\t->mandelbrot\n\t->duobrot");
	ft_putendl("\t->tribrot\n\t->tetrabrot\n\t->julia\n\t->burning");
}
