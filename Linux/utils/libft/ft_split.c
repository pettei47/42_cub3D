/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitagaw <tkitagaw@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 00:47:26 by tkitagaw          #+#    #+#             */
/*   Updated: 2020/12/13 12:41:33 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	c_count(char const *s, char c)
{
	char	*str;
	size_t	i;
	size_t	count;

	str = (char *)s;
	i = 1;
	count = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] != c && str[i - 1] == c)
			count++;
		i++;
	}
	count++;
	if (str[i] == '\0' && str[i - 1] != c)
		count++;
	return (count);
}

static char		*mkstr(char *s, char c, char *o)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (s[len] != c && s[len])
		len++;
	if (!(o = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		o[i] = s[i];
		i++;
	}
	o[i] = '\0';
	return (o);
}

static void		my_free(char **o)
{
	size_t	i;

	i = 0;
	while (o[i])
		free(o[i++]);
	free(o);
}

char			**ft_split(char const *s, char c)
{
	char	**outcome;
	char	*str;
	size_t	i;

	if (s == NULL)
		return (NULL);
	str = (char *)s;
	if (!(outcome = (char **)malloc(sizeof(char *) * (c_count(s, c) + 2))))
		return (NULL);
	i = 0;
	while (*str)
	{
		if (*str != c)
		{
			if (!(outcome[i] = mkstr(str, c, outcome[i])))
			{
				my_free(outcome);
				return (NULL);
			}
			str += ft_strlen(outcome[i++]) - 1;
		}
		str++;
	}
	outcome[i] = NULL;
	return (outcome);
}
