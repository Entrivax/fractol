/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 12:03:31 by lpilotto          #+#    #+#             */
/*   Updated: 2016/03/04 12:12:50 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "z_ci.h"
#include "helpers.h"
#include "libft.h"

void	draw_mandelbrot_pixel(t_env *env, int x, int y)
{
	t_z_ci	a;
	int		i;
	double	tmp;

	a.c_r = x / (env->width / (0.6 - -2.1) * env->zoom) + -2.1 + env->offsetx;
	a.c_i = y / (env->height / (1.2 - -1.2) * env->zoom) + -1.2 + env->offsety;
	a.z_r = 0;
	a.z_i = 0;
	i = 0;
	while ((a.z_r * a.z_r) + (a.z_i * a.z_i) < 4 && i < ITERATIONS_MAX)
	{
		tmp = a.z_r;
		a.z_r = a.z_r * a.z_r - a.z_i * a.z_i + a.c_r;
		a.z_i = 2 * a.z_i * tmp + a.c_i;
		i++;
	}
	if (i == ITERATIONS_MAX)
		pixel_put_img(env, x, y, 0x0);
	else
		pixel_put_img(env, x, y, i * 0xcd8bd4 / ITERATIONS_MAX);
}

void	draw_mandelbrot(t_env *env)
{
	int x;
	int y;

	x = 0;
	while (x < env->width)
	{
		y = 0;
		while (y < env->height)
		{
			draw_mandelbrot_pixel(env, x, y);
			y++;
		}
		x++;
	}
}
