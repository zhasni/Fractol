/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 10:34:05 by zhasni            #+#    #+#             */
/*   Updated: 2015/06/04 11:41:28 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_env(t_env *env)
{
	env->ratio = 1;
	env->it_max = 50;
	env->pos_x = 0;
	env->pos_y = 0;
	env->move_x = 0;
	env->move_y = 0;
	env->zr = -2.1;
	env->zi = -1.4;
	env->cr = -0.772691322542185;
	env->ci = 0.124281466072787;
	env->zoom = 1;
	env->old_x = SCREEN_X;
	env->old_y = SCREEN_Y;
	env->bol = 0;
	env->color = 1000;
	env->stop = 0;
	env->power = 2;
}

int		ft_fractol(t_env *env, char *str)
{
	if (ft_strcmp(str, "julia") == 0)
		env->frct = 7;
	else if (ft_strcmp(str, "mandel") == 0)
		env->frct = 8;
	else if (ft_strcmp(str, "carpet") == 0)
		env->frct = 9;
	else
	{
		ft_putstr("enter julia, mandel or carpet !\n");
		return (0);
	}
	mlx_hook(env->win, KeyPress, KeyRelease, key_hook, env);
	mlx_hook(env->win, MotionNotify, PointerMotionMask, motion_hook, env);
	mlx_mouse_hook(env->win, mouse_hook, env);
	mlx_expose_hook(env->win, expose_hook, env);
	mlx_loop(env->mlx);
	return (0);
}

int		main(int ac, char **av)
{
	t_env	env;

	if (!(env.mlx = mlx_init()))
		return (1);
	if (!(env.win = mlx_new_window(env.mlx, SCREEN_X, SCREEN_Y, "Fract'ol")))
		return (1);
	if (!(env.img = mlx_new_image(env.mlx, SCREEN_X, SCREEN_Y)))
		return (-1);
	if (!(env.str = mlx_get_data_addr(env.img, &(env.bpp), &(env.sline),
					&(env.endian))))
		return (-1);
	ft_init_env(&env);
	if (ac == 2)
	{
		env.arg = av[1];
		ft_fractol(&env, av[1]);
	}
	else
		ft_putstr("enter one argument julia, mandel or carpet !\n");
	return (0);
}
