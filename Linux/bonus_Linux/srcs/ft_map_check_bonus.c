/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 22:27:43 by teppei            #+#    #+#             */
/*   Updated: 2020/12/14 00:27:48 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	get_start_position2(t_elem *e, char c)
{
	if (c != 'N')
	{
		e->dir_x = 0.0;
		e->dir_y = -1.0;
		e->plane_x = -0.66;
		e->plane_y = 0.0;
	}
	else
	{
		e->dir_x = 0.0;
		e->dir_y = 1.0;
		e->plane_x = 0.66;
		e->plane_y = 0.0;
	}
}

static void	get_start_position(t_elem *e, int x, int y, char c)
{
	if (e->pos_x > -42.0)
		error_free("Multiple start positions", e);
	e->pos_x = (double)x + 0.50;
	e->pos_y = (double)y + 0.50;
	if (c == 'E')
	{
		e->dir_x = 1.0;
		e->dir_y = 0.0;
		e->plane_x = 0.0;
		e->plane_y = -0.66;
	}
	else if (c == 'W')
	{
		e->dir_x = -1.0;
		e->dir_y = 0.0;
		e->plane_x = 0.0;
		e->plane_y = 0.66;
	}
	else
		get_start_position2(e, c);
}

void		ft_map_check_format(t_elem *e)
{
	int		xy[2];
	char	c;

	xy[0] = 0;
	while (xy[0] < MAP_HEIGHT && e->map[xy[0]] != NULL)
	{
		xy[1] = 0;
		while (xy[1] < MAP_WIDTH && e->map[xy[0]][xy[1]] != 0)
		{
			c = e->map[xy[0]][xy[1]];
			if (('0' <= c && c <= '2'))
				xy[1]++;
			else if (c == ' ')
				e->map[xy[0]][xy[1]] = '0';
			else if (ft_strchr("NEWS", c))
				get_start_position(e, xy[1]++, xy[0], c);
			else
				error_free("map error", e);
			if (e->map[xy[0]][xy[1]] == '2')
				e->num_sp++;
		}
		xy[0]++;
	}
	if (e->pos_x <= -42.0)
		error_free("no player set", e);
}

void		warning(char *msg)
{
	ft_putstr_fd(PURPLE, 2);
	ft_putendl_fd("WARNING!", 2);
	ft_putendl_fd(msg, 2);
}
