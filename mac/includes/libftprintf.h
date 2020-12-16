/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitagaw <tkitagaw@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 13:30:01 by tkitagaw          #+#    #+#             */
/*   Updated: 2020/11/23 13:34:58 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

# define SAFE_FREE(ptr) { free(ptr); ptr = NULL; }

typedef struct	s_flag
{
	char	conv;
	int		minus;
	int		zero;
	int		width;
	int		prec;
	int		prc_sz;
}				t_flag;

int				ft_printf(const char *fmt, ...);
void			my_set_prec(const char **fmt, t_flag *f, va_list ap);
void			my_set_width(const char **fmt, t_flag *f, va_list ap);
int				my_put_c(t_flag *f, va_list ap);
int				my_put_s(t_flag *f, va_list ap);
int				my_put_diu(t_flag *f, va_list ap);
int				my_put_x(t_flag *f, va_list ap);
int				my_put_p(t_flag *f, va_list ap);
int				my_putnbr(char *s, t_flag *f, int l);
char			*pf_ft_strchr(const char *s, int c);
int				pf_ft_strlen(char *s);
char			*my_prcnbr(char *s, int l, int len);

#endif
