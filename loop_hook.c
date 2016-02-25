/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 11:51:19 by lpilotto          #+#    #+#             */
/*   Updated: 2016/02/25 13:20:19 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "mlx.h"
#include "helpers.h"
#include "fractals.h"

int		loop_hook(void *param)
{
	t_env **env;

	env = (t_env **)param;
	while (*env)
	{
		if ((*env)->fract_type == 0)
			draw_mandelbrot(*env);
		clear_win(*env);
		mlx_put_image_to_window((*env)->mlx, (*env)->win, (*env)->img, 0, 0);
		env++;
	}
	return (1);
}
