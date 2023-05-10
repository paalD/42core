/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:36:24 by dpaal             #+#    #+#             */
/*   Updated: 2022/05/20 12:48:34 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	find_next(t_list **list, int min, int max)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp && (tmp->content < min || tmp->content > max))
		tmp = tmp->next;
	if (!tmp)
		return (0);
	else
		return (tmp->content);
}

void	adjust_lists(t_list **stack_a, t_list **stack_b, int ac, int bc)
{
	while (ac > 0 && bc > 0)
	{
		ac -= rrr(stack_a, stack_b);
		bc--;
	}
	while (ac > 0)
		ac -= rra(stack_a);
	while (bc > 0)
		bc -= rrb(stack_b);
}
