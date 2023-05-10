/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:46:16 by dpaal             #+#    #+#             */
/*   Updated: 2021/09/20 19:09:49 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	test(char target, char const *set)
{
	size_t	i;
	size_t	set_len;

	i = 0;
	set_len = ft_strlen(set);
	while (i < set_len)
	{
		if (set[i] == target)
			return (1);
		i++;
	}
	return (0);
}

static int	get_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (test(s1[i], set) && s1[i] != '\0')
		i++;
	return (i);
}

static int	get_finish(char const *s1, char const *set, int start)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (test(s1[i], set) && i > start)
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		finish;

	if (!s1)
		return (0);
	start = get_start(s1, set);
	finish = get_finish(s1, set, start);
	if (finish <= start)
	{
		str = ft_calloc(1, 1);
		if (!str)
			return (0);
		return (str);
	}
	else
	{
		str = malloc(finish - start + 2);
		if (!str)
			return (0);
		ft_memcpy(str, s1 + start, finish - start + 1);
		str[finish - start + 1] = '\0';
		return (str);
	}
}
