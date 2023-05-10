/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:33:45 by dpaal             #+#    #+#             */
/*   Updated: 2022/05/20 13:16:05 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	push(t_list **src, t_list **dest)
{
	t_list	*tmp;

	tmp = ft_lstnew((*src)->content);
	if (*dest)
		tmp->next = *dest;
	*dest = tmp;
	tmp = *src;
	*src = (*src)->next;
	free(tmp);
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	return (1);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	return (1);
}
