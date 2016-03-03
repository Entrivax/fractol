/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <lpilotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 16:43:27 by lpilotto          #+#    #+#             */
/*   Updated: 2016/03/03 17:23:11 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "z_ci.h"
#include "helpers.h"
#include "libft.h"

float	ft_fabs(float a)
{
	return (a < 0. ? -a : a);
}

void	draw_burningship_pixel(t_env *env, int x, int y)
{
	t_z_ci	a;
	int		i;
	t_z_ci	tmp;

	tmp.c_r = 2 * 1.7 * (x / (env->width * env->zoom) - 0.5) + env->offsetx;
	tmp.c_i = 2 * 1.7 * (y / (env->height * env->zoom) - 0.5) + env->offsety;
	a.c_r = tmp.c_r;
	a.c_i = tmp.c_i;
	a.z_r = 0;
	a.z_i = 0;
	i = 0;
	while (i < 200)
	{
		tmp.z_r = a.z_r * a.z_r - a.z_i * a.z_i - a.c_r;
		tmp.z_i = 2 * ft_fabs(a.z_r * a.z_i) - a.c_i;
		a = tmp;
		if (a.z_r * a.z_r + a.z_i * a.z_i > 10)
			break;
		i++;
	}
	pixel_put_img(env, x, y, (i * 255 / 200 << 8) + (i * 255 / 200 << 16)
					+ i * 255 / 200);
}

void	draw_burningship(t_env *env)
{
	int x;
	int y;

	x = 0;
	while (x < env->width)
	{
		y = 0;
		while (y < env->height)
		{
			draw_burningship_pixel(env, x, y);
			y++;
		}
		x++;
	}
}
