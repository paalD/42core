/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:25:15 by dpaal             #+#    #+#             */
/*   Updated: 2021/09/24 10:09:55 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

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
