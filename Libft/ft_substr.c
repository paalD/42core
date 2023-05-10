/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:05:28 by dpaal             #+#    #+#             */
/*   Updated: 2021/09/23 16:41:15 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup("\0"));
	while (s[i] != '\0')
		i++;
	if (len > (i - start))
		len = i - start;
	str = malloc(len + 1);
	if (!str)
		return (0);
	str = ft_memcpy(str, s + start, len);
	str[len] = '\0';
	return (str);
}
