/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:16:04 by dpaal             #+#    #+#             */
/*   Updated: 2022/05/19 22:51:12 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	nextmin(t_list **list, long oldmin)
{
	t_list	*tmp;
	long	min;

	min = 2147483648;
	tmp = *list;
	while (tmp)
	{
		if (tmp->content < min && tmp->content > oldmin)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

t_list	*find_position(t_list **list, int n)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (tmp->content == n)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

void	index_lst(int listsize, t_list **list)
{
	int		n;
	long	min;
	t_list	**arr;

	n = 0;
	min = -2147483649;
	arr = malloc(sizeof(t_list **) * listsize);
	while (n < listsize)
	{
		min = nextmin(list, min);
		arr[n] = find_position(list, min);
		n++;
	}
	n = 0;
	while (n < listsize)
	{
		arr[n]->content = n + 1;
		n++;
	}
	free(arr);
}
