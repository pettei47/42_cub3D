/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_put_diu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitagaw <tkitagaw@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 19:57:48 by tkitagaw          #+#    #+#             */
/*   Updated: 2020/11/23 13:32:49 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	digit(long long a)
{
	int			i;
	long long	b;

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

static char	*my_itoa(long long d)
{
	char		*a;
	int			dig;
	int			i;
	int			m;

	dig = digit(d);
	m = 0;
	if (!(a = (char *)malloc(sizeof(char) * dig + 1)))
		return (NULL);
	i = 1;
	if (d < 0)
	{
		d *= -1;
		a[0] = '-';
		m = 1;
	}
	while (i <= (dig - m))
	{
		a[dig - i] = ((d % 10) + '0');
		i++;
		d /= 10;
	}
	a[dig] = '\0';
	return (a);
}

int			my_put_diu(t_flag *f, va_list ap)
{
	long	d;
	char	*s;
	int		zero;

	zero = 0;
	if (f->conv == 'u')
		d = (long)va_arg(ap, unsigned int);
	else
		d = (long)va_arg(ap, int);
	if (f->zero == 1 && d < 0)
	{
		write(1, "-", 1);
		d *= -1;
		f->width -= 1;
		zero = 1;
	}
	if (!(s = my_itoa((long long)d)))
		return (0);
	return (my_putnbr(s, f, pf_ft_strlen(s)) + zero);
}
