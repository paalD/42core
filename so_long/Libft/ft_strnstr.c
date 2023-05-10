/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:10:11 by dpaal             #+#    #+#             */
/*   Updated: 2021/09/23 15:08:03 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *lil, size_t len)
{
	size_t	i;
	size_t	l_len;

	l_len = ft_strlen(lil);
	i = 0;
	if (lil[0] == '\0')
		return ((char *)big);
	while (i < len && big[i])
	{
		if ((len - i) < l_len)
			return (0);
		if (big[i] == lil[0])
		{
			if (!(ft_memcmp(&big[i], lil, l_len)))
				return ((char *) &big[i]);
		}
		i++;
	}
	return (0);
}
