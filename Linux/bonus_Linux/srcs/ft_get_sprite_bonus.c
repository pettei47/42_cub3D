/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 04:32:06 by teppei            #+#    #+#             */
/*   Updated: 2020/12/13 22:09:58 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_sprite	set_sprite_data(int x, int y)
{
	t_sprite	new;

	new.sp_x = (double)x + 0.50;
	new.sp_y = (double)y + 0.50;
	new.ti = 4;
	return (new);
}

void			get_sprite(t_all *a)
{
	int	x;
	int	y;
	int	i;

	if (a->e->num_sp == 0)
		return ;
	if (!(a->sp = (t_sprite *)malloc(sizeof(t_sprite) * a->e->num_sp)))
		error_free("malloc error in get_sprite", a->e);
	i = 0;
	y = 0;
	while (a->e->map[y])
	{
		x = 0;
		while (a->e->map[y][x])
		{
			if (a->e->map[y][x] == '2')
				a->sp[i++] = set_sprite_data(x, y);
			x++;
		}
		y++;
	}
}
