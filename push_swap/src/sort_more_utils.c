/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:37:39 by dpaal             #+#    #+#             */
/*   Updated: 2022/05/19 23:09:47 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushrange_a(t_list **stack_a, t_list **stack_b, int min, int max)
{
	int	pivot;
	int	acount;
	int	bcount;
	int	closest;

	acount = 0;
	bcount = 0;
	if ((max - min + 2) * 2 >= listsize(stack_b))
		bcount = -2147483648;
	pivot = min + (max - min) / 2;
	closest = find_next(stack_b, min, max);
	while (closest)
	{
		while ((*stack_b)->content != closest)
			bcount += rb(stack_b);
		pa(stack_a, stack_b);
		if ((*stack_a)->content <= pivot)
			acount += ra(stack_a);
		closest = find_next(stack_b, min, max);
	}
	adjust_lists(stack_a, stack_b, acount, bcount);
}

void	pushrange_b(t_list **stack_a, t_list **stack_b, int min, int max)
{
	int	pivot;
	int	acount;
	int	bcount;
	int	closest;

	acount = 0;
	if ((max - min + 2) * 2 >= listsize(stack_a))
		acount = -2147483648;
	bcount = 0;
	pivot = min + (max - min) / 2;
	closest = find_next(stack_a, min, max);
	while (closest)
	{
		while ((*stack_a)->content != closest)
			acount += ra(stack_a);
		pb(stack_a, stack_b);
		if ((*stack_b)->content > pivot)
			bcount += rb(stack_b);
		closest = find_next(stack_a, min, max);
	}
	adjust_lists(stack_a, stack_b, acount, bcount);
}

void	simple_pr_a(t_list **stack_a, t_list **stack_b, int min, int max)
{
	int	closest;
	int	bcount;

	bcount = 0;
	closest = find_next(stack_b, min, max);
	while (closest)
	{
		while ((*stack_b)->content != closest)
			bcount += rb(stack_b);
		pa(stack_a, stack_b);
		closest = find_next(stack_b, min, max);
	}
	while (bcount > 0)
		bcount -= rrb(stack_b);
}

void	simple_pr_b(t_list **stack_a, t_list **stack_b, int min, int max)
{
	int	closest;
	int	acount;

	acount = 0;
	closest = find_next(stack_a, min, max);
	while (closest)
	{
		while ((*stack_a)->content != closest)
			acount += ra(stack_a);
		pb(stack_a, stack_b);
		closest = find_next(stack_a, min, max);
	}
	while (acount > 0)
		acount -= rra(stack_a);
}
