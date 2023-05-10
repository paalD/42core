/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 23:12:37 by dpaal             #+#    #+#             */
/*   Updated: 2021/06/25 00:25:03 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	size_t	i;
	char	*tmp1;
	char	*tmp2;

	i = 0;
	tmp1 = (char *)ptr1;
	tmp2 = (char *)ptr2;
	if (num == 0)
		return (0);
	while (i < num && tmp1[i] == tmp2[i])
		i++;
	if (i == num)
		return (0);
	return ((unsigned char)tmp1[i] - (unsigned char)tmp2[i]);
}
