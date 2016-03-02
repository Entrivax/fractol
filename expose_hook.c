/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <lpilotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 19:34:15 by lpilotto          #+#    #+#             */
/*   Updated: 2016/03/02 19:38:27 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "mlx.h"

int		expose_hook(void *param)
{
	t_env	*env;

	env = (t_env *)param;
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (1);
}
