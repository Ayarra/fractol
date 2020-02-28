/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 07:03:56 by hhamdaou          #+#    #+#             */
/*   Updated: 2019/12/27 23:18:59 by hhamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	switch_fractal(int key, t_mlx *mlx)
{
	if (key == 83 || key == 84 || key == 85 ||
		key == 86 || key == 87 || key == 88)
	{
		if (key == 83)
			mlx->type = 1;
		if (key == 84)
			mlx->type = 2;
		if (key == 85)
			mlx->type = 3;
		if (key == 86)
			mlx->type = 4;
		if (key == 87)
			mlx->type = 5;
		if (key == 88)
			mlx->type = 6;
		fractal_init(mlx);
	}
}

int		validate_input(int ac, char **av)
{
	if (ac != 2)
	{
		print_error();
		return (0);
	}
	else
	{
		ft_strlower(av[1]);
		if (ft_strequ(av[1], "mandelbrot"))
			return (1);
		else if (ft_strequ(av[1], "julia"))
			return (2);
		else if (ft_strequ(av[1], "burning"))
			return (3);
		else if (ft_strequ(av[1], "duobrot"))
			return (4);
		else if (ft_strequ(av[1], "tribrot"))
			return (5);
		else if (ft_strequ(av[1], "tetrabrot"))
			return (6);
		else
			print_error();
		return (0);
	}
}

void	mlx_reset(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_HEIGHT, WIN_WIDTH);
	mlx_clear_window(mlx->mlx_ptr, mlx->win);
}

void	init_mlx(t_mlx *mlx, char *str)
{
	mlx->img.color = 16774648;
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, str);
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img_ptr,
			&mlx->img.bpp, &mlx->img.size_l, &mlx->img.endian);
}

int		main(int ac, char **av)
{
	t_mlx mlx;

	if (!(mlx.type = validate_input(ac, av)))
		return (0);
	init_mlx(&mlx, av[1]);
	fractal_set(&mlx);
	mlx_hook(mlx.win, 4, 0, &mouse_hook, &mlx);
	mlx_hook(mlx.win, 6, 0, &mouse_move, &mlx);
	mlx_hook(mlx.win, 2, 0, key_press, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
