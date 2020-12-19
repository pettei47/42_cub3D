/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_render.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 07:25:04 by teppei            #+#    #+#             */
/*   Updated: 2020/12/13 21:14:04 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	input_order_and_dist(int *order, double *dist, t_all *a)
{
	int i;
	int x;
	int y;

	i = 0;
	while (i < a->e->num_sp)
	{
		order[i] = i;
		x = a->e->pos_x - a->sp[i].sp_x;
		y = a->e->pos_y - a->sp[i].sp_y;
		dist[i] = x * x + y * y;
		i++;
	}
}

static void	sort_sprite(int *order, double *dist, int num_sp)
{
	int		i;
	int		j;
	double	tmp_d;
	int		tmp_i;

	i = 0;
	while (i < num_sp - 1)
	{
		j = num_sp - 1;
		while (j > i)
		{
			if (dist[j] > dist[j - 1])
			{
				tmp_d = dist[j];
				tmp_i = order[j];
				dist[j] = dist[j - 1];
				order[j] = order[j - 1];
				dist[j - 1] = tmp_d;
				order[j - 1] = tmp_i;
			}
			j--;
		}
		i++;
	}
}

static void	calc_sd(t_all *a, int idx, t_sd *sd)
{
	sd->x = a->sp[idx].sp_x - a->e->pos_x;
	sd->y = a->sp[idx].sp_y - a->e->pos_y;
	sd->inv_det = 1.0 / (a->e->plane_x * a->e->dir_y \
			- a->e->dir_x * a->e->plane_y);
	sd->transf_x = sd->inv_det * (a->e->dir_y * sd->x - a->e->dir_x * sd->y);
	sd->transf_y = sd->inv_det * (-a->e->plane_y \
			* sd->x + a->e->plane_x * sd->y);
	sd->screeen_x = (int)((a->e->win_x / 2) \
			* (1 + sd->transf_x / sd->transf_y));
	sd->height = (int)fabs((a->e->win_y / sd->transf_y));
	sd->d_start_y = fmax(-sd->height / 2 + a->e->win_y / 2, 0);
	sd->d_end_y = fmin(sd->height / 2 + a->e->win_y / 2, a->e->win_y - 1);
	sd->width = (int)fabs((a->e->win_y / sd->transf_y));
	sd->d_start_x = fmax(-sd->width / 2 + sd->screeen_x, 0);
	sd->d_end_x = fmin(sd->width / 2 + sd->screeen_x, a->e->win_x - 1);
}

static void	draw_sprite(t_all *a, t_sd *sd)
{
	int			stripe;
	int			y;
	int			d;
	uint32_t	color;

	stripe = sd->d_start_x;
	while (stripe < sd->d_end_x)
	{
		sd->tex_x = (1 * (stripe - (-sd->width / 2 + sd->screeen_x))
					* a->tex[4].w / sd->width) / 1;
		y = sd->d_start_y;
		if (sd->transf_y > 0 && sd->transf_y < a->z_buffer[stripe])
			while (y < sd->d_end_y)
			{
				d = y * 1 - a->e->win_y * 0.50 + sd->height * 0.50;
				sd->tex_y = (d * a->tex[4].h / sd->height) / 1;
				color = a->tex[4].addr\
						[a->tex[4].w * (int)sd->tex_y + (int)sd->tex_x];
				if ((color & 0x00FFFFFF) != 0)
					my_mlx_pixel_put(&a->img, stripe, y, color);
				y++;
			}
		stripe++;
	}
}

void		render_sprite(t_all *a)
{
	t_sd	sd;
	int		*order;
	double	*dist;
	int		i;

	if (!(order = (int *)malloc(sizeof(int) * a->e->num_sp)))
		quit_normally(a);
	if (!(dist = (double *)malloc(sizeof(double) * a->e->num_sp)))
		quit_normally(a);
	input_order_and_dist(order, dist, a);
	sort_sprite(order, dist, a->e->num_sp);
	i = 0;
	while (i < a->e->num_sp)
	{
		calc_sd(a, order[i], &sd);
		draw_sprite(a, &sd);
		i++;
	}
	free(order);
	order = NULL;
	free(dist);
	dist = NULL;
}
