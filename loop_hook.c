/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 11:51:19 by lpilotto          #+#    #+#             */
/*   Updated: 2016/03/02 13:49:13 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "mlx.h"
#include "helpers.h"
#include "fractals.h"
#include "vector2.h"

int		loop_hook(void *param)
{
	t_env		**env;
	t_vector2	c;

	env = (t_env **)param;
	c.x = .3;
	c.y = .5;
	while (*env)
	{
		if ((*env)->fract_type == 0)
			draw_mandelbrot(*env);
		if ((*env)->fract_type == 1)
		{
			c.x = (*env)->mouse_x / 100.f;
			c.y = (*env)->mouse_y / 100.f;
			draw_julia(*env, c);
		}
		clear_win(*env);
		mlx_put_image_to_window((*env)->mlx, (*env)->win, (*env)->img, 0, 0);
		env++;
	}
	return (1);
}
