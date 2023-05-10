/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 14:26:16 by dpaal             #+#    #+#             */
/*   Updated: 2021/09/24 10:47:29 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
