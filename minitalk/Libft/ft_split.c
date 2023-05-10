/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:11:52 by dpaal             #+#    #+#             */
/*   Updated: 2021/09/20 20:12:43 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	word_count(char const *s, char c)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\0')
		{
			res++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		if (s[i] == '\0')
			break ;
		i++;
	}
	return (res);
}

static void	s_word(char **arr, char const *s, char c)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c && s[i - 1] == c && i > 0) || (s[i] != c && i == 0))
		{
			j = i;
			while (s[j + 1] != c && s[j + 1] != '\0')
				j++;
			arr[count] = ft_substr(s, i, j - i + 1);
			count++;
			i++;
		}
		else
			i++;
	}
	arr[count] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		count;

	if (!s)
		return (0);
	count = word_count(s, c);
	if (count == 0)
	{
		arr = malloc(sizeof(void *));
		if (!arr)
			return (0);
		arr[0] = 0;
		return (arr);
	}
	arr = malloc((count + 1) * sizeof(void *));
	if (!arr)
		return (0);
	s_word(arr, s, c);
	return (arr);
}
