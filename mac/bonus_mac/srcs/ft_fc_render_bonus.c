/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fc_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 08:49:53 by teppei            #+#    #+#             */
/*   Updated: 2020/12/13 19:54:02 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void		set_move_speed(t_all *a)
{
	a->mv_spd = fmax(0.08, \
			(double)(a->e->win_x * a->e->win_y) / (5 * my_power(10, 6)));
	a->rt_spd = fmax(0.08, \
			(double)(a->e->win_x * a->e->win_y) / (10 * my_power(10, 6)));
}

void		my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	*(uint32_t *)(img->addr + (y * img->line + x * (img->bpp / 8))) = color;
}

static void	calc_color(t_all *a)
{
	a->f_color = (a->e->fr << 16) + (a->e->fg << 8) + a->e->fb;
	a->c_color = (a->e->cr << 16) + (a->e->cg << 8) + a->e->cb;
}

void		render_fc(t_all *a)
{
	int h;
	int w;
	int y;
	int x;

	h = a->e->win_y;
	w = a->e->win_x;
	y = h / 2 + 1;
	calc_color(a);
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			my_mlx_pixel_put(&a->img, x, y, a->f_color);
			my_mlx_pixel_put(&a->img, x, h - y - 1, a->c_color);
			x++;
		}
		y++;
	}
}
