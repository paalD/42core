/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 12:37:30 by dpaal             #+#    #+#             */
/*   Updated: 2021/09/20 16:14:38 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;
	size_t			size;

	if (!s)
		return (0);
	i = 0;
	size = ft_strlen(s);
	res = malloc((size + 1) * sizeof(char));
	if (!res)
		return (0);
	while (i < size)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[size] = '\0';
	return (res);
}
