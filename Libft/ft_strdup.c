/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:47:48 by dpaal             #+#    #+#             */
/*   Updated: 2021/09/20 14:08:44 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dup;

	dup = malloc(ft_strlen(str) + 1);
	if (!dup)
		return (0);
	ft_memcpy(dup, str, ft_strlen(str) + 1);
	return (dup);
	free(dup);
}
