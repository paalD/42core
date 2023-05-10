/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:16:15 by dpaal             #+#    #+#             */
/*   Updated: 2022/04/08 11:41:08 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	calc_count(int n)
{
	int	res;
	int	i;

	res = 0;
	if (n == 0)
		res = 1;
	i = n;
	while (i != 0)
	{
		i = i / 10;
		res++;
	}
	return (res);
}

static char	*calc_pos(int count, int n, char *str)
{
	int	i;

	i = 0;
	while (i < count)
	{
		str[count - i - 1] = n % 10 + 48;
		n = n / 10;
		i++;
	}
	str[count] = '\0';
	return (str);
}

static char	*calc_neg(int count, int n, char *str)
{
	int	i;

	i = 1;
	while (i < count + 1)
	{
		str[count - i + 1] = n % 10 * (-1) + 48;
		n = n / 10;
		i++;
	}
	str[count + 1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		count;
	char	*str;

	count = calc_count(n);
	if (n >= 0)
	{
		str = malloc ((count + 1) * sizeof(char));
		if (!str)
			return (0);
		str = calc_pos(count, n, str);
	}
	else
	{
		str = malloc ((count + 2) * sizeof(char));
		if (!str)
			return (0);
		str[0] = '-';
		str = calc_neg(count, n, str);
	}
	return (str);
}
