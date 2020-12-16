/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitagaw <tkitagaw@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 14:09:11 by tkitagaw          #+#    #+#             */
/*   Updated: 2020/07/17 08:52:04 by tkitagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		chklen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_strdup(const char *src)
{
	char	*dest;
	int		src_len;
	int		i;

	src_len = chklen(src);
	if (!(dest = (char *)malloc(sizeof(char) * (src_len + 1))))
		return (NULL);
	i = 0;
	while (i < src_len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
