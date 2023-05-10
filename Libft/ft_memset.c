/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 13:54:40 by dpaal             #+#    #+#             */
/*   Updated: 2021/06/24 15:27:15 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t	i;
	char	*changer;

	changer = ptr;
	i = 0;
	while (i < num)
	{
		*changer = value;
		changer++;
		i++;
	}
	return (ptr);
}
