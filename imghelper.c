/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imghelper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 13:56:30 by lpilotto          #+#    #+#             */
/*   Updated: 2016/01/27 13:07:46 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "mlx.h"

void	pixel_put_img(t_env *env, int x, int y, int rgb_color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		(*(unsigned int *)(env->img_writable + x * env->bits_per_pixel / 8 +
			y * env->size_line)) = mlx_get_color_value(env->mlx, rgb_color);
}
