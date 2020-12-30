/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 08:36:56 by teppei            #+#    #+#             */
/*   Updated: 2020/12/30 12:24:16 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	calc_draw_param(t_raycasting *rc, t_all *a)
{
	if (rc->side == 0)
	{
		rc->perp_wall_dist = rc->map_x - a->e->pos_x + (1 - rc->step_x) / 2;
		rc->perp_wall_dist /= rc->ray_dir_x;
	}
	else
	{
		rc->perp_wall_dist = rc->map_y - a->e->pos_y + (1 - rc->step_y) / 2;
		rc->perp_wall_dist /= rc->ray_dir_y;
	}
	rc->line_height = (int)(a->e->win_y / rc->perp_wall_dist);
	rc->draw_start = fmax(-(rc->line_height) / 2 + a->e->win_y / 2, 0);
	rc->draw_end = fmin(rc->line_height / 2 + a->e->win_y / 2, a->e->win_y - 1);
	if (rc->side == 0)
		rc->wall_x = a->e->pos_y + rc->perp_wall_dist * rc->ray_dir_y;
	else
		rc->wall_x = a->e->pos_x + rc->perp_wall_dist * rc->ray_dir_x;
	rc->wall_x -= floor(rc->wall_x);
	rc->tex_x = (int)(rc->wall_x * (double)a->tex[rc->tex_num].w);
	if ((rc->side == 0 && rc->ray_dir_x > 0) ||
		(rc->side == 1 && rc->ray_dir_y < 0))
		rc->tex_x = a->tex[rc->tex_num].w - rc->tex_x - 1;
	rc->step = 1.0 * a->tex[rc->tex_num].h / rc->line_height;
	rc->tex_pos = (rc->draw_start - a->e->win_y / 2 +
					rc->line_height / 2) * rc->step;
}

static void	draw_wall(t_raycasting *rc, t_all *a, int x)
{
	uint32_t	color;
	int			tex_height;
	int			y;

	calc_draw_param(rc, a);
	tex_height = a->tex[rc->tex_num].h;
	y = rc->draw_start;
	while (y < rc->draw_end)
	{
		rc->tex_y = fmin((int)rc->tex_pos, (tex_height - 1));;
		rc->tex_pos += rc->step;
		color = a->tex[rc->tex_num].addr[tex_height * rc->tex_y + rc->tex_x];
		my_mlx_pixel_put(&a->img, x, y, color);
		y++;
	}
}

static void	dda_algo(t_raycasting *rc, t_all *a)
{
	while (1)
	{
		if (rc->side_dist_x < rc->side_dist_y)
		{
			rc->side_dist_x += rc->delta_dist_x;
			rc->map_x += rc->step_x;
			rc->side = 0;
			if (rc->step_x == 1)
				rc->tex_num = 2;
			else
				rc->tex_num = 3;
		}
		else
		{
			rc->side_dist_y += rc->delta_dist_y;
			rc->map_y += rc->step_y;
			rc->side = 1;
			if (rc->step_y == 1)
				rc->tex_num = 1;
			else
				rc->tex_num = 0;
		}
		if (a->e->map[rc->map_y][rc->map_x] == '1')
			break ;
	}
}

static void	calc_rc(t_raycasting *rc, t_all *a, int x)
{
	rc->camera_x = 2 * x / (double)a->e->win_x - 1;
	rc->ray_dir_x = a->e->dir_x + a->e->plane_x * rc->camera_x;
	rc->ray_dir_y = a->e->dir_y + a->e->plane_y * rc->camera_x;
	rc->map_x = (int)a->e->pos_x;
	rc->map_y = (int)a->e->pos_y;
	rc->delta_dist_x = fabs(1 / rc->ray_dir_x);
	rc->delta_dist_y = fabs(1 / rc->ray_dir_y);
	if (rc->ray_dir_x < 0)
		rc->step_x = -1;
	else
		rc->step_x = 1;
	if (rc->ray_dir_x < 0)
		rc->side_dist_x = (a->e->pos_x - rc->map_x) * rc->delta_dist_x;
	else
		rc->side_dist_x = (rc->map_x + 1.0 - a->e->pos_x) * rc->delta_dist_x;
	if (rc->ray_dir_y < 0)
		rc->step_y = -1;
	else
		rc->step_y = 1;
	if (rc->ray_dir_y < 0)
		rc->side_dist_y = (a->e->pos_y - rc->map_y) * rc->delta_dist_y;
	else
		rc->side_dist_y = (rc->map_y + 1.0 - a->e->pos_y) * rc->delta_dist_y;
}

void		render_wall(t_all *a)
{
	t_raycasting	rc;
	int				x;

	x = 0;
	while (x < a->e->win_x)
	{
		calc_rc(&rc, a, x);
		dda_algo(&rc, a);
		draw_wall(&rc, a, x);
		a->z_buffer[x] = rc.perp_wall_dist;
		x++;
	}
}
