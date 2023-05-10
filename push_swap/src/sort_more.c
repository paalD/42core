/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:37:42 by dpaal             #+#    #+#             */
/*   Updated: 2022/05/19 22:39:07 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_more_back(t_list **stack_a, t_list **stack_b, int min, int max)
{
	int	pivot;

	pivot = min + (max - min) / 2;
	if (max - min < 10)
	{
		if (max - min >= 5)
		{
			simple_pr_a(stack_a, stack_b, max - 4, max);
			sort_five(stack_a, stack_b, 5);
			simple_pr_a(stack_a, stack_b, min, max - 5);
			sort_five(stack_a, stack_b, max - min - 4);
		}
		else
		{
			simple_pr_a(stack_a, stack_b, min, max);
			sort_five(stack_a, stack_b, max - min + 1);
		}
		return ;
	}
	if (max - pivot + 1 >= 1)
		pushrange_a(stack_a, stack_b, pivot + 1, max);
	else
		simple_pr_a(stack_a, stack_b, pivot + 1, max);
	sort_more(stack_a, stack_b, pivot + 1, max);
	sort_more_back(stack_a, stack_b, min, pivot);
}

void	sort_more(t_list **stack_a, t_list **stack_b, int min, int max)
{
	int	pivot;

	pivot = min + (max - min) / 2;
	if (max - min < 10)
	{
		if (max - min >= 5)
		{
			simple_pr_b(stack_a, stack_b, min, max - 5);
			sort_five(stack_a, stack_b, 5);
			simple_pr_a(stack_a, stack_b, min, max - 5);
			sort_five(stack_a, stack_b, max - min - 4);
		}
		else
			sort_five(stack_a, stack_b, max - min + 1);
		return ;
	}
	if (pivot - min >= 20)
		pushrange_b(stack_a, stack_b, min, pivot);
	else
		simple_pr_b(stack_a, stack_b, min, pivot);
	sort_more(stack_a, stack_b, pivot + 1, max);
	sort_more_back(stack_a, stack_b, min, pivot);
}
