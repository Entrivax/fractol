/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 12:03:36 by lpilotto          #+#    #+#             */
/*   Updated: 2016/03/03 09:06:21 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include <stdlib.h>

#include <stdio.h>
int		key_hook(int keycode, void *param)
{
	t_env	*env;

	env = param;
	ft_putnbrendl(keycode);
	if (keycode == 126 || keycode == 65362)
		env->zoom *= 1.2f;
	else if (keycode == 125 || keycode == 65364)
		env->zoom /= 1.2f;
	else if (keycode == 65307)
		exit(0);
	if (keycode == 126 || keycode == 65362 || keycode == 125 || keycode == 65364)
		env->need_rewrite = 1;
	printf("zoom: %lf\n", env->zoom);
	return (1);
}
