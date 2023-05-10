/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:39:29 by dpaal             #+#    #+#             */
/*   Updated: 2022/05/19 23:06:34 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **stack)
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
	*stack = lst->next;
	while (lst->next)
		lst = lst->next;
	lst->next = tmp;
	tmp->next = NULL;
}

int	ra(t_list **stack)
{
	rotate(stack);
	write(1, "ra\n", 3);
	return (1);
}

int	rb(t_list **stack)
{
	rotate(stack);
	write(1, "rb\n", 3);
	return (1);
}

int	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
	return (1);
}
