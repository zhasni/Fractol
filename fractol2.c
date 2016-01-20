/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 20:26:20 by zhasni            #+#    #+#             */
/*   Updated: 2015/01/23 10:57:10 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_julia_4(double zr, double zi, int it_max, t_env *env)
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
		zr = (zr * zr * zr * zr) - 6 * (zr * zr * zi * zi) + (zi * zi *
			zi * zi) + cr;
		zi = 4 * (tmp * tmp * tmp * zi) - 4 * (tmp * zi * zi * zi) + ci;
		color++;
	}
	if (color == it_max)
		return (env->color * color << 2);
	return (env->color * color << 1);
}

int			ft_mandel_4(double zr, double zi, int it_max, t_env *env)
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
		zr = (zr * zr * zr * zr) - 6 * (zr * zr * zi * zi) + (zi * zi *
			zi * zi) + cr;
		zi = 4 * (tmp * tmp * tmp * zi) - 4 * (tmp * zi * zi * zi) + ci;
		color++;
	}
	if (color == it_max)
		return (env->color * color << 1);
	return (env->color * color << 2);
}

int			ft_julia_5(double zr, double zi, int it_max, t_env *env)
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
		zr = (zr * zr * zr * zr * zr) - 10 * (zr * zr * zr * zi * zi) + 5 *
			(zr * zi * zi * zi * zi) + cr;
		zi = 5 * (tmp * tmp * tmp * tmp * zi) - 10 * (tmp * tmp * zi * zi * zi)
			+ (zi * zi * zi * zi * zi) + ci;
		color++;
	}
	if (color == it_max)
		return (env->color * color << 1);
	return (env->color * color << 2);
}

int			ft_mandel_5(double zr, double zi, int it_max, t_env *env)
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
		zr = (zr * zr * zr * zr * zr) - 10 * (zr * zr * zr * zi * zi) + 5 *
			(zr * zi * zi * zi * zi) + cr;
		zi = 5 * (tmp * tmp * tmp * tmp * zi) - 10 * (tmp * tmp * zi * zi * zi)
			+ (zi * zi * zi * zi * zi) + ci;
		color++;
	}
	if (color == it_max)
		return (env->color * color << 2);
	return (env->color * color << 1);
}

int			ft_mandelbar(double zr, double zi, int it_max, t_env *env)
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
		zr = zi * zi - zr * zr - cr;
		zi = 2 * tmp * zi - ci;
		color++;
	}
	if (color != it_max)
		return (env->color * color << 1);
	return (env->color * color << 2);
}
