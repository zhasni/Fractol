/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 19:20:54 by zhasni            #+#    #+#             */
/*   Updated: 2015/01/20 20:34:02 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_julia(double zr, double zi, int it_max, t_env *env)
{
	double	cr;
	double	ci;
	int		color;
	double	tmp;

	env->motion = 1;
	cr = env->cr;
	ci = env->ci;
	color = 0;
	while (color <= it_max && (zr * zr + zi * zi) < 4)
	{
		tmp = zr;
		zr = zr * zr - zi * zi + cr;
		zi = 2 * tmp * zi + ci;
		color++;
	}
	if (color != it_max)
		return (env->color * color << 2);
	return (env->color * color << 1);
}

int			ft_mandel(double zr, double zi, int it_max, t_env *env)
{
	double	cr;
	double	ci;
	int		color;
	double	tmp;

	env->motion = 0;
	cr = zr;
	ci = zi;
	color = 0;
	while (color <= it_max && (zr * zr + zi * zi) <= 4)
	{
		tmp = zr;
		zr = zr * zr - zi * zi + cr;
		zi = 2 * tmp * zi + ci;
		color++;
	}
	if (color != it_max)
		return (env->color * color << 1);
	return (env->color * color << 2);
}

void		ft_carpet(int x, int y, t_env *env)
{
	int tmp_x;
	int tmp_y;

	tmp_x = x;
	tmp_y = y;
	x = x / env->power;
	y = y / env->power;
	if (!((x / 1) % 3 == 1 && (y / 1) % 3 == 1)
		&& !((x / 3) % 3 == 1 && (y / 3) % 3 == 1)
			&& !((x / 9) % 3 == 1 && (y / 9) % 3 == 1)
				&& !((x / 27) % 3 == 1 && (y / 27) % 3 == 1)
					&& !((x / 81) % 3 == 1 && (y / 81) % 3 == 1))
		ft_put_pixel_to_image(env, tmp_x, tmp_y, (env->color * x));
	else
		ft_put_pixel_to_image(env, tmp_x, tmp_y, (env->color * y));
}

int			ft_julia_3(double zr, double zi, int it_max, t_env *env)
{
	double	cr;
	double	ci;
	int		color;
	double	tmp;

	env->motion = 1;
	cr = env->cr;
	ci = env->ci;
	color = 0;
	while (color <= it_max && (zr * zr + zi * zi) <= 4)
	{
		tmp = zr;
		zr = zr * zr * zr - 3 * zr * zi * zi + cr;
		zi = 3 * tmp * tmp * zi - zi * zi * zi + ci;
		color++;
	}
	if (color != it_max)
		return (env->color * color << 1);
	return (env->color * color << 2);
}

int			ft_mandel_3(double zr, double zi, int it_max, t_env *env)
{
	double	cr;
	double	ci;
	int		color;
	double	tmp;

	env->motion = 0;
	cr = zr;
	ci = zi;
	color = 0;
	while (color <= it_max && (zr * zr + zi * zi) <= 4)
	{
		tmp = zr;
		zr = zr * zr * zr - 3 * zr * zi * zi + cr;
		zi = 3 * tmp * tmp * zi - zi * zi * zi + ci;
		color++;
	}
	if (color != it_max)
		return (env->color * color << 2);
	return (env->color * color << 1);
}
