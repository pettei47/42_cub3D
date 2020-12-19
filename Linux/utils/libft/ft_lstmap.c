/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitagaw <tkitagaw@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 14:49:22 by tkitagaw          #+#    #+#             */
/*   Updated: 2020/07/18 00:34:02 by tkitagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *l, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*i;

	if (!l || !f)
		return (NULL);
	if (!(i = ft_lstnew(NULL)))
		return (NULL);
	new = i;
	while (i)
	{
		i->content = f(l->content);
		if (!(l->next))
			break ;
		if (!(i->next = ft_lstnew(NULL)))
		{
			ft_lstclear(&i, del);
			return (NULL);
		}
		i = i->next;
		l = l->next;
	}
	return (new);
}
