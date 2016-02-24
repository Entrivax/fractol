/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 12:03:31 by lpilotto          #+#    #+#             */
/*   Updated: 2016/02/24 14:51:44 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "z_ci.h"

void	draw_mandelbrot_pixel(t_env *env, int x, int y)
{
	t_z_ci	z_ci;
	int		i;
	int		tmp;

	z_ci.c_r = x / env->zoom + env->offsetx;
	z_ci.c_i = y / env->zoom + env->offsety;
	z_ci.z_r = 0;
	z_ci.z_i = 0;
	i = 0;
	while (z_ci.z_r * z_ci.z_r + z_ci.z_i * z_ci.z_i < 4 && i < 2000)
	{
		tmp = z_ci.z_r;
		z_ci.z_r = z_ci.z_r * z_ci.z_r - z_ci.z_i * z_ci.z_i + z_ci.c_r;
		z_ci.z_i = 2 * z_ci.z_i * tmp + z_ci.c_i;
		i++;
	}
	if (i == 2000)
		pixel_put_img(env, x, y, ((int)z_ci.z_r * 0x1 + z_ci.z_i * 0x100));
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
