/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitagaw <tkitagaw@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:41:36 by tkitagaw          #+#    #+#             */
/*   Updated: 2020/12/12 18:09:27 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>

# define SAFE_FREE(ptr) { free(ptr); ptr = NULL; }

# define BUFFER_SIZE 1024

int		get_next_line(int fd, char **line);
char	*gnl_ft_strjoin(char const *s1, char const *s2);
size_t	gnl_ft_strlen(const char *s);
char	*gnl_ft_strdup(const char *src);
char	*gnl_ft_strchr(const char *s, int c);

#endif
