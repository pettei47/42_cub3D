/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitagaw <tkitagaw@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 22:11:30 by tkitagaw          #+#    #+#             */
/*   Updated: 2020/07/13 18:39:05 by tkitagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*p;
	unsigned char	*q;
	size_t			i;

	p = (unsigned char*)dst;
	q = (unsigned char*)src;
	i = 0;
	if (dst == src)
		return (dst);
	while (n > 0)
	{
		*p++ = *q++;
		n--;
	}
	return (dst);
}
