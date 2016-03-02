/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 12:01:10 by lpilotto          #+#    #+#             */
/*   Updated: 2016/03/02 19:47:36 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

typedef	struct s_env	t_env;

struct					s_env {
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_writable;
	double	width;
	double	height;
	char	need_rewrite;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		fract_type;
	double	zoom;
	double	offsetx;
	double	offsety;
	int		mouse_x;
	int		mouse_y;
};

#endif
