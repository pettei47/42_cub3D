/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_only.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 12:31:05 by teppei            #+#    #+#             */
/*   Updated: 2020/12/14 00:34:10 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	only_d(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < '0' || '9' < str[i]) && str[i] != c)
			return (0);
		i++;
	}
	return (1);
}