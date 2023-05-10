/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:37:09 by dpaal             #+#    #+#             */
/*   Updated: 2021/06/24 15:43:08 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_bzero(void *ptr, size_t num)
{
	size_t	i;
	char	*changer;

	changer = ptr;
	i = 0;
	while (i < num)
	{
		*changer = '\0';
		changer++;
		i++;
	}
}
