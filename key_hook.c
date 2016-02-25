/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 12:03:36 by lpilotto          #+#    #+#             */
/*   Updated: 2016/02/25 13:32:20 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"

int		key_hook(int keycode, void *param)
{
	t_env	*env;

	env = param;
	ft_putnbrendl(keycode);
	if (keycode == 126)
		env->zoom++;
	else if (keycode == 125)
		env->zoom--;
	return (1);
}
