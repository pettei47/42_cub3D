/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_cub_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 01:31:07 by teppei            #+#    #+#             */
/*   Updated: 2020/12/14 00:18:25 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

long	my_power(long a, long n)
{
	long	t;

	if (n == 0)
		return (1);
	if (n == 1)
		return (a);
	if (n % 2 == 1)
		return (a * my_power(a, n - 1));
	else
	{
		t = my_power(a, n / 2);
		return (t * t);
	}
}

void	my_e_reset2(t_elem *e)
{
	e->dir_x = -42.0;
	e->dir_y = -42.0;
	e->pos_x = -42.0;
	e->pos_y = -42.0;
	e->plane_x = -42.0;
	e->plane_y = -42.0;
	e->num_sp = 0;
	e->save = 0;
}

void	my_e_reset(t_elem *e)
{
	int	i;

	i = 0;
	e->win_x = -1;
	e->win_y = -1;
	e->north = NULL;
	e->south = NULL;
	e->west = NULL;
	e->east = NULL;
	e->sprite = NULL;
	e->fr = -1;
	e->fg = -1;
	e->fb = -1;
	e->cr = -1;
	e->cg = -1;
	e->cb = -1;
	while (i < MAP_HEIGHT)
		e->map[i++] = NULL;
	my_e_reset2(e);
}

int		my_c_ptr(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
		i++;
	return (i);
}

void	my_free_ptr(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
	{
		SAFE_FREE(s[i]);
		i++;
	}
	SAFE_FREE(s);
}
