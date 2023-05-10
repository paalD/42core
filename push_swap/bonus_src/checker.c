/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:15:33 by dpaal             #+#    #+#             */
/*   Updated: 2022/05/22 18:52:11 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	**read_inputs(t_list **stack_a, int argc, char **argv)
{
	int		i;
	char	*ops;
	char	*buf;
	char	**ops_arr;

	i = 2;
	while (i < argc)
		i += ft_lstadd_back(stack_a, ft_lstnew(ft_atolli(argv[i])));
	index_lst(argc - 1, stack_a);
	ops = ft_calloc(sizeof(char), 2);
	buf = ft_calloc(sizeof(char), 2);
	i = read(0, buf, 1);
	while (i)
	{
		if (ops[0])
			ops = ft_strjoin(ops, buf);
		else
			ft_strlcpy(ops, buf, 2);
		i = read(0, buf, 1);
	}
	ops_arr = ft_split(ops, '\n');
	free(buf);
	free(ops);
	return (ops_arr);
}

int	execute_instruction(t_list **stack_a, t_list **stack_b, char *line)
{
	if (!ft_strcmp(line, "sa"))
		sa(stack_a);
	else if (!ft_strcmp(line, "sb"))
		sb(stack_b);
	else if (!ft_strcmp(line, "ss"))
		ss(stack_a, stack_b);
	else if (!ft_strcmp(line, "pa"))
		pa(stack_a, stack_b);
	else if (!ft_strcmp(line, "pb"))
		pb(stack_a, stack_b);
	else if (!ft_strcmp(line, "ra"))
		ra(stack_a);
	else if (!ft_strcmp(line, "rb"))
		rb(stack_b);
	else if (!ft_strcmp(line, "rr"))
		rr(stack_a, stack_b);
	else if (!ft_strcmp(line, "rra"))
		rra(stack_a);
	else if (!ft_strcmp(line, "rrb"))
		rrb(stack_b);
	else if (!ft_strcmp(line, "rrr"))
		rrr(stack_a, stack_b);
	else
		return (0);
	return (1);
}

void	sort_and_check(t_list **stack_a, t_list **stack_b, char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (!execute_instruction(stack_a, stack_b, arr[i]))
		{
			write(1, "Error\n", 6);
			return ;
		}
		i++;
	}
	check_list(stack_a, stack_b);
}

void	free_contents(t_list **stack_a, t_list **stack_b, char **ops_arr)
{
	int	i;

	if (stack_a)
		free_list(stack_a);
	if (stack_b)
		free_list(stack_b);
	i = 0;
	while (ops_arr[i])
	{
		free(ops_arr[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**ops_arr;

	stack_b = NULL;
	if (!check_input(argc, argv))
		return (0);
	if (argc <= 2)
		return (0);
	stack_a = ft_lstnew(ft_atolli(argv[1]));
	ops_arr = read_inputs(&stack_a, argc, argv);
	sort_and_check(&stack_a, &stack_b, ops_arr);
	free_contents(&stack_a, &stack_b, ops_arr);
	free(ops_arr);
	if (stack_a)
		free(stack_a);
	if (stack_b)
		free(stack_b);
	return (0);
}
