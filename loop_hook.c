/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 11:51:19 by lpilotto          #+#    #+#             */
/*   Updated: 2016/03/03 17:10:59 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "mlx.h"
#include "helpers.h"
#include "fractals.h"
#include "vector2.h"

void	loop_hook_next(t_env *env)
{
	if (env->fract_type == 2)
	{
		draw_burningship(env);
	}
}

int		loop_hook(void *param)
{
	t_env		**env;
	t_vector2	c;

	env = (t_env **)param;
	while (*env)
	{
		if ((*env)->need_rewrite)
		{
			(*env)->need_rewrite = 0;
			if ((*env)->fract_type == 0)
				draw_mandelbrot(*env);
			else if ((*env)->fract_type == 1)
			{
				c.x = (*env)->mouse_x / 1000.f;
				c.y = (*env)->mouse_y / 1000.f;
				draw_julia(*env, c);
			}
			else
				loop_hook_next(*env);
			clear_win(*env);
			mlx_put_image_to_window((*env)->mlx, (*env)->win, (*env)->img, 0, 0);
		}
		env++;
	}
	return (1);
}
