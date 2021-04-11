/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aacquist <aacquist@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 09:56:21 by aacquist          #+#    #+#             */
/*   Updated: 2020/12/07 21:23:33 by aacquist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*rslt;
	t_list	*new;
	t_list	*newtwo;

	if (!lst)
		return (NULL);
	if (!(rslt = malloc(sizeof(t_list) * ft_lstsize(lst))))
		return (NULL);
	rslt = NULL;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&rslt, del);
			return (NULL);
		}
		if (!rslt)
			rslt = new;
		else
			newtwo->next = new;
		newtwo = new;
		lst = lst->next;
	}
	return (rslt);
}
