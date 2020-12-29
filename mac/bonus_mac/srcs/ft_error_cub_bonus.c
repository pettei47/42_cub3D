/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_cub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 19:01:17 by teppei            #+#    #+#             */
/*   Updated: 2020/12/13 13:58:12 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	my_free_e(t_elem *e)
{
	int	i;

	i = 0;
	SAFE_FREE(e->north);
	SAFE_FREE(e->south);
	SAFE_FREE(e->west);
	SAFE_FREE(e->east);
	SAFE_FREE(e->sprite);
	while (e->map[i])
	{
		SAFE_FREE(e->map[i]);
		i++;
	}
}

int		error(char *msg)
{
	ft_putstr_fd(DEFAULT, 2);
	ft_putendl_fd("Error", 2);
	ft_putstr_fd(RED, 2);
	ft_putendl_fd(msg, 2);
	ft_putstr_fd(DEFAULT, 2);
	exit(EXIT_FAILURE);
}

void	error_free(char *msg, t_elem *e)
{
	my_free_e(e);
	error(msg);
}

void	error_free_ptr(char *msg, t_elem *e, char **s)
{
	my_free_e(e);
	my_free_ptr(s);
	error(msg);
}

void	error_devide(char *msg, char *line, t_elem *e)
{
	SAFE_FREE(line);
	error_free(msg, e);
}
