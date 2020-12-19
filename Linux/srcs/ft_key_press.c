/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 06:42:59 by teppei            #+#    #+#             */
/*   Updated: 2020/12/12 16:57:22 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	release_key(int key, void *a)
{
	t_all	*b;

	b = (t_all *)a;
	if (key == W)
		b->key.w = 0;
	if (key == A)
		b->key.a = 0;
	if (key == S)
		b->key.s = 0;
	if (key == D)
		b->key.d = 0;
	if (key == LEFT)
		b->key.l = 0;
	if (key == RIGHT)
		b->key.r = 0;
	if (key == ESC)
		b->key.esc = 0;
	return (0);
}

int	press_key(int key, void *a)
{
	t_all	*b;

	b = (t_all *)a;
	if (key == W)
		b->key.w = 1;
	if (key == A)
		b->key.a = 1;
	if (key == S)
		b->key.s = 1;
	if (key == D)
		b->key.d = 1;
	if (key == LEFT)
		b->key.l = 1;
	if (key == RIGHT)
		b->key.r = 1;
	if (key == ESC)
		b->key.esc = 1;
	return (0);
}
