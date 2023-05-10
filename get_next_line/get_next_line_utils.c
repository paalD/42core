/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:10:14 by dpaal             #+#    #+#             */
/*   Updated: 2021/11/08 13:30:51 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char const	*src_tmp;
	char		*dest_tmp;

	src_tmp = (char *)src;
	dest_tmp = (char *)dest;
	if (!dest && !src)
		return (NULL);
	while (n)
	{
		*dest_tmp = *src_tmp;
		src_tmp++;
		dest_tmp++;
		n--;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	ft_memcpy(str, s1, ft_strlen(s1));
	ft_memcpy(str + ft_strlen(s1), s2, ft_strlen(s2));
	str [len] = '\0';
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	char	*ret;
	int		i;

	i = 0;
	c = (char)c;
	ret = (char *)str;
	while (str[i] != '\0' && str[i] != c)
	{
		i++;
		ret++;
	}
	if (str[i] == c)
		return (ret);
	else
		return (0);
}

char	*ft_strdup(const char *str)
{
	char	*dup;

	dup = malloc(ft_strlen(str) + 1);
	if (!dup)
		return (0);
	ft_memcpy(dup, str, ft_strlen(str) + 1);
	return (dup);
}
