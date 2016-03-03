/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 12:03:36 by lpilotto          #+#    #+#             */
/*   Updated: 2016/03/03 19:52:19 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include <stdlib.h>

#ifdef LINUX

int		key_hook(int keycode, void *param)
{
	t_env	*env;

	env = param;
	if (keycode == 65451)
		env->zoom *= 1.2f;
	else if (keycode == 65453)
		env->zoom /= 1.2f;
	else if (keycode == 65307)
		exit(0);
	else if (keycode == 65361)
		env->offsetx -= .2 / env->zoom;
	else if (keycode == 65363)
		env->offsetx += .2 / env->zoom;
	else if (keycode == 65362)
		env->offsety -= .2 / env->zoom;
	else if (keycode == 65364)
		env->offsety += .2 / env->zoom;
	if (keycode == 65451 || keycode == 65362 || keycode == 65453 || keycode == 65364 || keycode == 65361 || keycode == 65363)
		env->need_rewrite = 1;
	return (1);
}

#endif

#ifdef MAC

int		key_hook(int keycode, void *param)
{
	t_env	*env;

	env = param;
	if (keycode == 69)
		env->zoom *= 1.2f;
	else if (keycode == 78)
		env->zoom /= 1.2f;
	else if (keycode == 53)
		exit(0);
	else if (keycode == 123)
		env->offsetx -= .2 / env->zoom;
	else if (keycode == 124)
		env->offsetx += .2 / env->zoom;
	else if (keycode == 125)
		env->offsety -= .2 / env->zoom;
	else if (keycode == 126)
		env->offsety += .2 / env->zoom;
	if (keycode == 126 || keycode == 125 || keycode == 123 ||
		keycode == 124 || keycode == 69 || keycode == 78)
		env->need_rewrite = 1;
	return (1);
}

#endif
