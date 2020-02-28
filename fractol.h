/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 07:08:51 by hhamdaou          #+#    #+#             */
/*   Updated: 2019/12/27 21:57:25 by hhamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# define WIN_WIDTH 600
# define WIN_HEIGHT 600

typedef struct	s_complex
{
	double		x;
	double		y;
}				t_complex;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
	int			color;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
	int			type;
	double		x_max;
	double		y_max;
	double		x_min;
	double		y_min;
	int			iter;
	int			pause;
	t_complex	julia;
	t_img		img;
}				t_mlx;

void			mlx_reset(t_mlx *mlx);
void			fractal_set(t_mlx *mlx);
void			fractal_init(t_mlx *mlx);
void			fractal_put(t_mlx *mlx);
int				convergence_checker(t_mlx *mlx, t_complex c, int max_iter);
int				key_press(int key, t_mlx *mlx);
int				mouse_hook(int event, int x, int y, t_mlx *mlx);
int				mouse_move(int x, int y, t_mlx *mlx);
void			zoom(t_mlx *mlx, int x, int y, double scale);
void			switch_fractal(int key, t_mlx *mlx);
void			fractal_op1(t_mlx *mlx, t_complex c, t_complex *z, double zx);
void			fractal_op2(t_mlx *mlx, t_complex c, t_complex *z, double zx);
void			print_error(void);
#endif
