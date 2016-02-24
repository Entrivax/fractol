/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 11:48:54 by lpilotto          #+#    #+#             */
/*   Updated: 2016/02/24 14:33:04 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"

void	print_usage()
{
	ft_putstr("Usage : ");
	ft_putstr(argv[0]);
	ft_putendl(" <fractales...>");
	ft_putendl("Fractales: mandelbrot, julia, ");
}

int		stop_error()
{
	ft_putendl("error");
	exit(1);
	return (1);
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
		env[i]->mlx = mlx;
		env[i]->width = 200;
		env[i]->height = 200;
		env[i]->win = mlx_new_window(mlx, env[i]->width, env[i]->height, argv[i + 1]);
		env[i]->img = mlx_new_image(mlx, env[i]->width, env[i]->height);
		env[i]->img_writable = mlx_get_data_addr(env[i]->img,
			&(env[i]->bits_per_pixel), &(env[i]->size_line), &(env[i]->endian));
		if (ft_strcmp(argv[i + 1], "mandelbrot") == 0)
			env[i]->fract_type = 0;
		else if (ft_strcmp(argv[i + 1], "julia") == 0)
			env[i]->fract_type = 1;
		mlx_key_hook(env[i]->win, &key_hook, env[i]);
	}
	mlx_loop_hook(mlx, &loop_hook, env);
	mlx_loop(mlx);
}

int		main(int argc, char **argv)
{
	int		i;
	t_env	**env;

	if (argc == 1)
	{
		print_usage();
		return (0);
	}
	i = 0;
	while (i < argc - 1)
	{
		ft_tolower(argv[i + 1]);
		if (ft_strcmp(argv[i + 1], "mandelbrot") && ft_strcmp(argv[i + 1], "julia"))
		{
			print_usage();
			return (0);
		}
		i++;
	}
	if ((env = (t_env **)malloc(sizeof(t_env *) * (i + 1))) == NULL)
		return (stop_error());
	setup(argc, argv, env);
	return (0);
}
