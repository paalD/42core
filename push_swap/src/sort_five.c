/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:30:12 by dpaal             #+#    #+#             */
/*   Updated: 2022/05/19 22:54:21 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	three_notsimple(t_list **stack_a)
{
	if (!(*stack_a)->next->next)
		return ;
	if ((*stack_a)->content > (*stack_a)->next->content && \
		(*stack_a)->content > (*stack_a)->next->next->content)
		sa(stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content && \
		(*stack_a)->next->content < (*stack_a)->next->next->content)
		sa(stack_a);
	if ((*stack_a)->content < (*stack_a)->next->content && \
		(*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a);
}

static void	three_simple(t_list **stack_a)
{
	if (!(*stack_a)->next->next)
		return ;
	if ((*stack_a)->content < (*stack_a)->next->content && \
		(*stack_a)->next->content < (*stack_a)->next->next->content)
		return ;
	if ((*stack_a)->content > (*stack_a)->next->content && \
		(*stack_a)->next->content > (*stack_a)->next->next->content)
		sa(stack_a);
	if ((*stack_a)->content < (*stack_a)->next->next->content && \
		(*stack_a)->next->content > (*stack_a)->next->next->content)
		sa(stack_a);
	if ((*stack_a)->content < (*stack_a)->next->next->content)
		sa(stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content)
		ra(stack_a);
	if ((*stack_a)->next->content > (*stack_a)->next->next->content)
		rra(stack_a);
}

static void	insert_number(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp && (*stack_b)->content < tmp->content)
		tmp = tmp->next;
	while (tmp && (*stack_b)->content > tmp->content)
		tmp = tmp->next;
	if (tmp)
		smart_rotate(stack_a, tmp->content);
	else if ((*stack_b)->content > listmax(stack_a) || \
			(*stack_b)->content < listmin(stack_a))
		smart_rotate(stack_a, listmin(stack_a));
	pa(stack_a, stack_b);
}

static int	islastmax(t_list **stack_a, int n)
{
	int		i;
	int		last;
	t_list	*tmp;

	i = 1;
	tmp = *stack_a;
	while (i < n)
	{
		i++;
		tmp = tmp->next;
	}
	last = tmp->content;
	tmp = *stack_a;
	i = 1;
	while (i < n)
	{
		i++;
		if (tmp->content > last)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_five(t_list **stack_a, t_list **stack_b, int n)
{
	int	test;

	test = islastmax(stack_a, n);
	while (test && n >= 2)
	{
		n--;
		test = islastmax(stack_a, n);
	}
	if (n < 2)
		return ;
	if (n == 2)
		sa(stack_a);
	if (n == 5)
		pb(stack_a, stack_b);
	if (n >= 4)
		pb(stack_a, stack_b);
	if (n == 2 || !(*stack_a)->next->next->next)
		three_simple(stack_a);
	else
		three_notsimple(stack_a);
	if (n >= 4)
		insert_number(stack_a, stack_b);
	if (n == 5)
		insert_number(stack_a, stack_b);
	smart_rotate(stack_a, listmin(stack_a));
}
