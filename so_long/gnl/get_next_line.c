/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:40:22 by dpaal             #+#    #+#             */
/*   Updated: 2021/11/26 14:14:47 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 200
#endif

static int	leftover(char **result, char **remainder)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strchr(*remainder, '\n');
	if (!tmp)
	{
		tmp2 = *result;
		*result = ft_strjoin(*result, *remainder);
		free(tmp2);
		free(*remainder);
		*remainder = NULL;
		return (0);
	}
	else
	{
		tmp2 = *remainder;
		*remainder = ft_strdup(++tmp);
		*tmp = '\0';
		tmp = *result;
		*result = ft_strjoin(*result, tmp2);
		free(tmp);
		free(tmp2);
		return (1);
	}
}

static void	reading(char **result, char **remainder, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*tmp;
	ssize_t	check;

	check = read(fd, buffer, BUFFER_SIZE);
	buffer[check] = '\0';
	if (check == 0 || check == -1)
		return ;
	tmp = ft_strchr(buffer, '\n');
	if (!tmp)
	{
		tmp = *result;
		*result = ft_strjoin(*result, buffer);
		free(tmp);
		reading(result, remainder, fd);
	}
	else
	{
		if (++tmp)
			*remainder = ft_strdup(tmp);
		*tmp = '\0';
		tmp = *result;
		*result = ft_strjoin(*result, buffer);
		free(tmp);
	}
}

char	*get_next_line(int fd)
{
	static char	*remainder = NULL;
	char		*result;
	int			check;

	if (fd < 0 || fd > 1024)
		return (0);
	result = malloc(sizeof(char));
	result[0] = '\0';
	if (remainder)
	{
		check = leftover(&result, &remainder);
		if (!remainder && !check)
			reading(&result, &remainder, fd);
		else
			return (result);
	}
	else
		reading(&result, &remainder, fd);
	if (result[0] == '\0')
	{
		free(result);
		return (0);
	}
	return (result);
}
