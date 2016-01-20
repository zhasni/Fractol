/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 20:26:04 by zhasni            #+#    #+#             */
/*   Updated: 2015/01/20 20:26:08 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_draw_julia_4(t_env *env)
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
			ft_put_pixel_to_image(env, x, y, ft_julia_4(env->zoom_x,
						env->zoom_y, env->it_max, env));
			y++;
		}
		x++;
	}
}

void		ft_draw_mandel_4(t_env *env)
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
			ft_put_pixel_to_image(env, x, y, ft_mandel_4(env->zoom_x,
						env->zoom_y, env->it_max, env));
			y++;
		}
		x++;
	}
}

void		ft_draw_julia_5(t_env *env)
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
			ft_put_pixel_to_image(env, x, y, ft_julia_5(env->zoom_x,
						env->zoom_y, env->it_max, env));
			y++;
		}
		x++;
	}
}

void		ft_draw_mandel_5(t_env *env)
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
			ft_put_pixel_to_image(env, x, y, ft_mandel_5(env->zoom_x,
						env->zoom_y, env->it_max, env));
			y++;
		}
		x++;
	}
}

void		ft_draw_mandelbar(t_env *env)
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
			ft_put_pixel_to_image(env, x, y, ft_mandelbar(env->zoom_x,
						env->zoom_y, env->it_max, env));
			y++;
		}
		x++;
	}
}
