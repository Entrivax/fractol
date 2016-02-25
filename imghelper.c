/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imghelper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 13:56:30 by lpilotto          #+#    #+#             */
/*   Updated: 2016/02/25 13:19:48 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "mlx.h"

void	clear_win(t_env *env)
{
	int x;
	int y;

	x = 0;
	while (x < env->width)
	{
		y = 0;
		while (y < env->width)
		{
			mlx_pixel_put(env->mlx, env->win, x, y, 0);
			y++;
		}
		x++;
	}
}

void	pixel_put_img(t_env *env, int x, int y, int rgb_color)
{
	if (x >= 0 && x < env->width && y >= 0 && y < env->height)
		(*(unsigned int *)(env->img_writable + x * env->bits_per_pixel / 8 +
			y * env->size_line)) = mlx_get_color_value(env->mlx, rgb_color);
}
