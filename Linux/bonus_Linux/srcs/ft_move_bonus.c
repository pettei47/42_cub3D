/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 05:00:45 by teppei            #+#    #+#             */
/*   Updated: 2020/12/29 19:42:09 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	move_ws(t_all *a)
{
	if (a->key.w)
	{
		if (ft_strchr("12", a->e->map
			[(int)(a->e->pos_y + a->e->dir_y * a->mv_spd)]\
			[(int)(a->e->pos_x)]) == NULL)
			a->e->pos_y += a->e->dir_y * a->mv_spd;
		if (ft_strchr("12", a->e->map
			[(int)(a->e->pos_y)]\
			[(int)(a->e->pos_x + a->e->dir_x * a->mv_spd)]) == NULL)
			a->e->pos_x += a->e->dir_x * a->mv_spd;
	}
	if (a->key.s)
	{
		if (ft_strchr("12", a->e->map
			[(int)(a->e->pos_y - a->e->dir_y * a->mv_spd)]\
			[(int)(a->e->pos_x)]) == NULL)
			a->e->pos_y -= a->e->dir_y * a->mv_spd;
		if (ft_strchr("12", a->e->map
			[(int)a->e->pos_y]\
			[(int)(a->e->pos_x - a->e->dir_x * a->mv_spd)]) == NULL)
			a->e->pos_x -= a->e->dir_x * a->mv_spd;
	}
}

static void	move_ad(t_all *a)
{
	if (a->key.a)
	{
		if (ft_strchr("12", a->e->map
			[(int)(a->e->pos_y - a->e->plane_y * a->mv_spd)]\
			[(int)(a->e->pos_x)]) == NULL)
			a->e->pos_y -= a->e->plane_y * a->mv_spd;
		if (ft_strchr("12", a->e->map
			[(int)(a->e->pos_y)]\
			[(int)(a->e->pos_x - a->e->plane_x * a->mv_spd)]) == NULL)
			a->e->pos_x -= a->e->plane_x * a->mv_spd;
	}
	if (a->key.d)
	{
		if (ft_strchr("12", a->e->map
			[(int)(a->e->pos_y + a->e->plane_y * a->mv_spd)]\
			[(int)(a->e->pos_x)]) == NULL)
			a->e->pos_y += a->e->plane_y * a->mv_spd;
		if (ft_strchr("12", a->e->map
			[(int)(a->e->pos_y)]\
			[(int)(a->e->pos_x + a->e->plane_x * a->mv_spd)]) == NULL)
			a->e->pos_x += a->e->plane_x * a->mv_spd;
	}
}

static void	rotate2(t_all *a)
{
	double	old_dir_x;
	double	old_plane_x;

	if (a->key.l)
	{
		old_dir_x = a->e->dir_x;
		a->e->dir_x = a->e->dir_x * cos(a->rt_spd) \
						- a->e->dir_y * sin(a->rt_spd);
		a->e->dir_y = old_dir_x * sin(a->rt_spd) \
						+ a->e->dir_y * cos(a->rt_spd);
		old_plane_x = a->e->plane_x;
		a->e->plane_x = a->e->plane_x * cos(a->rt_spd) \
						- a->e->plane_y * sin(a->rt_spd);
		a->e->plane_y = old_plane_x * sin(a->rt_spd) \
						+ a->e->plane_y * cos(a->rt_spd);
	}
}

static void	rotate(t_all *a)
{
	double	old_dir_x;
	double	old_plane_x;

	if (a->key.r)
	{
		old_dir_x = a->e->dir_x;
		a->e->dir_x = a->e->dir_x * cos(-a->rt_spd) \
						- a->e->dir_y * sin(-a->rt_spd);
		a->e->dir_y = old_dir_x * sin(-a->rt_spd) \
						+ a->e->dir_y * cos(-a->rt_spd);
		old_plane_x = a->e->plane_x;
		a->e->plane_x = a->e->plane_x * cos(-a->rt_spd) \
						- a->e->plane_y * sin(-a->rt_spd);
		a->e->plane_y = old_plane_x * sin(-a->rt_spd) \
						+ a->e->plane_y * cos(-a->rt_spd);
	}
	rotate2(a);
}

void		movement(t_all *a)
{
	move_ws(a);
	move_ad(a);
	rotate(a);
	if (a->key.esc)
		quit_normally(a);
}
