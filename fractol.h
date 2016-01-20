/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 19:00:01 by zhasni            #+#    #+#             */
/*   Updated: 2015/03/31 14:06:16 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
//# include </usr/X11/include/X11/X.h>
# include <Libft/libft.h>

# define SCREEN_Y	540
# define SCREEN_X	660
# define T_MUL 		65450
# define T_DIV 	 	65455
# define T_EQUAL 	65469
# define T_Q 		113
# define T_W 	 	119
# define T_9		65465
# define T_8		65464
# define T_7		65463
# define T_6		65462
# define T_5		65461
# define T_4		65460
# define T_3		65459
# define T_2		65458
# define T_1		65457
# define T_0		65456
# define T_PT		65454
# define T_ENTER	65421

typedef	struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*str;
	int				bpp;
	int				sline;
	int				endian;
	int				color;
	double			zr;
	double			zi;
	double			cr;
	double			ci;
	double			pr;
	double			pi;
	double			zoom_x;
	double			zoom_y;
	double			ratio;
	int				it_max;
	int				pos_x;
	int				pos_y;
	double			old_x;
	double			old_y;
	long long		zoom;
	double			move_x;
	double			move_y;
	int				bol;
	int				motion;
	char			*arg;
	int				frct;
	int				stop;
	int				power;
}					t_env;

void				ft_put_pixel_to_image(t_env *env, int x, int y, int color);
void				ft_bzero(void *s, size_t n);
void				ft_draw_julia(t_env *env);
void				ft_draw_mandel(t_env *env);
void				ft_draw_carpet(t_env *env);
int					ft_julia(double zr, double zi, int it_max, t_env *env);
int					ft_mandel(double zr, double zi, int it_max, t_env *env);
void				ft_carpet(int x, int y, t_env *env);
int					ft_fractol(t_env *env, char *arg);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_putstr(char const *s);
int					key_hook(int keycode, t_env *env);
int					mouse_hook(int button, int x, int y, t_env *env);
int					motion_hook(int x, int y, t_env *env);
int					expose_hook(t_env *env);
void				ft_init_env(t_env *env);
void				ft_putchar(char c);
int					ft_julia_3(double zr, double zi, int it_max, t_env *env);
int					ft_mandel_3(double zr, double zi, int it_max, t_env *env);
void				ft_draw_julia_3(t_env *env);
void				ft_draw_mandel_3(t_env *env);
void				key_hook_bis(int keycode, t_env *env);
void				mouse_hook_bis(int button, int x, int y, t_env *env);
int					ft_mandel_4(double zr, double zi, int it_max, t_env *env);
void				ft_draw_mandel_4(t_env *env);
int					ft_julia_4(double zr, double zi, int it_max, t_env *env);
void				ft_draw_julia_4(t_env *env);
int					ft_mandel_5(double zr, double zi, int it_max, t_env *env);
void				ft_draw_mandel_5(t_env *env);
int					ft_julia_5(double zr, double zi, int it_max, t_env *env);
void				ft_draw_julia_5(t_env *env);
int					ft_mandel_6(double zr, double zi, int it_max, t_env *env);
void				ft_draw_mandel_6(t_env *env);
int					ft_julia_6(double zr, double zi, int it_max, t_env *env);
void				ft_draw_julia_6(t_env *env);
int					ft_mandelbar(double zr, double zi, int it_max, t_env *env);
void				ft_draw_mandelbar(t_env *env);

#endif
