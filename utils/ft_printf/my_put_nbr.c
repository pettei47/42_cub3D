/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_put_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitagaw <tkitagaw@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 00:13:44 by tkitagaw          #+#    #+#             */
/*   Updated: 2020/08/21 01:24:27 by tkitagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*my_prcnbr(char *s, int l, int len)
{
	char	*n;
	int		i;

	i = 0;
	if (!(n = (char *)malloc(sizeof(char) * (len + 1))))
		return (s);
	if (s[0] == '-')
	{
		n[0] = '-';
		while (len - i++ > l)
			n[i] = '0';
	}
	else
	{
		while (len - i > l)
			n[i++] = '0';
	}
	while (s[i - (len - l)])
	{
		n[i] = s[i - (len - l)];
		i++;
	}
	n[i] = '\0';
	SAFE_FREE(s);
	return (n);
}

int		my_putnbr(char *s, t_flag *f, int l)
{
	char	fill;
	int		len;
	int		i;

	fill = f->zero == 1 ? '0' : ' ';
	i = 0;
	if (f->prec == 1 && l <= f->prc_sz && s[0] == '-')
		len = f->prc_sz + 1;
	else if (f->prec == 1 && l - 1 < f->prc_sz && s[0] != '-')
		len = f->prc_sz;
	else
		len = l;
	len = (f->prc_sz == 0 && f->prec == 1 && s[0] == '0') ? 0 : len;
	if (f->prec == 1 && l != len)
		s = my_prcnbr(s, l, len);
	if (f->minus == 1)
		write(1, s, len);
	while (f->width - i++ > len)
		write(1, &fill, 1);
	if (f->minus == 0)
		write(1, s, len);
	SAFE_FREE(s);
	return (f->width > len ? f->width : len);
}
