/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_moved.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 13:15:03 by lpilotto          #+#    #+#             */
/*   Updated: 2016/03/02 13:46:47 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		mouse_moved(int x, int y, void *param)
{
	t_env *env;

	env = param;
	env->mouse_x = x;
	env->mouse_y = y;
	return (0);
}
