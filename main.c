/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 11:48:54 by lpilotto          #+#    #+#             */
/*   Updated: 2016/03/03 17:11:34 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "mlx.h"
#include "libft.h"
#include "hooks.h"
#include <stdlib.h>

void	print_usage(char *procname)
{
	ft_putstr("Usage : ");
	ft_putstr(procname);
	ft_putendl(" <fractales...>");
	ft_putendl("Fractales: mandelbrot, julia, burningship");
}

int		stop_error(void)
{
	ft_putendl("error");
	exit(1);
	return (1);
}

void	init_env(void *mlx, t_env *env, char *fract)
{
	env->mlx = mlx;
	env->width = 1000;
	env->height = 1000;
	env->zoom = 1;
	env->offsetx = 0;
	env->offsety = 0;
	env->win = mlx_new_window(mlx, env->width, env->height, fract);
	env->img = mlx_new_image(mlx, env->width, env->height);
	env->img_writable = mlx_get_data_addr(env->img,
		&(env->bits_per_pixel), &(env->size_line), &(env->endian));
	if (ft_strcmp(fract, "mandelbrot") == 0)
		env->fract_type = 0;
	else if (ft_strcmp(fract, "julia") == 0)
		env->fract_type = 1;
	else if (ft_strcmp(fract, "burningship") == 0)
		env->fract_type = 2;
	mlx_key_hook(env->win, &key_hook, env);
	mlx_hook(env->win, 6, (1L<<6), &mouse_moved, env);
	mlx_expose_hook(env->win, &expose_hook, env);
	mlx_mouse_hook(env->win, &mouse_hook, env);
}

void	setup(int argc, char **argv, t_env **env)
{
	int		i;
	void	*mlx;

	i = -1;
	if ((mlx = mlx_init()) == NULL)
		stop_error();
	mlx_do_key_autorepeaton(mlx);
	while ((++i) < argc - 1)
	{
		if ((env[i] = (t_env *)malloc(sizeof(t_env))) == NULL)
			stop_error();
		init_env(mlx, env[i], argv[i + 1]);
	}
	env[i] = NULL;
	mlx_loop_hook(mlx, &loop_hook, env);
	mlx_loop(mlx);
}

int		main(int argc, char **argv)
{
	int		i;
	t_env	**env;

	if (argc == 1)
	{
		print_usage(argv[0]);
		return (0);
	}
	i = 0;
	while (i < argc - 1)
	{
		ft_strtolower(argv[i + 1]);
		if (ft_strcmp(argv[i + 1], "mandelbrot")
			&& ft_strcmp(argv[i + 1], "julia")
			&& ft_strcmp(argv[i + 1], "burningship"))
		{
			print_usage(argv[0]);
			return (0);
		}
		i++;
	}
	if ((env = (t_env **)malloc(sizeof(t_env *) * (i + 1))) == NULL)
		return (stop_error());
	setup(argc, argv, env);
	return (0);
}
