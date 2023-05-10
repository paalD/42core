/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:33:54 by dpaal             #+#    #+#             */
/*   Updated: 2022/05/22 13:05:22 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0' && i < size)
		i++;
	while (src[j] != '\0' && i + j + 1 < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i < size)
		dest[i + j] = '\0';
	while (src[j] != '\0')
		j++;
	return (i + j);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	res;

	res = 0;
	while (res < dstsize - 1 && src[res] != '\0' && dstsize != 0)
	{
		dst[res] = src[res];
		res++;
	}
	if (dstsize != 0)
		dst[res] = '\0';
	while (src[res] != '\0')
		res++;
	return (res);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	char	*set;
	size_t	i;

	ptr = malloc(nmemb * size);
	set = ptr;
	if (ptr == 0)
		return (0);
	i = 0;
	while (i < (nmemb * size))
	{
		set[i] = '\0';
		i++;
	}
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*temp;

	if (!s1 || !s2)
		return ((void *)0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	temp = ft_calloc(sizeof(char), i + j + 1);
	if (!temp)
		return ((void *)0);
	ft_strlcpy(temp, (char *)s1, i + 1);
	ft_strlcat(temp, (char *)s2, i + j + 1);
	free(s1);
	return (temp);
}
