/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 19:27:55 by zhasni            #+#    #+#             */
/*   Updated: 2015/01/23 10:57:54 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			expose_hook(t_env *env)
{
	ft_bzero(env->str, SCREEN_Y * env->sline);
	if (env->frct == 7)
		ft_draw_julia(env);
	else if (env->frct == 8)
		ft_draw_mandel(env);
	else if (env->frct == 9)
		ft_draw_carpet(env);
	else if (env->frct == 4)
		ft_draw_julia_3(env);
	else if (env->frct == 5)
		ft_draw_mandel_3(env);
	else if (env->frct == 6)
		ft_draw_julia_4(env);
	else if (env->frct == 1)
		ft_draw_mandel_4(env);
	else if (env->frct == 2)
		ft_draw_julia_5(env);
	else if (env->frct == 3)
		ft_draw_mandel_5(env);
	else if (env->frct == 0)
		ft_draw_mandelbar(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	env->bol = 0;
	return (0);
}

void		ft_seak(int x, int y, t_env *env)
{
	if (x > SCREEN_X / 2 && x > 0)
		env->cr = ((double)(x - (SCREEN_X / 2)) / 100);
	if (x < SCREEN_X / 2 && x > 0)
		env->cr = ((double)(x - (SCREEN_X / 2)) / 100);
	if (y > SCREEN_Y / 2 && y > 0)
		env->ci = ((double)(y - (SCREEN_Y / 2)) / 100);
	if (y < SCREEN_Y / 2 && y > 0)
		env->ci = ((double)(y - (SCREEN_Y / 2)) / 100);
}

int			motion_hook(int x, int y, t_env *env)
{
	if (env->stop == 0)
	{
		if (env->old_x - x != 0 && env->old_y - y != 0)
		{
			env->old_x = x;
			env->old_y = y;
		}
		if (!env->bol && env->motion)
		{
			env->bol = 1;
			ft_seak(x, y, env);
			expose_hook(env);
		}
	}
	return (0);
}

int			mouse_hook(int button, int x, int y, t_env *env)
{
	double		x_calc;
	double		y_calc;

	if (button == 1)
	{
		env->zoom += 1 * env->ratio;
		x_calc = (double)(SCREEN_X / 2 - x) / 12.5;
		y_calc = (double)(SCREEN_Y / 2 - y) / 25;
		env->move_x += (double)-(x_calc / env->zoom / 10);
		env->move_y += (double)-(y_calc / env->zoom / 10);
	}
	else if (button == 3)
	{
		env->zoom -= 1 * env->ratio;
		if (env->zoom <= 0)
			env->zoom = 1;
		x_calc = (double)(SCREEN_X / 2 - x) / 12.5;
		y_calc = (double)(SCREEN_Y / 2 - y) / 25;
		env->move_x += (double)-(x_calc / env->zoom / 10);
		env->move_y += (double)-(y_calc / env->zoom / 10);
	}
	else
		mouse_hook_bis(button, x, y, env);
	expose_hook(env);
	return (0);
}

int			key_hook(int keycode, t_env *env)
{
	if (keycode == 65307)
		exit (0);
	if (keycode == T_MUL)
		env->ratio *= 10;
	if (keycode == T_DIV)
		env->ratio /= 10;
	if (keycode == 65453)
	{
		env->it_max -= 10;
		if (env->it_max <= 0)
			env->it_max = 1;
	}
	if (keycode == 65451)
		env->it_max += 10;
	if (keycode == 65362)
		env->move_y += 0.1 / env->zoom;
	if (keycode == 65364)
		env->move_y -= 0.1 / env->zoom;
	if (keycode == 65361)
		env->move_x += 0.1 / env->zoom;
	if (keycode == 65363)
		env->move_x -= 0.1 / env->zoom;
	key_hook_bis(keycode, env);
	expose_hook(env);
	return (0);
}
