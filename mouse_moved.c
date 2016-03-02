/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_moved.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 13:15:03 by lpilotto          #+#    #+#             */
/*   Updated: 2016/03/02 19:46:00 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		mouse_moved(int x, int y, void *param)
{
	t_env *env;

	env = param;
	env->mouse_x = x;
	env->mouse_y = y;
	if (env->fract_type == 1)
		env->need_rewrite = 1;
	return (0);
}
