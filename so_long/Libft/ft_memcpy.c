/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:55:10 by dpaal             #+#    #+#             */
/*   Updated: 2021/09/20 14:02:01 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
