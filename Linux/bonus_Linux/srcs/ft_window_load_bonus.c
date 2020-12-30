/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_load.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 14:08:14 by teppei            #+#    #+#             */
/*   Updated: 2020/12/14 00:37:57 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static int	compare_window_size(t_all *a)
{
	int screen_width;
	int screen_height;

	if (a->e->win_x <= 0 || a->e->win_y <= 0)
		return (0);
	mlx_get_screen_size(a->mlx_p, &screen_width, &screen_height);
	a->e->win_y = (int)fmin(a->e->win_y, screen_height);
	a->e->win_x = (int)fmin(a->e->win_x, screen_width);
	if (a->e->win_x == -1)
		a->e->win_x = screen_width;
	if (a->e->win_y == -1)
		a->e->win_y = screen_height;
	return (1);
}

void		load_window(t_all *a)
{
	if (!(compare_window_size(a)))
	{
		my_free_a(a);
		error("Invalid 'R' value (0, -x, -y)");
	}
	if (!(a->z_buffer = (double *)malloc(sizeof(double) * a->e->win_x)))
	{
		my_free_a(a);
		error("malloc error in load_window");
	}
}
