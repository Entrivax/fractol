/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 12:03:31 by lpilotto          #+#    #+#             */
/*   Updated: 2016/03/04 12:13:16 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "z_ci.h"
#include "helpers.h"
#include "libft.h"
#include "vector2.h"

void	draw_julia_pixel(t_env *env, int x, int y, t_vector2 c)
{
	t_z_ci	a;
	int		i;
	double	tmp;

	a.c_r = c.x;
	a.c_i = c.y;
	a.z_r = x / (env->width / (0.6 - -2.1) * env->zoom) + -2.1 + env->offsetx;
	a.z_i = y / (env->height / (1.2 - -1.2) * env->zoom) + -1.2 + env->offsety;
	i = 0;
	while ((a.z_r * a.z_r) + (a.z_i * a.z_i) <= 4 && i < ITERATIONS_MAX)
	{
		tmp = a.z_r;
		a.z_r = a.z_r * a.z_r - a.z_i * a.z_i + a.c_r;
		a.z_i = 2 * a.z_i * tmp + a.c_i;
		i++;
	}
	if (i == ITERATIONS_MAX)
		pixel_put_img(env, x, y, 0x0);
	else
		pixel_put_img(env, x, y, i * 0xfedcba);
}

void	draw_julia(t_env *env, t_vector2 c)
{
	int x;
	int y;

	x = 0;
	while (x < env->width)
	{
		y = 0;
		while (y < env->height)
		{
			draw_julia_pixel(env, x, y, c);
			y++;
		}
		x++;
	}
}
