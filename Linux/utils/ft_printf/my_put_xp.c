/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_put_xp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitagaw <tkitagaw@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 21:41:31 by tkitagaw          #+#    #+#             */
/*   Updated: 2020/11/23 13:33:38 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*my_itoa_hex(unsigned long x)
{
	unsigned long	n;
	char			*a;
	int				i;
	int				digit;

	n = x;
	digit = 1;
	i = 1;
	while ((n / 16) > 0)
	{
		n /= 16;
		digit++;
	}
	a = (char *)malloc(sizeof(char) * (digit + 1));
	while (i <= digit)
	{
		a[digit - i] = "0123456789abcdef"[x % 16];
		x /= 16;
		i++;
	}
	a[digit] = '\0';
	return (a);
}

int			my_put_x(t_flag *f, va_list ap)
{
	unsigned int	x;
	char			*s;
	int				i;

	i = 0;
	x = va_arg(ap, unsigned int);
	if (!(s = my_itoa_hex(x)))
		return (0);
	if (f->conv == 'X')
	{
		while (s[i])
		{
			if ('a' <= s[i] && s[i] <= 'z')
				s[i] -= 32;
			i++;
		}
	}
	return (my_putnbr(s, f, pf_ft_strlen(s)));
}

static int	my_putptr(char *s, t_flag *f, int l)
{
	char	fill;
	int		i;
	int		len;

	fill = f->zero == 1 ? '0' : ' ';
	i = 0;
	len = l;
	if (l < f->prc_sz && f->prec == 1)
	{
		len = f->prc_sz;
		s = my_prcnbr(s, l, len);
	}
	if (f->minus == 1)
		write(1, "0x", 2);
	if (f->minus == 1)
		write(1, s, len);
	while (f->width - i++ > (len + 2))
		write(1, &fill, 1);
	if (f->minus == 0)
	{
		write(1, "0x", 2);
		write(1, s, len);
	}
	SAFE_FREE(s);
	return (f->width > (len + 2) ? f->width : (len + 2));
}

int			my_put_p(t_flag *f, va_list ap)
{
	unsigned long	p;
	char			*s;
	int				i;

	i = 0;
	p = va_arg(ap, unsigned long);
	if (!(s = my_itoa_hex(p)))
		return (0);
	if (f->prec == 1 && f->prc_sz == 0)
	{
		if (f->minus == 1)
			write(1, "0x", 2);
		while (f->width - i++ > 2)
			write(1, " ", 1);
		if (f->minus == 0)
			write(1, "0x", 2);
		return (2 > f->width ? 2 : f->width);
	}
	return (my_putptr(s, f, pf_ft_strlen(s)));
}
