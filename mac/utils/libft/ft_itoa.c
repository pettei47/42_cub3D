/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitagaw <tkitagaw@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 02:18:10 by tkitagaw          #+#    #+#             */
/*   Updated: 2020/07/16 20:21:54 by tkitagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	digit(long a)
{
	size_t	i;
	long	b;

	i = 0;
	b = a;
	if (b == 0)
		return (1);
	if (b < 0)
	{
		b *= -1;
		i++;
	}
	while (b > 0)
	{
		b /= 10;
		i++;
	}
	return (i);
}

static char		*ft_swap(char *s, size_t len)
{
	char	tmp;
	size_t	i;

	i = 0;
	while (i < len / 2)
	{
		tmp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = tmp;
		i++;
	}
	return (s);
}

char			*ft_itoa(int n)
{
	long	a;
	char	*out;
	size_t	i;
	size_t	dig;

	a = (long)n;
	dig = digit(a);
	i = 0;
	if (!(out = (char *)ft_calloc(sizeof(char), (dig + 1))))
		return (NULL);
	if (a < 0)
	{
		a *= -1;
		out[dig - 1] = '-';
		dig--;
	}
	while (i < dig)
	{
		out[i] = (a % 10) + '0';
		a /= 10;
		i++;
	}
	out = ft_swap(out, ft_strlen(out));
	return (out);
}
