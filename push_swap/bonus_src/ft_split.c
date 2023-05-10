/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:11:52 by dpaal             #+#    #+#             */
/*   Updated: 2022/05/20 12:29:27 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	*single_word(char const *s, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	word = malloc(sizeof(char) * i + 1);
	word[i] = '\0';
	if (s[i] == c)
		i--;
	while (i >= 0)
	{
		word[i] = s[i];
		i--;
	}
	return (word);
}

static int	count_words(char const *s, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			words++;
		while (s[i] != c)
		{
			if (s[i] == '\0')
				break ;
			i++;
		}
	}
	return (words);
}

static void	write_words(char const *s, char c, int *words, char **pstrings)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < *words)
	{
		while (s[i] == c)
			i++;
		pstrings[j] = single_word(&s[i], c);
		j++;
		while (s[i] != c)
		{
			i++;
			if (s[i] == '\0')
				break ;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**pstrings;
	int		words;

	if (!s)
		return ((void *)0);
	words = count_words(s, c);
	pstrings = malloc((sizeof(char *) * words) + sizeof(void *));
	if (pstrings == 0)
		return ((void *)0);
	write_words(s, c, &words, pstrings);
	pstrings[words] = (void *)0;
	return (pstrings);
}
