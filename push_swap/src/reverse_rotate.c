/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:41:08 by dpaal             #+#    #+#             */
/*   Updated: 2022/05/19 23:06:56 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*lst;
	t_list	*tmp;

	lst = *stack;
	tmp = *stack;
	if (!lst || !lst->next)
		return ;
	if (!lst->next->next)
	{
		swap(stack);
		return ;
	}
	while (lst->next->next)
		lst = lst->next;
	*stack = lst->next;
	lst->next->next = tmp;
	lst->next = NULL;
}

int	rra(t_list **stack)
{
	reverse_rotate(stack);
	write(1, "rra\n", 4);
	return (1);
}

int	rrb(t_list **stack)
{
	reverse_rotate(stack);
	write(1, "rrb\n", 4);
	return (1);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
	return (1);
}
