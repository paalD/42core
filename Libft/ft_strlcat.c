/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:44:14 by dpaal             #+#    #+#             */
/*   Updated: 2021/06/29 11:40:47 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	res;
	size_t	i;

	res = 0;
	i = 0;
	while (dst[res] != '\0')
	{
		if (res == dstsize)
			break ;
		res++;
	}
	while (src[i] != '\0' && res < dstsize - 1 && dstsize != 0 && res < dstsize)
	{
		dst[res] = src[i];
		res++;
		i++;
	}
	if (dstsize != 0 && res < dstsize)
		dst[res] = '\0';
	while (src[i] != '\0')
	{
		res++;
		i++;
	}
	return (res);
}
