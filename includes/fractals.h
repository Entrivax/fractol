/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:08:34 by lpilotto          #+#    #+#             */
/*   Updated: 2016/03/03 17:10:32 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTALS_H
# define FRACTALS_H

# include "env.h"
# include "vector2.h"

void	draw_mandelbrot(t_env *env);
void	draw_julia(t_env *env, t_vector2 c);
void	draw_burningship(t_env *env);

#endif
