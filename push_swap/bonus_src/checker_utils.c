/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:15:31 by dpaal             #+#    #+#             */
/*   Updated: 2022/05/20 12:41:45 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while ((unsigned char)s1[i] != '\0')
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if ((unsigned char)s1[i] != (unsigned char)s2[i])
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

int	check_list(t_list **list, t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_b)
	{
		write(1, "KO\n", 3);
		return (0);
	}
	tmp = *list;
	while (tmp && tmp->next)
	{
		if (tmp->next->content != tmp->content + 1)
		{
			write(1, "KO\n", 3);
			return (0);
		}
		tmp = tmp->next;
	}
	write(1, "OK\n", 3);
	return (1);
}

void	free_list(t_list **list)
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
