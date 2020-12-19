/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_put_cs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitagaw <tkitagaw@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 18:46:45 by tkitagaw          #+#    #+#             */
/*   Updated: 2020/11/23 13:31:32 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*pf_ft_strchr(const char *s, int c)
{
	char	*out;

	out = (char *)s;
	while (*out)
	{
		if (*out == (char)c)
			return (out);
		out++;
	}
	if (*out == '\0' && c == '\0')
		return (out);
	return (0);
}

int		pf_ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int		my_put_c(t_flag *f, va_list ap)
{
	char	c;
	char	fill;
	int		i;

	i = 0;
	c = f->conv == '%' ? '%' : va_arg(ap, int);
	if (f->width < 1)
		f->width = 1;
	fill = f->zero == 1 ? '0' : ' ';
	if (f->minus == 1)
		write(1, &c, 1);
	while (f->width - i > 1)
	{
		write(1, &fill, 1);
		i++;
	}
	if (f->minus == 0)
		write(1, &c, 1);
	return (f->width);
}

int		my_put_s(t_flag *f, va_list ap)
{
	char	*s;
	char	fill;
	int		len;
	int		i;

	s = va_arg(ap, char *);
	if (s == NULL)
		s = "(null)";
	len = 0;
	fill = f->zero == 1 ? '0' : ' ';
	i = 0;
	while (s[len] && (len < f->prc_sz || f->prec == 0))
		len++;
	if (f->minus == 1)
		write(1, s, len);
	while (f->width - i > len)
	{
		write(1, &fill, 1);
		i++;
	}
	if (f->minus == 0)
		write(1, s, len);
	return (f->width > len ? f->width : len);
}
