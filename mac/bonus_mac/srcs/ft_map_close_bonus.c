/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 00:04:34 by teppei            #+#    #+#             */
/*   Updated: 2020/12/12 03:56:02 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	dfs(char check[MAP_HEIGHT][MAP_WIDTH], int y, int x, int *c)
{
	if ((x * y) == 0 || x >= MAP_WIDTH - 2 || y >= MAP_HEIGHT - 2
			|| check[y][x] == '\0' || check[y] == NULL)
	{
		*c = 0;
		return ;
	}
	check[y][x] = '1';
	if (check[y - 1][x] != '1')
		dfs(check, y - 1, x, c);
	if (check[y + 1][x] != '1')
		dfs(check, y + 1, x, c);
	if (check[y][x - 1] != '1')
		dfs(check, y, x - 1, c);
	if (check[y][x + 1] != '1')
		dfs(check, y, x + 1, c);
	return ;
}

int			map_close_check(t_elem *e, int h)
{
	char	check[MAP_HEIGHT][MAP_WIDTH];
	int		close;
	int		i;
	int		j;

	i = 0;
	while (i < h)
	{
		j = 0;
		while (e->map[i][j] != '\0' && j < MAP_WIDTH)
		{
			if (e->map[i][j] == '1')
				check[i][j] = '1';
			else if (ft_strchr("NEWS", e->map[i][j]))
				check[i][j] = 'N';
			else
				check[i][j] = '0';
			j++;
		}
		check[i][j] = '\0';
		i++;
	}
	close = 1;
	dfs(check, (int)e->pos_y, (int)e->pos_x, &close);
	return (close);
}
