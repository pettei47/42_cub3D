/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitagaw <tkitagaw@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:31:18 by tkitagaw          #+#    #+#             */
/*   Updated: 2020/11/23 19:08:26 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	my_mkline(char **line, char **save, char *nl, int ret)
{
	char	*tmp;

	if (!(*line = gnl_ft_strdup(*save)))
	{
		SAFE_FREE(*save);
		return (1);
	}
	if (ret == 1)
	{
		if (!(tmp = gnl_ft_strdup(nl + 1)))
		{
			SAFE_FREE(*save);
			return (1);
		}
		SAFE_FREE(*save);
		*save = tmp;
	}
	else
		SAFE_FREE(*save);
	return (0);
}

static int	my_chkline(char **line, char **save, int rc)
{
	int		ret;
	char	*nl;

	ret = 0;
	if (rc < 0)
	{
		SAFE_FREE(*save);
		return (-1);
	}
	if (!*save)
	{
		if (!(*line = gnl_ft_strdup("")))
			return (-1);
		return (0);
	}
	if ((nl = gnl_ft_strchr(*save, '\n')) != 0)
	{
		*nl = '\0';
		ret = 1;
	}
	if (my_mkline(line, save, nl, ret) == 0)
		return (ret);
	return (-1);
}

static int	my_mksave(char **save, char **buf)
{
	char	*tmp;

	if (!*save)
	{
		if (!(*save = gnl_ft_strdup(*buf)))
		{
			SAFE_FREE(*buf);
			return (-1);
		}
	}
	else
	{
		if (!(tmp = gnl_ft_strjoin(*save, *buf)))
		{
			SAFE_FREE(*save);
			SAFE_FREE(*buf);
			return (-1);
		}
		SAFE_FREE(*save);
		*save = tmp;
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*save[256];
	char		*buf;
	int			rc;

	if (fd < 0 || fd == 1 || fd == 2 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
	{
		SAFE_FREE(save[fd]);
		return (-1);
	}
	while ((rc = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rc] = '\0';
		if (my_mksave(&save[fd], &buf) == -1)
			return (-1);
		if (gnl_ft_strchr(save[fd], '\n'))
			break ;
	}
	SAFE_FREE(buf);
	return (my_chkline(line, &save[fd], rc));
}
