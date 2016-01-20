/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 19:37:37 by zhasni            #+#    #+#             */
/*   Updated: 2015/01/28 20:44:47 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_put_pixel_to_image(t_env *env, int x, int y, int color)
{
	int		i;

	i = ((env->bpp / 8) * x) + ((env->sline) * y);
	if (i >= 0 && i < SCREEN_Y * env->sline && i > y * env->sline && i <
			(y * env->sline) + ((env->bpp / 8) * SCREEN_X))
	{
		env->str[i] = color;
		env->str[i + 1] = (color) >> 8;
		env->str[i + 2] = (color) >> 16;
	}
}

void		key_hook_qar(int keycode, t_env *env)
{
	if (keycode == T_6)
	{
		ft_init_env(env);
		env->frct = 6;
	}
	if (keycode == T_2)
	{
		ft_init_env(env);
		env->frct = 2;
	}
	if (keycode == T_3)
	{
		ft_init_env(env);
		env->frct = 3;
	}
	if (keycode == T_0)
	{
		ft_init_env(env);
		env->frct = 0;
	}
	if (keycode == T_PT)
		env->power += 2;
	if (keycode == T_EQUAL)
		ft_init_env(env);
}

void		key_hook_ter(int keycode, t_env *env)
{
	if (keycode == T_Q)
		env->color += 100;
	if (keycode == T_W)
		env->color -= 100;
	if (keycode == T_5)
	{
		ft_init_env(env);
		env->frct = 5;
	}
	if (keycode == T_ENTER)
	{
		if (env->stop == 0)
			env->stop = 1;
		else if (env->stop == 1)
			env->stop = 0;
	}
	if (keycode == T_1)
	{
		ft_init_env(env);
		env->frct = 1;
	}
	else
		key_hook_qar(keycode, env);
}

void		key_hook_bis(int keycode, t_env *env)
{
	if (keycode == T_7)
	{
		ft_init_env(env);
		env->frct = 7;
	}
	if (keycode == T_8)
	{
		ft_init_env(env);
		env->frct = 8;
	}
	if (keycode == T_9)
	{
		ft_init_env(env);
		env->frct = 9;
	}
	if (keycode == T_4)
	{
		ft_init_env(env);
		env->frct = 4;
	}
	else
		key_hook_ter(keycode, env);
}

void		mouse_hook_bis(int button, int x, int y, t_env *env)
{
	if (button == 5)
	{
		env->zoom += 1 * env->ratio;
		env->move_x += (((double)x - SCREEN_X / 2) / SCREEN_X / 2) /
			env->zoom;
		env->move_y += (((double)y - SCREEN_Y / 2) / SCREEN_Y / 2) /
			env->zoom;
	}
	else if (button == 4)
	{
		env->zoom -= 1 * env->ratio;
		if (env->zoom <= 0)
			env->zoom = 1;
		env->move_x += (((double)x - SCREEN_X / 2) / SCREEN_X / 2) /
			env->zoom;
		env->move_y += (((double)y - SCREEN_Y / 2) / SCREEN_Y / 2) /
			env->zoom;
	}
}
