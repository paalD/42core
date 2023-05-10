/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:36:56 by dpaal             #+#    #+#             */
/*   Updated: 2022/05/19 23:07:27 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	int		i;
	t_list	*tmp;

	tmp = *stack;
	i = tmp->content;
	tmp->content = tmp->next->content;
	tmp->next->content = i;
}

int	sa(t_list **stack)
{
	swap(stack);
	write(1, "sa\n", 3);
	return (1);
}

int	sb(t_list **stack)
{
	swap(stack);
	write(1, "sb\n", 3);
	return (1);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
	return (1);
}
