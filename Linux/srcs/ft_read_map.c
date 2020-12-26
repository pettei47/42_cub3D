/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:15:03 by teppei            #+#    #+#             */
/*   Updated: 2020/12/27 00:43:22 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_cub(int argc, char **argv, t_elem *e)
{
	int		len;
	char	*str;

	if (argc < 2 || 3 < argc)
		error("check argments : short or over");
	if (argc == 3)
	{
		if (!ft_strncmp(argv[2], "--save", 7))
			e->save = 1;
		else
			error("2nd argment is not \"--save\"");
	}
	if (argc == 3 || argc == 2)
	{
		str = &argv[1][0];
		if (ft_strrchr(argv[1], '/'))
			str = ft_strrchr(argv[1], '/') + 1;
		len = ft_strlen(str);
		if (len < 5 || ft_strncmp(str + len - 4, ".cub", 5))
			error("file not \".cub\"");
	}
}

void	ft_rev_map(char **map, int size)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = map[i];
		map[i] = map[size - i - 1];
		map[size - i - 1] = tmp;
		i++;
	}
}

int		ft_read_map(int *bit, int fd, char **line, t_elem *e)
{
	int		ret;
	int		i;

	i = 0;
	while (*bit < 111111111 && i < MAP_HEIGHT)
	{
		if ((ret = get_next_line(fd, line)) == 0)
		{
			if (ft_strncmp(*line, "", 1) != 0)
				e->map[i++] = ft_strdup(*line);
			e->map[i] = NULL;
			*bit += my_power(10, 8);
		}
		if (ret == 1 && ft_strncmp(*line, "", 1) != 0)
			e->map[i++] = ft_strdup(*line);
		if (ft_strlen(*line) >= MAP_WIDTH)
			error_devide("too big map (x)", *line, e);
		SAFE_FREE(*line);
	}
	if (i >= MAP_HEIGHT)
		error("too big map (y)");
	SAFE_FREE(*line);
	ft_rev_map(e->map, i);
	return (i);
}

void	map_devide_check2(int fd, char **line, t_elem *e)
{
	while (get_next_line(fd, line))
	{
		if (ft_strncmp(*line, "", 2) != 0)
		{
			close(fd);
			error_devide("somthing exist under map", *line, e);
		}
		SAFE_FREE(*line);
	}
}

void	map_devide_check(char *cub, t_elem *e)
{
	int		fd;
	char	*line;
	int		i;
	int		readm;

	readm = 0;
	fd = open(cub, O_RDONLY);
	while (get_next_line(fd, &line) && readm < 2)
	{
		i = 0;
		while (line[i] == ' ')
			i++;
		if (line[i] == '0' || line[i] == '1')
			readm = 1;
		if (readm == 1 && ft_strncmp(line, "", 2) == 0)
		{
			readm = 2;
			SAFE_FREE(line);
			map_devide_check2(fd, &line, e);
		}
		SAFE_FREE(line);
	}
	close(fd);
	SAFE_FREE(line);
}
