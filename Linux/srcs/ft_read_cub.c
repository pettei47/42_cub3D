/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 00:59:44 by teppei            #+#    #+#             */
/*   Updated: 2020/12/30 13:58:43 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_chk_elem4(char **s, t_elem *e, int *bit)
{
	char	**c_rgb;

	if ((ft_strncmp(s[0], "C", 2) == 0) && e->cr < 0 && my_c_ptr(s) == 2)
	{
		*bit += my_power(10, 1);
		if (only_d(s[1], ',') > 3)
			error_free("C must be three numbers", e);
		c_rgb = ft_split(s[1], ',');
		if (my_c_ptr(c_rgb) != 3)
			error_free("element C must have 3 contents", e);
		e->cr = ft_atoi(c_rgb[0]);
		e->cg = ft_atoi(c_rgb[1]);
		e->cb = ft_atoi(c_rgb[2]);
		my_free_ptr(c_rgb);
		if (e->cr < 0 || 255 < e->cr || e->cg < 0 || 255 < e->cg \
				|| e->cb < 0 || 255 < e->cb)
			error_free("C must be 0 ~ 255", e);
	}
	else
		error_free("cub elements error", e);
	return (1);
}

int	ft_chk_elem3(char **s, t_elem *e, int *bit)
{
	char	**f_rgb;

	if ((ft_strncmp(s[0], "F", 2) == 0) && e->fr < 0 && my_c_ptr(s) == 2)
	{
		*bit += my_power(10, 1);
		if (only_d(s[1], ',') > 3)
			error_free("F must be three numbers", e);
		f_rgb = ft_split(s[1], ',');
		if (my_c_ptr(f_rgb) != 3)
			error_free("element F must have 3 contents", e);
		e->fr = ft_atoi(f_rgb[0]);
		e->fg = ft_atoi(f_rgb[1]);
		e->fb = ft_atoi(f_rgb[2]);
		my_free_ptr(f_rgb);
		if (e->fr < 0 || 255 < e->fr || e->fg < 0 || 255 < e->fg \
				|| e->fb < 0 || 255 < e->fb)
			error_free("F must be 0 ~ 255", e);
	}
	else
		return (ft_chk_elem4(s, e, bit));
	return (1);
}

int	ft_chk_elem2(char **s, t_elem *e, int *bit)
{
	if ((ft_strncmp(s[0], "WE", 3) == 0) && !e->west && my_c_ptr(s) == 2)
	{
		*bit += my_power(10, 4);
		e->west = ft_strdup(s[1]);
	}
	else if ((ft_strncmp(s[0], "EA", 3) == 0) && !e->east && my_c_ptr(s) == 2)
	{
		*bit += my_power(10, 3);
		e->east = ft_strdup(s[1]);
	}
	else if ((ft_strncmp(s[0], "S", 2) == 0) && !e->sprite && my_c_ptr(s) == 2)
	{
		*bit += my_power(10, 2);
		e->sprite = ft_strdup(s[1]);
	}
	else if ((ft_strncmp(s[0], "SO", 3) == 0) && !e->south && my_c_ptr(s) == 2)
	{
		*bit += my_power(10, 5);
		e->south = ft_strdup(s[1]);
	}
	else
		return (ft_chk_elem3(s, e, bit));
	return (1);
}

int	ft_chk_elem1(char **s, t_elem *e, int *bit)
{
	if (!*s)
		return (0);
	if ((ft_strncmp(s[0], "R", 2) == 0) && e->win_x < 0 && my_c_ptr(s) == 3)
	{
		*bit += my_power(10, 7);
		if (only_d(s[1], ' ') == 4 || only_d(s[2], ' ') == 4)
			error_free("window size must be number", e);
		if (s[1][0] == '0' || s[2][0] == '0')
			error_free("window size invalid", e);
		e->win_x = ft_strlen(s[1]) > 7 ? 10000 : ft_atoi(s[1]);
		e->win_y = ft_strlen(s[2]) > 7 ? 10000 : ft_atoi(s[2]);
	}
	else if ((ft_strncmp(s[0], "NO", 3) == 0) && !e->north && my_c_ptr(s) == 2)
	{
		*bit += my_power(10, 6);
		e->north = ft_strdup(s[1]);
	}
	else
		return (ft_chk_elem2(s, e, bit));
	return (1);
}

int	ft_read_cub(char *cub, t_elem *e)
{
	int		fd;
	char	*line;
	char	**src;
	int		bit;
	int		map_h;

	bit = 0;
	if ((fd = open(cub, O_RDONLY)) == -1)
		error("no such file or permission denied");
	while (bit < 11111111)
	{
		if (get_next_line(fd, &line) < 0)
			error("cannot read file (is it directry?)");
		src = ft_split(line, ' ');
		SAFE_FREE(line);
		if (ft_chk_elem1(src, e, &bit) < 0)
			error_free_ptr("cub elements error", e, src);
		my_free_ptr(src);
	}
	if ((map_h = ft_read_map(&bit, fd, &line, e)) < 0)
		error_free("map read error", e);
	close(fd);
	map_devide_check(cub, e);
	return (map_h);
}
