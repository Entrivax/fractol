/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <lpilotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 12:53:09 by lpilotto          #+#    #+#             */
/*   Updated: 2016/03/03 13:59:52 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

#include <stdio.h>
int		mouse_hook(int button, int x, int y, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	(void)x;
	(void)y;
	if (button == 4)
	{
		env->zoom *= 1.2;
		env->offsetx += (x / env->width - .5) * (2.7 / env->zoom);
		env->offsety += (y / env->height - .5) * (2.4 / env->zoom);
	}
	else if (button == 5)
	{
		env->zoom /= 1.2;
		env->offsetx += (.5 - x / env->width) * (2.7 / env->zoom);
		env->offsety += (.5 - y / env->height) * (2.4 / env->zoom);
	}
	printf("%lf %lf\n", env->offsetx, env->offsety);
	env->need_rewrite = 1;
	return (1);
}
