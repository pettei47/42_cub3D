/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitagaw <tkitagaw@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 14:39:48 by tkitagaw          #+#    #+#             */
/*   Updated: 2020/11/23 13:32:16 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	my_flag_reset(t_flag *f)
{
	f->conv = '\0';
	f->minus = 0;
	f->zero = 0;
	f->width = 0;
	f->prec = 0;
	f->prc_sz = 0;
}

static void	my_flag_chk(char **fmt, t_flag *f, va_list ap)
{
	while (**fmt != f->conv)
	{
		if (**fmt == '-')
		{
			f->minus = 1;
			*fmt += 1;
		}
		else if (**fmt == '0' && f->prec == 0)
		{
			f->zero = 1;
			*fmt += 1;
		}
		else if (((47 < **fmt && **fmt < 58) || **fmt == '*') && f->prec < 1)
			my_set_width((const char **)fmt, f, ap);
		else if (**fmt == '.')
		{
			f->prec = 1;
			my_set_prec((const char **)fmt, f, ap);
		}
		else
			*fmt += 1;
	}
	*fmt += 1;
	f->zero = f->minus == 1 ? 0 : f->zero;
	f->zero = (f->prec == 1 && (pf_ft_strchr("pdiuixX", f->conv))) ? 0 : f->zero;
}

static int	my_set_conv(char *fmt, t_flag *f)
{
	int	i;

	i = 0;
	while (fmt[i])
	{
		if (pf_ft_strchr("cspdiuxX%", fmt[i]))
		{
			f->conv = fmt[i];
			return (1);
		}
		i++;
	}
	return (0);
}

static int	my_chk_conv(char **fmt, t_flag *f, va_list ap)
{
	*fmt += 1;
	if (my_set_conv(*fmt, f) == 0)
		return (-1);
	my_flag_chk(fmt, f, ap);
	if (f->conv == 'c' || f->conv == '%')
		return (my_put_c(f, ap));
	if (f->conv == 's')
		return (my_put_s(f, ap));
	if (f->conv == 'p')
		return (my_put_p(f, ap));
	if (f->conv == 'd' || f->conv == 'i' || f->conv == 'u')
		return (my_put_diu(f, ap));
	if (f->conv == 'x' || f->conv == 'X')
		return (my_put_x(f, ap));
	return (-1);
}

int			ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_flag	f;
	int		ret;
	int		pc;

	va_start(ap, fmt);
	my_flag_reset(&f);
	ret = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			if ((pc = my_chk_conv((char **)&fmt, &f, ap)) < 0)
				return (ret);
			ret += pc;
			my_flag_reset(&f);
		}
		else
		{
			write(1, fmt++, 1);
			ret++;
		}
	}
	va_end(ap);
	return (ret);
}
