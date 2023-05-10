/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 22:53:05 by dpaal             #+#    #+#             */
/*   Updated: 2021/09/23 11:58:23 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memchr(const void *ptr, int c, size_t num)
{
	size_t	i;
	char	*tmp;

	i = 0;
	c = (char)c;
	tmp = (char *)ptr;
	while (i < num)
	{
		if (*tmp == c)
			return (tmp);
		tmp++;
		i++;
	}
	return (0);
}
