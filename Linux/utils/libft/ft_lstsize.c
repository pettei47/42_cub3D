/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitagaw <tkitagaw@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 09:11:05 by tkitagaw          #+#    #+#             */
/*   Updated: 2020/07/17 09:18:33 by tkitagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *l)
{
	int		size;

	if (!l)
		return (0);
	size = 0;
	while (l)
	{
		size++;
		l = l->next;
	}
	return (size);
}
