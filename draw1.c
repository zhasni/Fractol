/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 18:57:38 by zhasni            #+#    #+#             */
/*   Updated: 2015/01/20 20:14:01 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_draw_julia(t_env *env)
{
	int		x;
	int		y;

	x = 0;
	while (x < SCREEN_X)
	{
		y = 0;
		while (y < SCREEN_Y)
		{
			env->zoom_x = 1.5 * (x - SCREEN_X / 2) / (0.5 * env->zoom *
				SCREEN_X) + env->move_x;
			env->zoom_y = (y - SCREEN_Y / 2) / (0.5 * env->zoom * SCREEN_Y)
				+ env->move_y;
			ft_put_pixel_to_image(env, x, y, ft_julia(env->zoom_x, env->zoom_y,
						env->it_max, env));
			y++;
		}
		x++;
	}
}

void		ft_draw_mandel(t_env *env)
{
	int		x;
	int		y;

	x = 0;
	while (x < SCREEN_X)
	{
		y = 0;
		while (y < SCREEN_Y)
		{
			env->zoom_x = 1.5 * (x - SCREEN_X / 2) / (0.5 * env->zoom *
					SCREEN_X) + env->move_x;
			env->zoom_y = (y - SCREEN_Y / 2) / (0.5 * env->zoom * SCREEN_Y)
				+ env->move_y;
			ft_put_pixel_to_image(env, x, y, ft_mandel(env->zoom_x, env->zoom_y,
						env->it_max, env));
			y++;
		}
		x++;
	}
}

void		ft_draw_carpet(t_env *env)
{
	int		x;
	int		y;

	x = 0;
	while (x < SCREEN_X)
	{
		y = 0;
		while (y < SCREEN_Y)
		{
			ft_carpet(x, y, env);
			y++;
		}
		x++;
	}
}

void		ft_draw_julia_3(t_env *env)
{
	int		x;
	int		y;

	x = 0;
	while (x < SCREEN_X)
	{
		y = 0;
		while (y < SCREEN_Y)
		{
			env->zoom_x = 1.5 * (x - SCREEN_X / 2) / (0.5 * env->zoom *
					SCREEN_X) + env->move_x;
			env->zoom_y = (y - SCREEN_Y / 2) / (0.5 * env->zoom * SCREEN_Y)
				+ env->move_y;
			ft_put_pixel_to_image(env, x, y, ft_julia_3(env->zoom_x,
						env->zoom_y, env->it_max, env));
			y++;
		}
		x++;
	}
}

void		ft_draw_mandel_3(t_env *env)
{
	int		x;
	int		y;

	x = 0;
	while (x < SCREEN_X)
	{
		y = 0;
		while (y < SCREEN_Y)
		{
			env->zoom_x = 1.5 * (x - SCREEN_X / 2) / (0.5 * env->zoom *
					SCREEN_X) + env->move_x;
			env->zoom_y = (y - SCREEN_Y / 2) / (0.5 * env->zoom * SCREEN_Y)
				+ env->move_y;
			ft_put_pixel_to_image(env, x, y, ft_mandel_3(env->zoom_x,
						env->zoom_y, env->it_max, env));
			y++;
		}
		x++;
	}
}
