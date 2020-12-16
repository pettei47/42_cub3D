/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_set_width_prec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitagaw <tkitagaw@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 18:15:02 by tkitagaw          #+#    #+#             */
/*   Updated: 2020/08/20 13:19:28 by tkitagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	my_set_width(const char **fmt, t_flag *f, va_list ap)
{
	if (**fmt == '*')
	{
		if ((f->width = va_arg(ap, int)) < 0)
		{
			f->width *= -1;
			f->minus = 1;
		}
		*fmt += 1;
		return ;
	}
	f->width = 0;
	while ('0' <= **fmt && **fmt <= '9')
	{
		f->width = (f->width * 10) + (**fmt - '0');
		*fmt += 1;
	}
}

void	my_set_prec(const char **fmt, t_flag *f, va_list ap)
{
	*fmt += 1;
	if (**fmt == '*')
	{
		if ((f->prc_sz = va_arg(ap, int)) < 0)
			f->prec = 0;
		*fmt += 1;
		return ;
	}
	f->prc_sz = 0;
	while ('0' <= **fmt && **fmt <= '9')
	{
		f->prc_sz = (f->prc_sz * 10) + (**fmt - '0');
		*fmt += 1;
	}
}
