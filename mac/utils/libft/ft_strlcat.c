/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitagaw <tkitagaw@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 20:09:06 by tkitagaw          #+#    #+#             */
/*   Updated: 2020/07/06 22:08:55 by tkitagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	szdst;
	size_t	lendst;
	size_t	i;

	szdst = ft_strlen(dest);
	lendst = szdst;
	i = 0;
	if (size <= szdst)
		return (ft_strlen(src) + size);
	while (i < size - lendst - 1 && src[i])
	{
		dest[szdst] = src[i];
		i++;
		szdst++;
	}
	dest[szdst] = '\0';
	return (szdst + ft_strlen(src) - i);
}
