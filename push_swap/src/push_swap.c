/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:24:04 by dpaal             #+#    #+#             */
/*   Updated: 2022/05/22 12:58:47 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*create_lst(int argc, char *argv[])
{
	int		i;
	t_list	*stack_a;

	stack_a = ft_lstnew(ft_atolli(argv[1]));
	i = 2;
	while (i < argc)
	{
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atolli(argv[i])));
		i++;
	}
	return (stack_a);
}

static void	free_lst(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (*list)
	{
		*list = (*list)->next;
		free(tmp);
		tmp = *list;
	}
}

int	sorted(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp && tmp->next)
	{
		if (tmp->next->content != tmp->content + 1)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	if (!check_input(argc, argv))
		return (0);
	if (argc <= 2)
		return (0);
	else
	{
		stack_a = create_lst(argc, argv);
		index_lst(&stack_a, argc - 1);
		if (!sorted(&stack_a))
		{
			if (argc <= 6)
				sort_five(&stack_a, &stack_b, argc - 1);
			else
				sort_more(&stack_a, &stack_b, 1, argc - 1);
		}
		free_lst(&stack_a);
		if (stack_b != NULL)
			free_lst(&stack_b);
	}
	return (0);
}
