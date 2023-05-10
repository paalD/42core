/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:55:14 by dpaal             #+#    #+#             */
/*   Updated: 2021/09/16 22:48:54 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*result;

	result = NULL;
	tmp = lst;
	while (tmp != NULL)
	{
		tmp2 = ft_lstnew(f(tmp->content));
		if (!tmp2)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, tmp2);
		tmp = tmp->next;
	}
	return (result);
}
