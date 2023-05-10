/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:36:42 by dpaal             #+#    #+#             */
/*   Updated: 2021/09/20 13:58:35 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	*forward(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)dest = *(char *)src;
		dest++;
		src++;
		i++;
	}
	return (dest - n);
}

static void	*backward(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	dest += n - 1;
	src += n - 1;
	while (i < n)
	{
		*(char *)dest = *(char *)src;
		dest--;
		src--;
		i++;
	}
	return (dest + 1);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!src && !dest)
		return (NULL);
	if (src < dest)
		return (backward(dest, src, n));
	else
		return (forward(dest, src, n));
}
