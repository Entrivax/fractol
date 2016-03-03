/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 12:07:33 by lpilotto          #+#    #+#             */
/*   Updated: 2016/03/03 12:56:41 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

int		key_hook(int keycode, void *param);
int		loop_hook(void *param);
int		expose_hook(void *param);
int		mouse_hook(int button, int x, int y, void *param);
int		mouse_moved(int x, int y, void *param);

#endif
