/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 12:03:36 by lpilotto          #+#    #+#             */
/*   Updated: 2016/03/02 13:50:22 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"


#include <stdio.h>
int		key_hook(int keycode, void *param)
{
	t_env	*env;

	env = param;
	ft_putnbrendl(keycode);
	if (keycode == 126)
		env->zoom *= 1.2f;
	else if (keycode == 125)
		env->zoom /= 1.2f;
	printf("zoom: %lf\n", env->zoom);
	return (1);
}
